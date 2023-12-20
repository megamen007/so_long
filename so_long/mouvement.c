/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:40:42 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/18 01:52:11 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_up(t_map_data *mape)
{
	if (mape->map[mape->p_x - 1][mape->p_y] == '1')
	{
		mape->map[mape->p_x][mape->p_y] = 'P';
		paint(mape);
	}
	else if (mape->map[mape->p_x - 1][mape->p_y] == '0')
	{
		up_3(mape);
		moves_c(mape);
	}
	else if (mape->map[mape->p_x - 1][mape->p_y] == 'C')
	{
		mape->c_c--;
		up_3(mape);
		moves_c(mape);
	}
	else if (mape->map[mape->p_x - 1][mape->p_y] == 'E' && mape->c_c == 0)
	{
		ft_printf("win_win\n");
		exito(mape);
	}
}

void	down_down(t_map_data *mape)
{
	if (mape->map[mape->p_x + 1][mape->p_y] == '1')
	{
		mape->map[mape->p_x][mape->p_y] = 'P';
		paint(mape);
	}
	else if (mape->map[mape->p_x + 1][mape->p_y] == '0')
	{
		down_3(mape);
		moves_c(mape);
	}
	else if (mape->map[mape->p_x + 1][mape->p_y] == 'C')
	{
		mape->c_c--;
		down_3(mape);
		moves_c(mape);
	}
	else if (mape->map[mape->p_x + 1][mape->p_y] == 'E' && mape->c_c == 0)
	{
		ft_printf("rak_rbe7ti_al7bib\n");
		exito(mape);
	}
}

void	right_right(t_map_data *mape)
{
	if (mape->map[mape->p_x][mape->p_y + 1] == '1')
	{
		mape->map[mape->p_x][mape->p_y] = 'P';
		paint(mape);
	}
	else if (mape->map[mape->p_x][mape->p_y + 1] == 'C')
	{
		mape->c_c--;
		right_3(mape);
		moves_c(mape);
	}
	else if (mape->map[mape->p_x][mape->p_y + 1] == '0')
	{
		right_3(mape);
		moves_c(mape);
	}
	else if (mape->map[mape->p_x][mape->p_y + 1] == 'E' && mape->c_c == 0)
	{
		ft_printf("win_win\n");
		exito(mape);
	}
}

void	left_left(t_map_data *mape)
{
	if (mape->map[mape->p_x][mape->p_y - 1] == 'E' && mape->c_c == 0)
	{
		ft_printf("raak nadii\n");
		exito(mape);
	}
	else if (mape->map[mape->p_x][mape->p_y - 1] == '1')
	{
		mape->map[mape->p_x][mape->p_y] = 'P';
		paint(mape);
	}
	else if (mape->map[mape->p_x][mape->p_y - 1] == 'C')
	{
		mape->c_c--;
		left_3(mape);
		moves_c(mape);
	}
	else if (mape->map[mape->p_x][mape->p_y - 1] == '0')
	{
		left_3(mape);
		moves_c(mape);
	}
}
