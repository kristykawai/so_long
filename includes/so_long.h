/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:36:02 by kchan             #+#    #+#             */
/*   Updated: 2024/01/19 12:34:35 by kchan            ###   ########.fr       */
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

/*define*/
# define MAP_WIDTH	6400 
# define MAP_HEIGHT	6400
# define TILE_WIDTH  64
# define TILE_HEIGHT 64

# define CHAR_WALL			'W'
# define CHAR_EXIT			'E'
# define CHAR_PLAYER		'P'
# define CHAR_COLLLECT		'C'
# define CHAR_FLOOR			'0'

# define XMP_COLLECTABLE	"./assets/xmp/collectable.xmp"
# define XMP_EXIT_CLOSE		"./assets/xmp/exit_close.xmp"
# define XMP_EXIT_OPEN		"./assets/xmp/exit_open.xmp"
# define XMP_FLOOR			"./assets/xmp/floor.xmp"
# define XMP_PLAYER			"./assets/xmp/player.xmp"
# define XMP_WALL			"./assets/xmp/wall.xmp"

# define WAV_MUSIC			"./assets/music/346_Town.wav"


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
	t_multi		exits_open;
	t_multi		exits_close;
	t_multi		player;
	t_multi		collect[1000];

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
	void		*mlx;
	void		*mlx_win;
	int			fd;
	t_img		img;
	t_map		map;
	t_position	position;
	int			count;
	int			finish_game;
}				t_game;

/* error */
void	ft_error_general(char *msg);
void	ft_error_and_free_map(char *msg, t_game *game);
void	ft_free_map_repo(char **matrix);
void	ft_free_map_fill(char **matrix, int cols_to_free);


/*parser_input*/
void	check_argument(int ac, char **av);
void	is_emtpy_file(char *line);
int		check_map_len(t_game *game);
int		check_enclosed_wall(t_game *game);
void	check_valid_map(t_game *game);

/*init_layer*/

/*init_game*/
void	init_value(t_game *game);
void	set_player_position(t_multi *info, t_position *position);
void	init_mlx(t_game *game);

/*init_map*/
void	map_2d_malloc(t_game *game);
void	init_map(t_game *game);

/*utility*/
int		ft_readline(char *str);
void	printCharMatrix(char** matrix, int rows, int cols);

#endif

//unsure
// typedef struct	s_data 
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;