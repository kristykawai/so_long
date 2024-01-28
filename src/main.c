/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:28 by kchan             #+#    #+#             */
/*   Updated: 2024/01/28 23:38:54 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_up(t_game *game)
{
	delete_all_image(game);
	ft_free_map_repo(game->map.repo);
	ft_free_map_fill(game->map.fill, game->map.columns);
	mlx_destroy_window(game->mlx, game->mlx_win);		
	game->mlx_win = NULL;
	game->mlx = NULL;
	exit(0);
}

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
	clean_up(&game);
    return (0);
}
