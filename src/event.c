/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:50:47 by kawai             #+#    #+#             */
/*   Updated: 2024/01/26 23:48:00 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_up()
{
	write(1,"u",1);
}
void move_down()
{
	write(1,"d",1);
}
void move_right()
{
	write(1,"r",1);
}
void move_left()
{
	write(1,"l",1);
}

int	exit_game()
{
	ft_printf("GAME EXITED!!\n");
	exit(0);
}

int	handle_keypress(int keycode)
{
	if (keycode == KEY_UP)
		move_up();
	else if (keycode == KEY_DOWN)
		move_down();
	else if (keycode == KEY_RIGHT)
		move_right();
	else if (keycode == KEY_LEFT)
		move_left();
	else if (keycode == ESC_KEY)
		exit_game();
	else if (keycode == KEY_Q)
		exit_game();
	return (0);
}

int	mlx_hook_event(t_game *game)
{
	mlx_hook(game->mlx_win, ON_KEYDOWN, (1L << 0), handle_keypress, &game); 
	mlx_hook(game->mlx_win, ON_DESTROY, (1L << 2), exit_game, &game);
    return (0);
}

// int	close_the_win(t_game *game)
// {
// 	ft_printf("YOU WIN!!!\n");
// 	mlx_destroy_window(game->mlx, game->mlx_win);
// 	// exit(1);
// 	return(0);
// }
