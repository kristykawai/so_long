/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:19:04 by kchan             #+#    #+#             */
/*   Updated: 2024/02/01 16:29:44 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mcpy_fill(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	game->map.fill = (char **) malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.fill)
		ft_error_and_free_map("Failed to fill map up.", game);
	while (y < (unsigned int) game->map.rows)
	{
		game->map.fill[y]
			= (char *)ft_calloc(game->map.columns + 1, sizeof(char));
		if (!game->map.fill[y])
			ft_error_and_free_map("Failed to fill map up.", game);
		x = 0;
		while (x < (unsigned int) game->map.columns)
		{
			game->map.fill[y][x] = game->map.repo[y][x];
			x++;
		}
		game->map.fill[y][x] = '\0';
		y++;
	}
	game->map.fill[y] = NULL;
}

void	flood_fill_recursive(t_game *game, int x, int y, char replacement)
{
	if (x < 0 || x >= game->map.columns || y < 0 || y >= game->map.rows)
		return ;
	if (game->map.fill[y][x] != CHAR_WALL)
		game->map.fill[y][x] = replacement;
	if (ft_strchr("1X", game->map.fill[y][x - 1]) == NULL)
		flood_fill_recursive(game, x - 1, y, replacement);
	if (ft_strchr("1X", game->map.fill[y][x + 1]) == NULL)
		flood_fill_recursive(game, x + 1, y, replacement);
	if (ft_strchr("1X", game->map.fill[y - 1][x]) == NULL)
		flood_fill_recursive(game, x, y - 1, replacement);
	if (ft_strchr("1X", game->map.fill[y + 1][x]) == NULL)
		flood_fill_recursive(game, x, y + 1, replacement);
}

void	check_flood_fill_remain(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (ft_strchr("E", game->map.fill[y][x]) != NULL)
				ft_error_and_free_map
				("Invalid map: no valid path to exit", game);
			else if (ft_strchr("C", game->map.fill[y][x]) != NULL)
				ft_error_and_free_map
				("Invalid map: no valid path to one or more collectable", game);
			x++;
		}
		y++;
	}
}

void	flood_fill_check(t_game	*game, char replacement)
{
	flood_fill_recursive(game, game->position.x, game->position.y, replacement);
	check_flood_fill_remain(game);
}
