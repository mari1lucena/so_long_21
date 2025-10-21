/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:44:48 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/21 21:28:55 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Flood fill recursivo
void	flood_fill(char **map, int x, int y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return;
	
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, width, height);
	flood_fill(map, x - 1, y, width, height);
	flood_fill(map, x, y + 1, width, height);
	flood_fill(map, x, y - 1, width, height);
}

// Verifica se todos os coletáveis e saída são alcançáveis
int	check_flood_result(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
