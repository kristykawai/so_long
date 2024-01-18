/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:12 by kawai             #+#    #+#             */
/*   Updated: 2024/01/18 10:49:16 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	while (line && (line[0] != '\n'))
	{
		// game->map.repo[i] = malloc(sizeof(char) * (ft_readline(line) + 1));
		// if (!game->map.repo[i])
		// 	ft_error_general("Failed to allocate memory for map row.");
		// ft_strlcpy(game->map.repo[i], line, ft_strlen(line) + 1);
		// free(line);
		line = get_next_line(game->fd);
		i++;
	}
	game->map.rows = i; //height
	free(line);
	close(game->fd);//close map
}

int	check_map_len(t_game *game)
{
	int expected_columns;
	int i;

	i = 1;
	expected_columns = ft_strlen(game->map.repo[0]);
	while(i < game->map.rows)
	{
		if (ft_strlen(game->map.repo[i]) != (size_t)expected_columns)
			return (0);
		i++;
	}
	return 1;
}

int	check_enclosed_wall(t_game *game)
{
	int i;
	int max_coor_x;
	int max_coor_y;

	i = 0;
	max_coor_x = game->map.columns - 1;
	max_coor_y = game->map.rows - 1;
	while (i <= max_coor_y)
	{
		if (game->map.repo[0][i] != CHAR_WALL && 
			game->map.repo[max_coor_x][i] != CHAR_WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i <= max_coor_x)
	{
		if (game->map.repo[i][0] != CHAR_WALL && 
			game->map.repo[i][max_coor_y] != CHAR_WALL)
			return (0);
		i++;
	}
	return (1);
}
