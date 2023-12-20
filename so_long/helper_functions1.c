/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:21:10 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/14 19:25:20 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_ultimates4(t_map_data *mape)
{
	ft_printf("Error\nmap shape incorrect\n");
	free(mape);
	exit(1);
}

void	map_ultimates5(t_map_data *mape)
{
	ft_printf("Error\nWall problem\n");
	free(mape);
	exit(1);
}

void	map_ultimates6(t_map_data *mape)
{
	ft_printf("Error\nPATH problem\n");
	free(mape);
	exit(1);
}

void	put_imagetowindow(t_map_data *mape, int i, int j)
{
	if (mape->cur_char == '1')
		mlx_put_image_to_window(mape->mlx, mape->win, mape->wall, i * 50,
			j * 50);
	if (mape->cur_char == '0' || mape->cur_char == 'C' || mape->cur_char == 'E'
		|| mape->cur_char == 'P')
		mlx_put_image_to_window(mape->mlx, mape->win, mape->background, i * 50,
			j * 50);
	if (mape->cur_char == 'C')
		mlx_put_image_to_window(mape->mlx, mape->win, mape->collectible, i * 50,
			j * 50);
	if (mape->cur_char == 'P')
		mlx_put_image_to_window(mape->mlx, mape->win, mape->player, i * 50,
			j * 50);
	if (mape->cur_char == 'E' )
		mlx_put_image_to_window(mape->mlx, mape->win, mape->door, i * 50,
			j * 50);
}
