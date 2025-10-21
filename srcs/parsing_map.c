/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:42:17 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/21 21:28:31 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char    **map_add_line(char **map, char *line, int *count)
{
    char **tmp;
    int     i;

    tmp = malloc(sizeof(char *) * (*count + 2));
    if (!tmp)
        return (NULL);
    
    i = 0;
    while( i < *count)
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

char	**read_map(const char *filename, int *height, int *width)
{
	int		fd;
	char	*line;
	char	**map;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || !(line = get_next_line(fd)))
		return (NULL);
	*width = ft_strlen(line) - 1;
	map = malloc(sizeof(char *) * 2);
	if (!map)
		return (free(line), NULL);
	count = 0;
	map[count++] = ft_strtrim(line, "\n");
	map[count] = NULL;
	free(line);
	while ((line = get_next_line(fd)))
		map = map_add_line(map, line, &count);
	close(fd);
	*height = count;
	return (map);
}


void    paint_map(char **arr, t_vars *vars)
{
    int x;
    int y;
    
    y = 0;
    while(y < vars->game.height)
    {
        x = 0;
        while(x < vars->game.width)
        {
            if(arr[y][x] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->rock, x*TILE, y*TILE);
            else if(arr[y][x] == '0')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->waves, x*TILE, y*TILE);
            else if(arr[y][x] == 'C')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->heart, x*TILE, y*TILE);
            else if(arr[y][x] == 'E')
                    mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x*TILE, y*TILE);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win,  vars->player_image, 
                            vars->player_x*TILE, vars->player_y*TILE);   
}
