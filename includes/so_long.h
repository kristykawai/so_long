/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:36:02 by kchan             #+#    #+#             */
/*   Updated: 2024/01/27 20:39:20 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*header*/
# include <stdlib.h>
# include <limits.h>
# include <math.h> 
# include <OpenGL/gl.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../miniaudio/miniaudio.h"

/*define*/
# define MAP_WIDTH	6400 
# define MAP_HEIGHT	6400
# define TILE_WIDTH  64
# define TILE_HEIGHT 64

# define CHAR_MAP			"01PEC"
# define CHAR_WALL			'1'
# define CHAR_EXIT			'E'
# define CHAR_PLAYER		'P'
# define CHAR_COLLLECT		'C'
# define CHAR_FLOOR			'0'

# define XPM_COLLECTABLE	"./assets/xpm/collectable.xpm"
# define XPM_EXIT_CLOSE		"./assets/xpm/exit_close.xpm"
# define XPM_EXIT_OPEN		"./assets/xpm/exit_open.xpm"
# define XPM_FLOOR			"./assets/xpm/floor.xpm"
# define XPM_PLAYER			"./assets/xpm/player.xpm"
# define XPM_WALL			"./assets/xpm/wall.xpm"

/* miniaudio */
# define MINIAUDIO_IMPLEMENTATION
/* audio path */
# define WAV_MUSIC			"./assets/music/346_Town.wav"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
} eventcode;

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define ESC_KEY 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

/* struct */
typedef struct s_multi
{
	char		*image;
	int			x;
	int			y;
}				t_multi;

typedef struct s_img
{
	char		*floor;
	char		*wall;
	t_multi		exit_open;
	t_multi		exit_close;
	t_multi		player;
	t_multi		collect[100];
}				t_img;


typedef struct s_map
{
	char	**repo;
	char	**fill;
	int		columns;
	int		rows;
	int		collects;
	int		player;
	int		exits;
	int		walls;
	int		floor;
}				t_map;

typedef struct s_position
{
	int					x;
	int					y;
	unsigned int		move;
}				t_position;


/* game */
typedef struct s_game
{	
	void			*mlx;
	void			*mlx_win;
	int				fd;
	t_img			img;
	t_map			map;
	t_position		position;
	int				count;
	int				pixel;
	int				finish_game;
}				t_game;

/* ft_error */
void	ft_error_general(char *msg);
void	ft_error_and_free_map(char *msg, t_game *game);
void	ft_free_map_fill(char **matrix, int cols_to_free);
void	ft_free_map_repo(char **matrix);

/* floodfill */
void	ft_mcpy_fill(t_game *game);
void	flood_fill_recursive(t_game *game, int x, int y, char replacement);
void	check_flood_fill_remain(t_game *game);
void	flood_fill_check(t_game	*game, char replacement);

/*parser_input*/
void	check_argument(int ac, char **av);
void	is_emtpy_file(char *line);
int		check_row_len(t_game *game);
void	check_valid_map_size(t_game *game);

/*init_layer*/
int		check_valid_character(const char *s, int c);
void	count_map_entities(char c, t_game *game, unsigned int x, unsigned int y);
void	check_required_entities(t_game *game);
void	check_enclosed_wall(t_game *game, unsigned int x, unsigned int y);
void	init_layer(t_game *game);

/*init_game*/
void	init_value(t_game *game);
void	set_player_position(t_multi *info, t_position *position);
void	init_mlx(t_game *game);

/*init_map*/
void	map_2d_malloc(t_game *game);
void	init_map(t_game *game);

/*init_map_texture*/
void	place_texture(t_game *game);
void	place_floor_with_texture(t_game *game);
void	place_layer_with_texture(t_game *game);

/*init_image*/
void	init_player(t_game *game, int x, int y);
void	init_collect(t_game *game, int x, int y, int	*count);
void	init_exit(t_game *game, int x, int y);

/*utility*/
int		ft_readline(char *str);
void	printCharMatrix(char** matrix, int rows, int cols);
void	place_xpm_to_img(t_game *game, char **img_path, char *xpm_path);
void	ft_mlx_image_to_window(t_game *game, char *mlx_img, int x, int y);
void	mlx_delete_image(void *mlx, char *img);

/*event.c*/
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
int		handle_keypress(int keycode, t_game *game);

/*delete image*/
void	delete_item(t_game *game, int x, int y);
void	delete_collectible(t_game *game);
void	delete_player(t_game *game);
void	delete_floor(t_game *game);
void	delete_all_image(t_game *game);

/*exit*/
int		exit_game(void);
int		exit_win_game(t_game *game);

/*render*/
void	update_texture(t_game *game);
int		update_game(void	*param);

/*main*/
// void	clean_up(t_game *game);
#endif