/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:28:27 by kawai             #+#    #+#             */
/*   Updated: 2024/01/28 23:06:08 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_player(t_game *game)
{
	if (!game->img.player.image)
		return ;
	mlx_delete_image(game->mlx, game->img.player.image);
}

void	delete_floor(t_game *game)
{
	if (!game->img.floor)
		return ;
	mlx_delete_image(game->mlx, game->img.floor);
}

void	delete_item(t_game *game, int x, int y)
{
	int		i;
	int		collect_x;
	int		collect_y;

	collect_x = 0;
	collect_y = 0;
	game->map.repo[y][x] = '0';
	i = 0;
	while (i < game->map.collects && game->count_delete < game->map.collects)
	{
		if (game->count_delete >= game->map.collects)
			break ;
		collect_x = game->img.collect[i].x;
		collect_y = game->img.collect[i].y;
		if (collect_x == x && collect_y == y)
		{
			mlx_delete_image(game->mlx, game->img.collect[i].image);
			game->count_delete++;
		}
		i++;
	}
}

void	delete_collectible(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.repo[y][x] == CHAR_COLLLECT)
				delete_item(game, x, y);
			x++;
		}
		y++;
	}
	if (game->count_delete != game->map.collects)
		ft_error_and_free_map("could not delete all floor image", game);
}

void	delete_all_image(t_game *game)
{
	delete_player(game);
	delete_floor(game);
	delete_collectible(game);
	mlx_delete_image(game->mlx, game->img.exit_open.image);
	mlx_delete_image(game->mlx, game->img.exit_close.image);
	mlx_delete_image(game->mlx, game->img.wall);
}
