/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:50:47 by kawai             #+#    #+#             */
/*   Updated: 2024/01/27 16:18:48 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_up(t_game *game)
{
	game->map.repo[game->position.y][game->position.x] = '0';
	game->map.repo[game->position.y - 1][game->position.x] = 'P';
	game->position.y -= 1;
	game->position.move++;
	// game->img.player.y -= TILE_HEIGHT;
	// ft_printf("%c",	game->map.repo[game->position.y-1][game->position.x]);
}
void move_down(t_game *game)
{
	game->map.repo[game->position.y][game->position.x] = '0';
	game->map.repo[game->position.y + 1][game->position.x] = 'P';
	game->position.y += 1;
	game->position.move++;
}
void move_right(t_game *game)
{
	game->map.repo[game->position.y][game->position.x] = '0';
	game->map.repo[game->position.y][game->position.x + 1] = 'P';
	game->position.x += 1;
	game->position.move++;
}
void move_left(t_game *game)
{
	game->map.repo[game->position.y][game->position.x] = '0';
	game->map.repo[game->position.y][game->position.x - 1] = 'P';
	game->position.x -= 1;
	game->position.move++;
	// place_layer_with_texture(game);
	// display_movements_on_screen(game);
}

int	exit_game()
{
	ft_printf("GAME EXITED!!\n");
	exit(0);
}
// && game->map.repo[game->position.y-1][game->position.x]!= 'E'
//update function
//movement direction x, y 
//move position

int	handle_keypress(int keycode, t_game *game)
{
	if ((keycode == KEY_UP || keycode == KEY_W))
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



// int	close_the_win(t_game *game)
// {
// 	ft_printf("YOU WIN!!!\n");
// 	mlx_destroy_window(game->mlx, game->mlx_win);
// 	// exit(1);
// 	return(0);
// }
