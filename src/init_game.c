/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:09:54 by kawai             #+#    #+#             */
/*   Updated: 2024/01/19 12:34:23 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_value(t_game *game)
{
	game->position.x = 0; //start position x
	game->position.y = 0; //start position y
	game->position.move = 0;
	game->map.columns = 0; //x
	game->map.rows = 0; //y
	game->map.collects = 0;
	game->map.exits = 0;
	game->map.player = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.repo = NULL;
	game->count = 0;
	game->finish_game = 0;
	game->map.fill = NULL;
}

void	set_player_position(t_multi *info, t_position *position)
{
	info->x = position->x;
	info->y = position->y;
	ft_printf("Player position set to (%d,%d)\n", position->x, position->y);
}

void	init_mlx(t_game *game)
{
	// mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_error_and_free_map("Failed to initialize MLX.", game);
		exit(1);
	}
	game->mlx_win = mlx_new_window(game->mlx, TILE_WIDTH * game->map.columns, \
		TILE_HEIGHT * game->map.rows, "so long");
}
