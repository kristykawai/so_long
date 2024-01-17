/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:30:13 by kchan             #+#    #+#             */
/*   Updated: 2024/01/17 21:29:13 by kawai            ###   ########.fr       */
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