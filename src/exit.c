/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:27:53 by kawai             #+#    #+#             */
/*   Updated: 2024/01/27 20:28:15 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(void)
{
	ft_printf("GAME EXITED!!\n");
	exit(0);
}

int	exit_win_game(t_game *game)
{
	ft_printf("You win!\n");
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
