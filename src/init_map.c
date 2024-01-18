/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:12 by kawai             #+#    #+#             */
/*   Updated: 2024/01/18 17:33:53 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_emtpy_file(char *line)
{
	if (!line)
		ft_error_general("Empty map.");
}

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

int	check_map_len(t_game *game)
{
	int expected_columns;
	int i;

	i = 1;
	expected_columns = ft_strlen(game->map.repo[0]);
	game->map.columns = expected_columns;
	while(i < game->map.rows)
	{
		if (ft_strlen(game->map.repo[i]) != (size_t)expected_columns)
			return (0);
		i++;
	}
	return (1);
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
	game->map.rows = i; //height
	free(line);
	close(game->fd);
}

int	check_enclosed_wall(t_game *game)
{
	int i;
	int max_coor_x;
	int max_coor_y;

	i = -1;
	max_coor_x = game->map.columns;
	max_coor_y = game->map.rows;
	while (++i < max_coor_y)
	{
		if (game->map.repo[0][i] != CHAR_WALL && 
			game->map.repo[max_coor_x][i] != CHAR_WALL)
			return (0);
	}
	i = -1;
	while (++i < max_coor_x)
	{
		if (game->map.repo[i][0] != CHAR_WALL && 
			game->map.repo[i][max_coor_y] != CHAR_WALL)
			return (0);
	}
	return (1);
}

void check_valid_map(t_game *game)
{
	if (game->map.rows > MAP_HEIGHT / TILE_HEIGHT)
		ft_error_and_free_map("Map is too big.\n", game);
	else if (!check_map_len(game))
		ft_error_general("Invalid map: not retangular.");
	else if (!check_enclosed_wall(game))
		ft_error_general("Invalid map: not enclosed wall.");
}

//printCharMatrix(game->map.repo,game->map.rows,game->map.columns);
		

