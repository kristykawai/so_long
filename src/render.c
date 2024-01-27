/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:49:31 by kawai             #+#    #+#             */
/*   Updated: 2024/01/27 16:26:26 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_texture(t_game *game)
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
				ft_mlx_image_to_window(game->mlx, game->img.collect[game->count].image, x, y);
			else if (game->map.repo[y][x] == CHAR_EXIT)
				ft_mlx_image_to_window(game->mlx, game->img.exit_close.image, x, y);
			else if (game->map.repo[y][x] == CHAR_PLAYER)
				ft_mlx_image_to_window(game->mlx, game->img.player.image, x, y);
			x++;
		}
		y++;
	}
}

int	update_game(void	*param)
{
	t_game *game;

	game = (t_game *)param;
	// (void)param;
	// win_condition();
	// collect_condition();
	mlx_clear_window(game->mlx, game->mlx_win);
	place_floor_with_texture(game);
	update_texture(game);
	// draw_wall(g_game->wall_sprite);
	// draw_floor(g_game->floor_sprite);
	// draw_exit(g_game->exit_sprite);
	// draw_collectible(g_game->collect_sprite);
	// draw_character(g_game->character_sprite);
	return (0);
}

