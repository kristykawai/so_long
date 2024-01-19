/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:26:06 by kawai             #+#    #+#             */
/*   Updated: 2024/01/19 15:09:49 by kchan            ###   ########.fr       */
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
