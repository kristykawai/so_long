/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:36:02 by kchan             #+#    #+#             */
/*   Updated: 2024/01/09 15:35:59 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdlib.h>
# include <limits.h>
# include <math.h> 
# include <OpenGL/gl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct s_game
{
	void		*mlx;		// pointer to the mlx
	void		*window;	// pointer to the window
	t_vector	wndw_size;	// window size

	t_tile		**tilemap;	// 2D tile table

	t_player	player;		// struct with info about the player: current tile, animation frames, counter and images

	int		og_collects;	// original collectable to be able to reset
	int		collects;	// current value, reducing one each time you pick up one
	int		moves;		// moves counter, adding one each time you spend a turn
	
	// sprites/images
	t_vector	img_size;
	t_wall_img	wall_imgs;	// struct with all nine wall images
	t_collect_img	collects_imgs;	// struct with info about the collectables animation.
	t_enemy_img	enemy_imgs;	// struct with the animation info of the two type of enemies
	void		*door_open_img;	// images for the door
	void		*door_close_img;
	t_effect	effect;		// struct with the particle effect animation
	void		*red_panel;	// panels
	void		*white_panel;

}	t_game;

#endif