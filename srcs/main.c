/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:36:52 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 14:56:49 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_vars *vars, char *filename)
{
	vars->game.map = read_map(filename, &vars->game.height, &vars->game.width);
	if (!vars->game.map || !validate_map(&vars->game))
		return (free_map(vars->game.map), 0);
	find_the_player(vars);
	vars->game.collectibles = count_collectibles(&vars->game);
	return (1);
}

int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (free_map(vars->game.map), 0);
	vars->win = mlx_new_window(vars->mlx, vars->game.width * TILE, 
		vars->game.height * TILE, "JESUS LOVES YOU!");
	if (!vars->win)
		return (cleanup(vars), 0);
	return (1);
}

int	load_textures(t_vars *vars)
{
	int	width;
	int	height;

	vars->player_image = mlx_xpm_file_to_image(vars->mlx, "sprites/jesus.xpm", &width, &height);
	vars->rock = mlx_xpm_file_to_image(vars->mlx, "sprites/rock.xpm", &width, &height);
	vars->heart = mlx_xpm_file_to_image(vars->mlx, "sprites/coracao.xpm", &width, &height);
	vars->waves = mlx_xpm_file_to_image(vars->mlx, "sprites/waves.xpm", &width, &height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm", &width, &height);
	if (!vars->player_image || !vars->rock || !vars->heart || !vars->waves || !vars->exit)
		return (0);
	return (1);
}

void	start_game(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0L, exit_game, vars);
	paint_map(vars->game.map, vars);
}

int main(int argc, char *argv[])
{
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(t_vars));
	if (argc != 2)
		return (printf("Uso: %s <mapa.ber>\n", argv[0]), 1);
	if (!validate_map_file(argv[1]))
		return (1);
	if (!init_game(&vars, argv[1]))
		return (1);
    vars.game.moves = 0; 
	if (!init_mlx(&vars))
		return (cleanup(&vars), 1);
	if (!load_textures(&vars))
		return (printf("Erro: Texturas\n"), cleanup(&vars), 1);
	start_game(&vars);
	mlx_loop(vars.mlx);
	cleanup(&vars);
	return (0);
}
