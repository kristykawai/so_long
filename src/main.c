/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:28 by kchan             #+#    #+#             */
/*   Updated: 2024/01/21 17:38:40 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game		game;
	// ma_result	result;
	// ma_engine	engine;
	
	check_argument(ac, av);
	game.fd = open(av[1], O_RDONLY);
	if (game.fd < 0 || game.fd == 0)
		ft_error_general("Failed to open file\n");
	init_value(&game);
	init_map(&game);
	check_valid_map_size(&game);
	init_layer(&game);
	init_mlx(&game);
	place_texture(&game);
	// result = ma_engine_init(NULL, &engine);
	// ma_engine_play_sound(&engine, WAV_MUSIC, NULL);
	// mlx_key_hook(game.mlx, &key_hook, &game.mlx);
	mlx_loop(game.mlx);
	// clean_up(&game, &engine);
}
