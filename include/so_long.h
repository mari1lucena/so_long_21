/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:52:05 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 18:57:51 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 900
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define TILE 64

//guarda mapa e logica do jogo
typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		moves;
}	t_game;

//guarda mlx e sprites
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	void	*player_image;
	void	*rock;
	void	*heart;
	void	*waves;
	void	*exit;
	t_game	game;
}				t_vars;

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

//check.map
int		check_rectangular(t_game *game);
int		check_valid_chars(t_game *game);
int		check_walls(t_game *game);
int		check_contents(t_game *game);
int		check_valid_path(t_game *game);

//flood_fill.c
void	flood_fill(char **map, int x, int y, t_size size);
int		check_flood_result(char **map, t_size size);

//free.c
void	free_map(char **map);
void	cleanup(t_vars *vars);
int		exit_game(t_vars *vars);

//inicialization.c
int		init_game(t_vars *vars, char *filename);
int		init_mlx(t_vars *vars);
int		load_textures(t_vars *vars);
void	start_game(t_vars *vars);

//parsing_map.c
char	**copy_map(t_game *game);
char	**map_add_line(char **map, char *line, int *count);
char	**read_map(const char *f, int *h, int *w);
void	paint_map(char **arr, t_vars *vars);
void	draw_map2(char **arr, t_vars *vars);
char	**read_map_rest(int fd, char **map, int *count);

//utils_base.c
int		validate_map(t_game *game);
int		handle_exit(t_vars *vars, char tile);
void	handle_move(t_vars *vars, int new_x, int new_y);
int		key_hook(int keycode, t_vars *vars);

//utils.c
int		find_player_position(t_game *game, int *x, int *y);
int		count_collectibles(t_game *game);
void	find_the_player(t_vars *vars);

void	check_file(const char *filename);

//check_fd
int		check_file_validity(char *filename);
int		validate_map_file(char *filename);
int		check_file_extension(char *filename, char *extension);
int		error_message(char *message);

#endif