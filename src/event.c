/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:50:47 by kawai             #+#    #+#             */
/*   Updated: 2024/01/22 22:42:14 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	handle_keypress(int keycode)
// {
// 	// if (keycode == KEY_UP)
// 	// 	move_up();
// 	// else if (keycode == KEY_DOWN)
// 	// 	move_down();
// 	// else if (keycode == KEY_RIGHT)
// 	// 	move_right();
// 	// else if (keycode == KEY_LEFT)
// 	// 	move_left();
// 	if (keycode == ESC_KEY)
// 		exit_game();
// 	return (0);
// }

int	keyboard(int keyhook, t_game *game)
{
	if(!game)
		return (0);
	if (keyhook == ESC_KEY)
		close_the_win(game); 
	return (0);
}

void	exit_game()
{
	ft_printf("GAME EXITED!!\n");
	exit(0);
}

int	close_the_win(t_game *game)
{
	ft_printf("YOU WIN!!!\n");
	mlx_destroy_window(game->mlx, game->mlx_win);
	// exit(1);
	return(0);
}

int	mlx_hook_event(t_game *game)
{
	mlx_hook(game->mlx_win, ON_KEYDOWN, 0, keyboard, &game); 
	mlx_hook(game->mlx_win, ON_DESTROY, 0, close_the_win, &game); 
    return (0);
}


// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
// 	// Register destroy hook
// mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 