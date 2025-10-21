/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:35:28 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/21 21:44:39 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_game *game)
{
	int	y;
	size_t	first_line_len;

	if (game->height == 0 || game->width == 0)
		return (0);
	first_line_len = ft_strlen(game->map[0]);
	y = 1;
	while (y < game->height)
	{
		if (ft_strlen(game->map[y]) != first_line_len)
			return (0);
		y++;
	}
	return (1);
}

int check_valid_chars(t_game *game)
{
    int y;
    int x;
    char c;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while(x < game->width)
        {
            c = game->map[y][x];
            if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int check_walls(t_game *game)
{
    int y;

    // Primeira e última linha (topo e fundo)
    y = 0;
    while (y < game->width)
    {
        if (game->map[0][y] != '1' || game->map[game->height - 1][y] != '1')
            return (0);
        y++;
    }

    // Primeira e última coluna (laterais)
    y = 0;
    while (y < game->height)
    {
        if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
            return (0);
        y++;
    }

    return (1);
}

int check_contents(t_game *game)
{
    int y;
    int x;
    int count_p;
    int count_e;
    int count_c;

    y = -1;
    count_p = 0;
    count_e = 0;
    count_c = 0;
    while(++y < game->height)
    {
        x = -1;
        while(++x < game->width)
        {
            if(game->map[y][x] == 'P')
                count_p++;
            else if(game->map[y][x] == 'E')
                count_e++;
            else if(game->map[y][x] == 'C')
                count_c++;
        }
    }
   return (count_p == 1 && count_e == 1 && count_c >= 1);
}

int	check_valid_path(t_game *game)
{
	char	**map_copy;
	int		start_x;
	int		start_y;
	int		result;

	if (!find_player_position(game, &start_x, &start_y))
		return (0);
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, start_x, start_y, game->width, game->height);
	result = check_flood_result(map_copy, game->width, game->height);
	free_map(map_copy);
	return (result);
}
