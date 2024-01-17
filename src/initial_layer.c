/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:42:12 by kchan             #+#    #+#             */
/*   Updated: 2024/01/17 17:12:34 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argument(int ac, char **av, t_game *game)
{
	int	file_len;

    file_len = 0;
	if (ac != 2)
		ft_error_general("Invalid number of argument input. Try: ./so_long ./map/small_map.ber");
	file_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][file_len - 4], ".ber", 4))
		ft_error_general("Invalid map file. Only accept .ber");
}

void	setting_up_data(t_data *data)
{
	data->map_x = 0; 
	data->map_y = 0; 
	data->map_area = 0; 
	data->x = 0; 
	data->y = 0; 
	data->pixel = 0; 
	data->player = 0; 
	data->player_movements = 0; 
	data->player_direction = "images/mario.xpm"; 
	data->coins = 0; 
	data->exit = 0; 
}

void	init_value(t_game *game)
{
	game->position.x = 0; //start position x
	game->position.y = 0; //start position y
	game->position.move = 0;
	game->map.columns = 0; //x
	game->map.rows = 0; //y
	game->map.collects = 0;
	game->map.exits = 0;
	game->map.player = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.repo = NULL;
	game->count = 0;
	game->finish_game = 0;
	game->map.fill = NULL;
}

void	set_player_position(t_multi *info, t_position *position)
{
	info->x = position->x;
	info->y = position->y;
	ft_printf("Player position set to (%d,%d)\n", position->x, position->y);
}

void	init_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(IMG_WIDTH * game->map.rows, \
		IMG_HEIGHT * game->map.columns, "so long", true);
	if (!game->mlx)
	{
		ft_error_and_free_map("Failed to initialize MLX.", game);
		exit(1);
	}
}