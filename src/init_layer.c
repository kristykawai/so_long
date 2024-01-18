/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:42:12 by kchan             #+#    #+#             */
/*   Updated: 2024/01/18 10:13:16 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_argument(int ac, char **av)
{
	int	file_len;

    file_len = 0;
	if (ac != 2)
		ft_error_general("Invalid number of argument input. Try: ./so_long ./map/small_map.ber");
	file_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][file_len - 4], ".ber", 4))
		ft_error_general("Invalid map file. Only accept .ber");
}


