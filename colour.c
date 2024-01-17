/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:30:13 by kchan             #+#    #+#             */
/*   Updated: 2024/01/17 13:30:42 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int argb_to_int(float opac, float r, float g, float b)
{
    int color = 0;

    color |= (int)(b * 255) ;
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    color |= (int)(opac * 255)<< 24;ß

    return (color);
}