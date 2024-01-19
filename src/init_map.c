/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:12 by kawai             #+#    #+#             */
/*   Updated: 2024/01/19 15:08:50 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_2d_malloc(t_game *game)
{
	if (!game->map.repo)
	{
		game->map.repo = (char **)malloc(sizeof(char *) * 100);
		if (!game->map.repo)
			ft_error_general("Failed to allocate memory for map.");
		ft_memset(game->map.repo, 0, 100);
	}
}

void	init_map(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	line = get_next_line(game->fd);
	is_emtpy_file(line);
	while (line && (line[0] != '\n'))
	{
		if (game->map.repo == NULL)
			map_2d_malloc(game);
		game->map.repo[i] = malloc(sizeof(char) * (ft_readline(line) + 1));
		if (!game->map.repo[i])
			ft_error_general("Failed to allocate memory for map");
		ft_strlcpy(game->map.repo[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.rows = i;
	free(line);
	close(game->fd);
}
