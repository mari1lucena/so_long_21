/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:49:28 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/21 21:44:35 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_map(t_game *game)
{
    
    if(!check_valid_chars(game))
        return (printf("Erro: caracter inválido no mapa.\n"), 0);
    if (!check_rectangular(game))
        return (printf("Erro: mapa não é retangular.\n"), 0);
    if (!check_walls(game))
        return (printf("Erro: mapa não está cercado por paredes.\n"), 0);
    if (!check_contents(game))
        return (printf("Erro: mapa deve ter 1 P, 1 E e pelo menos 1 C.\n"), 0);
      if (!check_valid_path(game))
        return (printf("Erro: não há caminho válido no mapa.\n"), 0);
    return (1);
}

int	handle_exit(t_vars *vars, char tile)
{
	if (tile == 'E')
	{
		if (vars->game.collected == vars->game.collectibles)
		{
			printf("🎉 Você venceu com %d movimentos!\n", vars->game.moves);
			exit_game(vars);
		}
		else
		{
			printf("🚫 Ainda faltam %d coletáveis!\n", 
				vars->game.collectibles - vars->game.collected);
			return (1);
		}
	}
	return (0);
}

void	handle_move(t_vars *vars, int new_x, int new_y)
{
	char	tile;

	if (new_x < 0 || new_x >= vars->game.width || new_y < 0 || new_y >= vars->game.height
		|| vars->game.map[new_y][new_x] == '1')
		return;
	tile = vars->game.map[new_y][new_x];
	if (tile == 'C')
	{
		vars->game.collected++;
		vars->game.map[new_y][new_x] = '0';
	}
    if (tile == 'E' && vars->game.collected == vars->game.collectibles)
    {
        printf("Voce venceu com %d movimentos!\n", vars->game.moves);
        exit_game(vars);
    }
	vars->game.moves++;
	printf("Movimentos: %d\n", vars->game.moves);
	vars->player_x = new_x;
	vars->player_y = new_y;
}

int key_hook(int keycode, t_vars *vars)
{
    int new_x = vars->player_x;
    int new_y = vars->player_y;

    if (keycode == UP)
        new_y--;
    else if (keycode == DOWN)
        new_y++;
    else if (keycode == LEFT)
        new_x--;
    else if (keycode == RIGHT)
        new_x++;
    else if (keycode == 65307) // ESC no Linux
		exit_game(vars);
    else
        return (0);

    handle_move(vars, new_x, new_y);

    mlx_clear_window(vars->mlx, vars->win);
    paint_map(vars->game.map, vars);
    return (0);
}
