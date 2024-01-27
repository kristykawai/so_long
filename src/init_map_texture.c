/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:10:21 by kawai             #+#    #+#             */
/*   Updated: 2024/01/27 20:32:50 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_texture(t_game *game)
{
	place_xpm_to_img(game, &game->img.floor, XPM_FLOOR);
	place_xpm_to_img(game, &game->img.wall, XPM_WALL);
	place_floor_with_texture(game);
	place_layer_with_texture(game);
}

void	place_floor_with_texture(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			mlx_put_image_to_window (game->mlx, game->mlx_win,
			game->img.floor, game->pixel * x, game->pixel * y);
			x++;
		}
		y++;
	}
}

void	place_layer_with_texture(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.repo[y][x] == CHAR_WALL)
				ft_mlx_image_to_window(game->mlx, game->img.wall, x, y);
			else if (game->map.repo[y][x] == CHAR_COLLLECT)
				init_collect(game, x, y, &game->count);
			else if (game->map.repo[y][x] == CHAR_EXIT)
				init_exit(game, x, y);
			else if (game->map.repo[y][x] == CHAR_PLAYER)
				init_player(game, x, y);
			x++;
		}
		y++;
	}
	game->count = 0;
}
