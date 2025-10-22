/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:39:20 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 17:14:14 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->game.map)
		free_map(vars->game.map);
	if (vars->mlx)
	{
		if (vars->player_image)
			mlx_destroy_image(vars->mlx, vars->player_image);
		if (vars->rock)
			mlx_destroy_image(vars->mlx, vars->rock);
		if (vars->heart)
			mlx_destroy_image(vars->mlx, vars->heart);
		if (vars->waves)
			mlx_destroy_image(vars->mlx, vars->waves);
		if (vars->exit)
			mlx_destroy_image(vars->mlx, vars->exit);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

int	exit_game(t_vars *vars)
{
	if (vars)
	{
		cleanup(vars);
	}
	exit(0);
	return (0);
}
