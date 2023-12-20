/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 03:09:20 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/13 22:05:39 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	elements_check(t_map_data *mape, char **map)
{
	mape->c_c = 0;
	mape->c_e = 0;
	mape->c_p = 0;
	element(mape, map);
	if (mape->c_c == 0 || mape->c_e != 1 || mape->c_p != 1)
		return (0);
	return (1);
}

int	rectangle_map(t_map_data *mape, char **map)
{
	(void)map;
	if (mape->row_count >= 5 & mape->col_count >= 3
		|| mape->row_count >= 3 & mape->col_count >= 5)
		return (1);
	else
		return (0);
}

int	strlen_nn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int	ber_check(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i] != 'r')
	{
		return (0);
	}
	if (path[i - 1] != 'e')
	{
		return (0);
	}
	if (path[i - 2] != 'b')
	{
		return (0);
	}
	if (path[i - 3] != '.')
	{
		return (0);
	}
	return (1);
}

void	annihilation(t_map_data *mape)
{
	if (mape->win)
	{
		mlx_destroy_image(mape->mlx, mape->background);
		mlx_destroy_image(mape->mlx, mape->door);
		mlx_destroy_image(mape->mlx, mape->player);
		mlx_destroy_image(mape->mlx, mape->wall);
		mlx_destroy_image(mape->mlx, mape->collectible);
		mlx_destroy_window(mape->mlx, mape->win);
	}
}
