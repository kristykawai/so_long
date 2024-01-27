/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:52:03 by kawai             #+#    #+#             */
/*   Updated: 2024/01/27 20:42:25 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player(t_game *game, int x, int y)
{
	place_xpm_to_img(game, &game->img.player.image, XPM_PLAYER);
	set_player_position(&game->img.player, &game->position);
	ft_mlx_image_to_window(game->mlx, game->img.player.image, x, y);
}

void	init_collect(t_game *game, int x, int y, int	*count)
{
	place_xpm_to_img(game, &game->img.collect[*count].image, XPM_COLLECTABLE);
	game->img.collect[*count].x = x;
	game->img.collect[*count].y = y;
	ft_mlx_image_to_window(game->mlx, game->img.collect[*count].image, x, y);
	(*count)++;
}

void	init_exit(t_game *game, int x, int y)
{
	place_xpm_to_img(game, &game->img.exit_close.image, XPM_EXIT_CLOSE);
	game->img.exit_close.x = x;
	game->img.exit_close.y = y;
	place_xpm_to_img(game, &game->img.exit_open.image, XPM_EXIT_OPEN);
	game->img.exit_open.x = x;
	game->img.exit_open.y = y;
	ft_mlx_image_to_window(game->mlx, game->img.exit_close.image, \
		x, y);
}
