/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:42:17 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 18:58:31 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_add_line(char **map, char *line, int *count)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (*count + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < *count)
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[*count] = ft_strtrim(line, "\n");
	tmp[*count + 1] = NULL;
	(*count)++;
	free(line);
	free(map);
	return (tmp);
}

char	**read_map(const char *f, int *h, int *w)
{
	int		fd;
	char	*l;
	char	**m;
	int		c;

	fd = open(f, O_RDONLY);
	if (fd < 0)
		return (NULL);
	l = get_next_line(fd);
	if (!l)
		return (NULL);
	*w = ft_strlen(l) - 1;
	m = malloc(sizeof(char *) * 2);
	if (!m)
		return (free(l), NULL);
	c = 0;
	m[c++] = ft_strtrim(l, "\n");
	m[c] = NULL;
	free(l);
	m = read_map_rest(fd, m, &c);
	close(fd);
	*h = c;
	return (m);
}

char	**read_map_rest(int fd, char **map, int *count)
{
	char	*l;

	l = get_next_line(fd);
	while (l)
	{
		map = map_add_line(map, l, count);
		l = get_next_line(fd);
	}
	return (map);
}

void	paint_map(char **arr, t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->game.height)
	{
		x = 0;
		while (x < vars->game.width)
		{
			if (arr[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->rock, x * 64, y * 64);
			else if (arr[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->waves, x * 64, y * 64);
			else if (arr[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->heart, x * 64, y * 64);
			x++;
		}
		y++;
	}
	draw_map2(arr, vars);
}

void	draw_map2(char **arr, t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->game.height)
	{
		x = 0;
		while (x < vars->game.width)
		{
			if (arr[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player_image,
		vars->player_x * TILE, vars->player_y * TILE);
}
