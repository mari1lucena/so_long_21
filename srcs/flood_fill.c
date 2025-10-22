/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:44:48 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 18:43:43 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_size size)
{
	if (x < 0 || x >= size.width || y < 0 || y >= size.height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, size);
	flood_fill(map, x - 1, y, size);
	flood_fill(map, x, y + 1, size);
	flood_fill(map, x, y - 1, size);
}

int	check_flood_result(char **map, t_size size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.height)
	{
		x = 0;
		while (x < size.width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
