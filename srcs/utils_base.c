/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:49:28 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 18:58:40 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *game)
{
	if (!check_valid_chars(game))
		return (ft_printf("Erro:\ncaracter inválido no mapa.\n"), 0);
	if (!check_rectangular(game))
		return (ft_printf("Erro:\nmapa não é retangular.\n"), 0);
	if (!check_walls(game))
		return (ft_printf("Erro:\nmapa não está cercado por paredes.\n"), 0);
	if (!check_contents(game))
		return (ft_printf("Erro:\nmapa deve ter 1P, 1E e pelo menos 1C.\n"), 0);
	if (!check_valid_path(game))
		return (ft_printf("Erro:\nnão há caminho válido no mapa.\n"), 0);
	return (1);
}

int	handle_exit(t_vars *vars, char tile)
{
	if (tile == 'E')
	{
		if (vars->game.collected == vars->game.collectibles)
		{
			ft_printf("🎉 Você venceu com %d movimentos!\n", vars->game.moves);
			exit_game(vars);
		}
		else
		{
			ft_printf("🚫 Ainda faltam %d coletáveis!\n",
				vars->game.collectibles - vars->game.collected);
			return (1);
		}
	}
	return (0);
}

void	handle_move(t_vars *vars, int new_x, int new_y)
{
	char	tile;

	if (new_x < 0 || new_x >= vars->game.width || new_y < 0
		|| new_y >= vars->game.height || vars->game.map[new_y][new_x] == '1')
		return ;
	tile = vars->game.map[new_y][new_x];
	if (tile == 'C')
	{
		vars->game.collected++;
		vars->game.map[new_y][new_x] = '0';
	}
	if (tile == 'E' && vars->game.collected == vars->game.collectibles)
	{
		ft_printf("Voce venceu com %d movimentos!\n", vars->game.moves);
		exit_game(vars);
	}
	vars->game.moves++;
	ft_printf("Movimentos: %d\n", vars->game.moves);
	vars->player_x = new_x;
	vars->player_y = new_y;
}

int	key_hook(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player_x;
	new_y = vars->player_y;
	if (keycode == UP)
		new_y--;
	else if (keycode == DOWN)
		new_y++;
	else if (keycode == LEFT)
		new_x--;
	else if (keycode == RIGHT)
		new_x++;
	else if (keycode == 65307)
		exit_game(vars);
	else
		return (0);
	handle_move(vars, new_x, new_y);
	mlx_clear_window(vars->mlx, vars->win);
	paint_map(vars->game.map, vars);
	return (0);
}

// Função para criar uma cópia do mapa (para não modificar o original)
char	**copy_map(t_game *game)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < game->height)
	{
		copy[y] = ft_strdup(game->map[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			return (NULL);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}
