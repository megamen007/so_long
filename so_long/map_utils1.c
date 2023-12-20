/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:19:11 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/13 22:51:04 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_check(int x, int y, t_map_data *mape)
{
	if (mape->raw_map[x + 1][y] == '0' || mape->raw_map[x + 1][y] == 'C')
	{
		mape->raw_map[x + 1][y] = 'P';
		path_check(x + 1, y, mape);
	}
	if (mape->raw_map[x - 1][y] == '0' || mape->raw_map[x - 1][y] == 'C')
	{
		mape->raw_map[x - 1][y] = 'P';
		path_check(x - 1, y, mape);
	}
	if (mape->raw_map[x][y + 1] == '0' || mape->raw_map[x][y + 1] == 'C')
	{
		mape->raw_map[x][y + 1] = 'P';
		path_check(x, y + 1, mape);
	}
	if (mape->raw_map[x][y - 1] == '0' || mape->raw_map[x][y - 1] == 'C' )
	{
		mape->raw_map[x][y - 1] = 'P';
		path_check(x, y - 1, mape);
	}
}

int	walls(t_map_data *mape, char **map)
{
	int	start_one;
	int	end_one;
	int	k;

	k = 1;
	while (k < mape->row_count - 1)
	{
		start_one = 0;
		end_one = 0;
		if (map[k][0] == '1')
			start_one = 1;
		if (map[k][ft_strlen(map[k]) - 2] == '1')
			end_one = 1;
		if (start_one != 1 || end_one != 1)
			return (0);
		k++;
	}
	return (1);
}

int	surrounded_by_walls(t_map_data *mape, char **map)
{
	int	j;
	int	i;

	i = 0;
	while (i < mape->col_count)
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < mape->col_count)
	{
		if (map[(mape->row_count - 1)][j] != '1')
			return (0);
		j++;
	}
	if (!walls(mape, map))
		return (0);
	return (1);
}

int	check_the_map(t_map_data *init)
{
	int	j;
	int	i;

	i = 0;
	while (i < init->row_count)
	{
		j = 0;
		while (j < init->col_count)
		{
			if (init->map[i][j] != '0' && init->map[i][j] != '1' &&
				init->map[i][j] != 'P' && init->map[i][j] != 'E' &&
				init->map[i][j] != 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
