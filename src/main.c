/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:28 by kchan             #+#    #+#             */
/*   Updated: 2024/01/08 18:09:24 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

int argb_to_int(float opac, float r, float g, float b)
{
    int color = 0;

    color |= (int)(b * 255) ;
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    color |= (int)(opac * 255)<< 24;

    return (color);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Draw line");
	img.img = mlx_new_image(mlx, 1920,1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
	// my_mlx_pixel_put(&img, 1920/2, 1080/2, argb_to_int(0,1,1,1));
	// my_mlx_pixel_put(&img, 1920/2+1, 1080/2+1, argb_to_int(0,1,1,1));
	my_mlx_pixel_put(&img, 0, 0, argb_to_int(0,1,0,1));
	my_mlx_pixel_put(&img, 3, 3, argb_to_int(1,0,0,1));

	// my_mlx_pixel_put(&img, 6, 6, argb_to_int(1,0,0,1));
	// my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	// my_mlx_pixel_put(&img, 7, 5, 0x00FF0000);
	// my_mlx_pixel_put(&i mg, 8, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 1920/2, 1080/2);
	mlx_loop(mlx);
	// mlx_destroy_window(mlx, mlx_win);
    // mlx_destroy_image(mlx, img.img);
	// free(mlx);


	return (0);
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