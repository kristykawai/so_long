/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:10:21 by kawai             #+#    #+#             */
/*   Updated: 2024/02/01 16:29:46 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	display_move_mlx_win(t_game *game)
{
	char	*temp;

	temp = ft_itoa(game->position.move);
	mlx_string_put(game->mlx, game->mlx_win, 4, 32, 0x00FFFFFF, "Steps: ");
	mlx_string_put(game->mlx, game->mlx_win, 68, 32, 0x00FFFFFF, temp);
	free(temp);
}

void	place_texture(t_game *game)
{
	place_xpm_to_img(game, &game->img.floor, XPM_FLOOR);
	place_xpm_to_img(game, &game->img.wall, XPM_WALL);
	place_floor_with_texture(game);
	place_layer_with_texture(game);
	display_move_mlx_win(game);
}
