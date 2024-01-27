/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:28 by kchan             #+#    #+#             */
/*   Updated: 2024/01/27 16:24:06 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../miniaudio/miniaudio.h"

// void	clean_up(t_game *game)
// {
// // 	// delete_all_image(game);
// // 	// ft_free_map_repo(game->map.repo);
// 	if(game)
// 	write(1,"y",1);
// // 	// mlx_destroy_window(game->mlx, game->mlx_win);		
// // 	// game->mlx = NULL;
// // 	// game->mlx_win = NULL;
// // 	exit(0);
// }

int	main(int ac, char **av)
{
	t_game		game;

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
	mlx_hook(game.mlx_win, ON_KEYDOWN, (1L << 0), handle_keypress, &game); 
	mlx_hook(game.mlx_win, ON_DESTROY, (1L << 2), exit_game, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
	// clean_up(&game);
    return (0);
}

/* extra music
ma_result	result;
ma_engine	engine;

result = ma_engine_init(NULL, &engine);
ma_engine_init(NULL, &engine);
ma_engine_play_sound(&engine, WAV_MUSIC, NULL);
if (result != MA_SUCCESS)
return (-1);  // Failed to initialize the engine.
ma_engine_uninit(&engine);
*/