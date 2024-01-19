/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:19:04 by kchan             #+#    #+#             */
/*   Updated: 2024/01/19 16:59:57 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
	coordinates are represented as [y][x] // [row][column]
	allocate malloc row by row, copy and null terminate each char string copied as well as for the double pointer
*/

void	ft_mcpy_fill(t_game *game)
{
	unsigned int x;
	unsigned int y;

	y = 0;
	game->map.fill = (char **) malloc(sizeof(char *) * (game->map.rows + 1));
	if(!game->map.fill)
		ft_error_and_free_map("Failed to fill map up.", game);
	
	while (y < (unsigned int) game->map.rows)
	{
		game->map.fill[y] = (char *)ft_calloc(game->map.columns + 1, sizeof(char));
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
