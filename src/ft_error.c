/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:53:17 by kchan             #+#    #+#             */
/*   Updated: 2024/01/18 10:11:58 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_general(char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	exit(1);
}

void	ft_error_and_free_map(char *msg, t_game *game)
{
	ft_printf("[ERROR] %s\n", msg);
	ft_free_map_repo(game->map.repo);
	if (game->map.fill != NULL)
		ft_free_map_fill(game->map.fill, game->map.columns);
	exit(1);
}

void	ft_free_map_fill(char **map, int cols)
{
	int	i;

	if (!map || !*map)
		ft_error_general("Map data not found or invalid.");
	i = 0;
	while (i < cols && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_free_map_repo(char **target)
{
	int	i;

	if (!target || !*target)
		ft_error_general("Map data not found or invalid.");
	i = 0;
	while (target[i] != NULL)
	{
		free(target[i]);
		i++;
	}
	free(target);
	target = NULL;
}