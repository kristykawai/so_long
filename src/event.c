/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:50:47 by kawai             #+#    #+#             */
/*   Updated: 2024/01/28 22:32:56 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if(game->position.y > 0 && 
		game->map.repo[game->position.y - 1][game->position.x] != CHAR_WALL)
	{
		if(game->map.repo[game->position.y - 1][game->position.x] == CHAR_COLLLECT)
			game->count++;
		else if(game->map.repo[game->position.y - 1][game->position.x] == CHAR_EXIT 
			&& !is_all_collected(game))
			return	;
		else if(game->map.repo[game->position.y - 1][game->position.x] == CHAR_EXIT 
			&& is_all_collected(game))
			exit_win_game(game);
		game->map.repo[game->position.y][game->position.x] = CHAR_FLOOR;
		game->map.repo[game->position.y - 1][game->position.x] = CHAR_PLAYER;
		game->position.y -= 1;
		game->position.move++;
	}
}

void	move_down(t_game *game)
{
	if(game->position.y + 1 < game->map.rows && 
		game->map.repo[game->position.y + 1][game->position.x] != CHAR_WALL)
	{
		if(game->map.repo[game->position.y + 1][game->position.x] == CHAR_COLLLECT)
			game->count++;
		else if(game->map.repo[game->position.y + 1][game->position.x] == CHAR_EXIT 
			&& !is_all_collected(game))
			return	;
		else if(game->map.repo[game->position.y + 1][game->position.x] == CHAR_EXIT 
		&& is_all_collected(game))
			exit_win_game(game);
		game->map.repo[game->position.y][game->position.x] = CHAR_FLOOR;
		game->map.repo[game->position.y + 1][game->position.x] = CHAR_PLAYER;
		game->position.y += 1;
		game->position.move++;
	}
}

void	move_right(t_game *game)
{
	if(game->position.x + 1 < game->map.columns && 
		game->map.repo[game->position.y][game->position.x + 1] != CHAR_WALL)
	{
		if(game->map.repo[game->position.y][game->position.x + 1] == CHAR_COLLLECT)
			game->count++;
		else if(game->map.repo[game->position.y][game->position.x + 1] == CHAR_EXIT 
			&& !is_all_collected(game))
			return	;
		else if(game->map.repo[game->position.y][game->position.x + 1] == CHAR_EXIT 
		&& is_all_collected(game))
			exit_win_game(game);
		game->map.repo[game->position.y][game->position.x] = CHAR_FLOOR;
		game->map.repo[game->position.y][game->position.x + 1] = CHAR_PLAYER;
		game->position.x += 1;
		game->position.move++;
	}
}

void	move_left(t_game *game)
{
	if(game->position.x > 0 && 
		game->map.repo[game->position.y][game->position.x - 1] != CHAR_WALL)
	{
		if(game->map.repo[game->position.y][game->position.x - 1] == CHAR_COLLLECT)
			game->count++;
		else if(game->map.repo[game->position.y][game->position.x - 1] == CHAR_EXIT 
			&& !is_all_collected(game))
			return	;
		else if(game->map.repo[game->position.y][game->position.x - 1] == CHAR_EXIT 
		&& is_all_collected(game))
			exit_win_game(game);
		game->map.repo[game->position.y][game->position.x] = CHAR_FLOOR;
		game->map.repo[game->position.y][game->position.x - 1] = 'P';
		game->position.x -= 1;
		game->position.move++;
	}
	// display_movements_on_screen(game);
}

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
