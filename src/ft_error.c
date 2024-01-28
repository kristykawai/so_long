/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:53:17 by kchan             #+#    #+#             */
/*   Updated: 2024/01/28 23:06:28 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_general(char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	exit(1);
}

void	ft_free_map_repo(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || !*matrix)
		ft_error_general("Invalid Map.");
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_free_map_fill(char **matrix, int cols_to_free)
{
	int	i;

	i = 0;
	if (!matrix || !*matrix)
		ft_error_general("Invalid Map.");
	while (i < cols_to_free && matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_error_and_free_map(char *msg, t_game *game)
{
	ft_printf("[ERROR] %s\n", msg);
	ft_free_map_repo(game->map.repo);
	if (game->map.fill != NULL)
		ft_free_map_fill(game->map.fill, game->map.columns);
	exit(1);
}
