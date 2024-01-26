/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:18:40 by kchan             #+#    #+#             */
/*   Updated: 2024/01/26 22:07:46 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_argument(int ac, char **av)
{
	int	file_len;

    file_len = 0;
	if (ac != 2)
		ft_error_general("Invalid number of argument input. Try: ./so_long ./map/small_map.ber");
	file_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][file_len - 4], ".ber", 4))
		ft_error_general("Invalid map file. Only accept .ber");
}

void	is_emtpy_file(char *line)
{
	if (!line)
		ft_error_general("Empty map.");
}

int	check_row_len(t_game *game)
{
	int		expected_columns;
	int		i;

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

void	check_valid_map_size(t_game *game)
{
	if (game->map.rows > MAP_HEIGHT / TILE_HEIGHT)
		ft_error_and_free_map("Map is too big.\n", game);
	else if (!check_row_len(game))
		ft_error_general("Invalid map: not retangular.");
}
