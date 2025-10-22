/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:46:54 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 18:23:04 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_position(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	count_collectibles(t_game *game)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	find_the_player(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->game.height)
	{
		x = 0;
		while (x < vars->game.width)
		{
			if (vars->game.map[y][x] == 'P')
			{
				vars->player_x = x;
				vars->player_y = y;
				vars->game.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	check_file(const char *filename)
{
	int		fd;
	char	buffer[1];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nArquivo não encontrado\n", 30);
		exit(EXIT_FAILURE);
	}
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == 0)
	{
		close(fd);
		write(2, "Error\nArquivo vazio\n", 21);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
