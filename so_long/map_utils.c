/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:19:08 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/14 19:23:17 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	element(t_map_data *mape, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mape->row_count)
	{
		j = -1;
		while (++j < mape->col_count)
		{
			if (map[i][j] == 'C')
				mape->c_c++;
			if (map[i][j] == 'E')
				mape->c_e++;
			if (map[i][j] == 'P')
			{
				mape->c_p++;
				mape->p_x = i;
				mape->p_y = j;
			}
		}
	}
}

void	copie_the_map(t_map_data *mape, char *path)
{
	int	fd;
	int	i;
	int	j;

	j = 0;
	i = 0;
	mape->map = malloc(mape->row_count * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{	
		free(mape->map);
		free(mape);
		exit(1);
	}
	while (i < mape->row_count)
	{
		mape->map[i] = get_next_line(fd);
		i++;
	}
}

void	copie_the_map1(t_map_data *mape, char *path)
{
	int	fd;
	int	i;

	i = 0;
	mape->raw_map = malloc(mape->row_count * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(mape->raw_map);
		free(mape);
		exit(1);
	}
	while (i < mape->row_count)
	{
		mape->raw_map[i] = get_next_line(fd);
		i++;
	}
}

int	read_check_map(t_map_data *mape)
{
	int	z;
	int	j;
	int	found_path;

	z = 0;
	found_path = 1;
	while (z < mape->row_count)
	{
		j = 0;
		while (j < mape->col_count)
		{
			if (mape->raw_map[z][j] == 'C')
				found_path = 0;
			j++;
		}
		z++;
	}
	if (found_path == 1)
		return (1);
	return (0);
}

int	check_exit(t_map_data *mape)
{
	int	z;
	int	j;
	int	found_path;

	z = -1;
	found_path = 1;
	while (++z < mape->row_count)
	{
		j = -1;
		while (++j < mape->col_count)
		{
			if (mape->raw_map[z][j] == 'E')
			{
				if (mape->raw_map[z + 1][j] == 'P'
					|| mape->raw_map[z - 1][j] == 'P'
					|| mape->raw_map[z][j + 1] == 'P'
					|| mape->raw_map[z][j - 1] == 'P' )
					found_path = 0;
			}
		}
	}
	if (found_path == 1)
		return (1);
	return (0);
}
