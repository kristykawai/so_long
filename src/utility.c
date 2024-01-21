/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:26:06 by kawai             #+#    #+#             */
/*   Updated: 2024/01/21 17:37:02 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_readline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (i);
}

void printCharMatrix(char **matrix, int rows, int cols) 
{
	int i;
	int	j;
	
	i = 0;
    while (i < rows) 
	{
		j = 0;
        while(j < cols) 
		{
            ft_printf("%c", matrix[i][j]);
			j++;
        }
        // ft_printf("\n");
		i++;
    }
}

void	place_xpm_to_img(t_game *game, char **img_path, char *xpm_path)
{
	*img_path = mlx_xpm_file_to_image(game->mlx, xpm_path, &game->pixel, &game->pixel);
	if (!*img_path)
		ft_error_and_free_map("Invalid image for map texturing.", game);
}

void	ft_mlx_image_to_window(t_game *game, char *mlx_img, int x, int y)
{	
	if (!mlx_img)
	{
		ft_free_map_repo(game->map.repo);
		ft_error_general("mlx image uninit");
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, mlx_img, TILE_WIDTH * x, TILE_HEIGHT * y);
	// mlx_do_sync(game->mlx);
}
