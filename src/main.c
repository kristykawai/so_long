/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:28 by kchan             #+#    #+#             */
/*   Updated: 2024/01/08 13:57:30 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//tutorial https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#introduction
// not too sure what is offset in this context
// int offset = (y * line_length + x * (bits_per_pixel/8));
// Note that 0x00FF0000 is the hex representation of ARGB(0,255,0,0)
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

/*
int rgb_to_int(float r, float g, float b, float opac)
{
    int color = 0;

    color |= (int)(opac * 255);
    color |= (int)(b * 255) << 8;
    color |= (int)(g * 255) << 16;
    color |= (int)(r * 255) << 24;
    return (color);
}
*/
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Draw pixel");
	img.img = mlx_new_image(mlx, 1920,1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, rgb_to_int(1,0,1,0.1));
	// my_mlx_pixel_put(&img, 6, 6, rgb_to_int(1,0,1,0.1));
	// my_mlx_pixel_put(&img, 7, 7, rgb_to_int(1,0,1,0.1));
	my_mlx_pixel_put(&img, 7, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
	mlx_loop(mlx);
}

// #include "../minilibx/mlx.h"


// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 100, 100, "Hello world!");
// 	img.img = mlx_new_image(mlx, 100, 100);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
	
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 7, 5, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 8, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
// 	mlx_loop(mlx);
// }