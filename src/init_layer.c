/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:42:12 by kchan             #+#    #+#             */
/*   Updated: 2024/02/01 16:29:45 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_valid_character(const char *s, int c)
{
	while (*s)
	{
		if ((*s) == c)
			return (1);
		s++;
	}
	return (0);
}

void	count_map_entities(char c, t_game *game, unsigned int x, unsigned int y)
{
	if (check_valid_character(CHAR_MAP, c) == 0)
		ft_error_and_free_map("Invalid map: invalid map character", game);
	else if (c == CHAR_PLAYER)
	{
		game->position.x = x;
		game->position.y = y;
		game->map.player++;
	}
	else if (c == CHAR_COLLLECT)
		game->map.collects++;
	else if (c == CHAR_FLOOR)
		game->map.floor++;
	else if (c == CHAR_EXIT)
		game->map.exits++;
}

void	check_required_entities(t_game *game)
{
	if (game->map.collects < 1)
		ft_error_and_free_map
			("Invalid number of collectable, more than one is required", game);
	if (game->map.exits != 1)
		ft_error_and_free_map
			("Invalid number of exit, only 1 exit is allowed", game);
	if (game->map.player != 1)
		ft_error_and_free_map
			("Invalid number of player, only one is allowed", game);
}

void	check_enclosed_wall(t_game *game, unsigned int x, unsigned int y)
{
	if (game->map.repo[0][x] != CHAR_WALL ||
		game->map.repo[game->map.rows - 1][x] != CHAR_WALL)
		ft_error_and_free_map
		("Invalid map: incomplete walls on upper/lower boundaries.", game);
	if (game->map.repo[y][0] != CHAR_WALL ||
		game->map.repo[y][game->map.columns - 1] != CHAR_WALL)
		ft_error_and_free_map
		("Invalid map: incomplete walls on left/right boundaries.", game);
}

void	init_layer(t_game *game)
{
	unsigned int	x;
	unsigned int	y;
	char			character;

	y = 0;
	while (y < (unsigned int)game->map.rows)
	{
		x = 0;
		while (x < (unsigned int)game->map.columns)
		{
			character = game->map.repo[y][x];
			count_map_entities(character, game, x, y);
			check_enclosed_wall(game, x, y);
			x++;
		}
		y++;
	}
	check_required_entities(game);
	ft_mcpy_fill(game);
	flood_fill_check(game, 'X');
}
