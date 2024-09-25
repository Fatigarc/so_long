/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:04:14 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 06:14:41 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft2/libft.h"
# include "./mlx_linux1/mlx.h"

# define IMG_HEIGHT	72
# define IMG_WIDTH  72

# ifndef keys 
#  define KEY_ESC 65307
#  define KEY_UP 65362  
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
#  define KEY_LEFT 65361
#  define KEY_A 97
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
# endif

# ifndef Messages
#  define WINS "\n WELL DONE! YOU MAKE A DOG HAPPY\n\n"
#  define LOSE "\n UNBELIEVABLE...YOU HAVE DISSAPOINTED A DOG! \n\n"
# endif

# ifndef Textures
#  define SNACK "./textures/obstacule/snack.xpm"
#  define BORDER_COLLIE "./textures/player/border_collie.xpm"
#  define WALL "./textures/wall/lemon_tree.xpm"
#  define BACKGROUND "./textures/background/background.xpm"
#  define EXIT_HOUSE "./textures/exit_house/dog_house.xpm"
# endif

# ifndef MAX_LINE_LENGTH
#  define MAX_LINE_LENGTH 150
# endif

typedef struct s_image
{
	void	*xpm_ptr;
	void	*lemon_tree_xpm;
	void	*heartsnack_xpm;
	void	*backg_xpm;
	void	*dog_xpm;
	void	*exit_house_xpm;
}			t_image;

typedef struct s_player
{
	int		posx;
	int		posy;
	int		steps;
}			t_player;

typedef struct s_map
{
	size_t		row_len;
	size_t		column_len;
	t_player	main_char;
	char		**map_readed;
	char		**map_dup;
}			t_map;

typedef struct s_collec
{
	int		total_collec;
	int		items;
}			t_collec;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	t_map		*map_ref;
	t_player	player;
	t_collec	*collec;
	t_image		*textures;
}			t_game;

//player_move.c
void	check_end_game(t_game *game, int x, int y);
void	move_up(t_game *game, t_map *map);
void	move_down(t_game *game, t_map *map);
void	move_right(t_game *game, t_map *map);
void	move_left(t_game *game, t_map *map);

//hook.c
int		destroy_win_in_hook(t_game *game);
int		key_press_hook(int keycode, t_game *game);

//valid_map.c
void	flood_fill(t_map **map, int y, int x, int initial);
void	verify_valid_path(t_map **map, t_game **game);
void	verify_wall(t_map **map, t_game **game);
void	verify_extension(const char *argv, t_game **game, t_map **map);
void	verify_object(t_game **game, t_map **map);

//position.c
void	start_flood_fill(t_map **map);
void	count_map_row(t_map **map, int fd, const char *file_name, \
t_game **game);
void	check_number_column(char *line, int *fd, t_game **game, \
t_map **map);
void	count_map_column(t_map **map, int fd, const char *file_name, \
t_game **game);

//message.c
void	error_creating_img(t_game **game, t_map **map);
void	error_resolution(t_game *game);
void	error_msg(char	*str, t_game **game, t_map **map);

//init.c
void	close_game(t_game *game);
void	init_window(t_game *game);
void	init_images(t_game *game, t_map **map);

//free.c
void	destroy_all_img(t_game **game, t_image *image);
void	free_map_error(t_game **game, t_map **map);
void	free_dup_map(t_map **map);
void	free_map(t_game *game);
void	free_empty_lines(char **map_dup, int lines);

//parsing.c
void	duplicate_map(t_map **map);
void	read_map(t_game **game, const char *file_name, t_map **map);
void	check_player_exit(int nb_p, int nb_e, t_game **game, t_map **map);
void	valid_character(t_game **game, t_map **map);
void	map_parsing(t_map **map, t_game **game);

//draw.c
void	draw_background(t_game *game);
void	draw_collect(t_game *game);
void	draw_exit(t_game *game);
void	draw_player(t_game *game);
void	draw_images(t_game *game);

//main.c
void	close_game(t_game *game);
void	start_game(t_game *game);

#endif
