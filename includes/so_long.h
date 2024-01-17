/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:36:02 by kchan             #+#    #+#             */
/*   Updated: 2024/01/17 17:11:03 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*header*/
# include <stdlib.h>
# include <limits.h>
# include <math.h> 
# include <OpenGL/gl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

/*define*/
# define MAP_WIDTH	6400 
# define MAP_HEIGHT	6400
# define PIXEL_WIDTH  64
# define PIXEL_HEIGHT 64

# define CHAR_WALL			'W'
# define CHAR_EXIT			'E'
# define CHAR_PLAYER		'P'
# define CHAR_COLLLECT		'C'
# define CHAR_FLOOR			'0'

# define XMP_PLAYER			"./assets/xmp/collectable.xmp"
# define XMP_PLAYER			"./assets/xmp/exit_close.xmp"
# define XMP_PLAYER			"./assets/xmp/exit_open.xmp"
# define XMP_PLAYER			"./assets/xmp/floor.xmp"
# define XMP_PLAYER			"./assets/xmp/player.xmp"
# define XMP_PLAYER			"./assets/xmp/wall.xmp"

# define WAV_MUSIC			"./assets/music/346_Town.wav"


/* struct */
typedef struct s_multi
{
	mlx_image_t	*image;
	int			x;
	int			y;
}				t_multi;

typedef struct s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
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
	mlx_t		*mlx;
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
void	ft_free_map_repo(char **target);
void	ft_free_map_fill(char **map, int cols);

/*initial_layer*/
void	check_argument(int ac, char **av, t_game *game)

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