/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:50:47 by kawai             #+#    #+#             */
/*   Updated: 2024/01/27 14:05:29 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_up(t_game *game)
{
	// game->map.repo[game->position.y][game->position.x] = '0';
	// game->map.repo[game->position.y-1][game->position.x] = 'P';
	// game->position.move++;
	// place_layer_with_texture(game);
	// display_movements_on_screen(game);
	// game->map.repo[y][x] = '0';
		if(game)
	write(1,"u",1);
}
void move_down(t_game *game)
{
	if(game)
	write(1,"d",1);
}
void move_right(t_game *game)
{
	if(game)
	write(1,"r",1);
}
void move_left(t_game *game)
{
	// game->map.repo[game->position.y][game->position.x] = '0';
	// game->map.repo[game->position.y][game->position.x-1] = 'P';
	// game->position.move++;
	// place_layer_with_texture(game);
	// display_movements_on_screen(game);
	if(game)
	write(1,"l",1);
}

int	exit_game()
{
	ft_printf("GAME EXITED!!\n");
	exit(0);
}

//update function
//movement direction x, y 
//move position

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT ||keycode == KEY_A)
		move_left(game);
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
