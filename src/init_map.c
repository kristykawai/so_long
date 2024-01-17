/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:12 by kawai             #+#    #+#             */
/*   Updated: 2024/01/17 23:12:15 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_emtpy_file(char *line)
{
	if (!line)
		ft_error_general("Empty map.");
}

void	init_map(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	line = get_next_line(game->fd);
	is_emtpy_file(line);
	while (line && !(line[0] == '\n'))
	{
		game->map.repo[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!game->map.repo[i])
			ft_error_general("Failed to allocate memory for map row.");
		ft_strlcpy(game->map.repo[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.rows = i; //height
	free(line);
	close(game->fd);
}

int	check_map_len(t_game *game)
{
	int expected_columns;
	int i;

	i = 1;
	expected_columns = ft_strlen(game->map.repo[0]);
	while(i < game->map.rows)
	{
		if (ft_strlen(game->map.repo[i]) != expected_columns)
			return 0;
		i++;
	}
	return 1;
}

