/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper-function2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:06:16 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/17 05:01:08 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_3(t_map_data *mape)
{
	mape->map[mape->p_x - 1][mape->p_y] = 'P';
	mape->map[mape->p_x][mape->p_y] = '0';
	mape->p_x--;
	paint(mape);
}

void	down_3(t_map_data *mape)
{
	mape->map[mape->p_x + 1][mape->p_y] = 'P';
	mape->map[mape->p_x][mape->p_y] = '0';
	mape->p_x++;
	paint(mape);
}

void	left_3(t_map_data *mape)
{
	mape->map[mape->p_x][mape->p_y - 1] = 'P';
	mape->map[mape->p_x][mape->p_y] = '0';
	mape->p_y--;
	paint(mape);
}

void	right_3(t_map_data *mape)
{
	mape->map[mape->p_x][mape->p_y + 1] = 'P';
	mape->map[mape->p_x][mape->p_y] = '0';
	mape->p_y++;
	paint(mape);
}
