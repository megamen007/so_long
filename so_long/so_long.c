/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:23:19 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/14 19:24:46 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map_data	*mape;

	if (argc == 2)
	{
		mape = malloc(sizeof(t_map_data));
		map_ultimates(mape, argv[1]);
		map_mega_ultimates(mape);
		path_check(mape->p_x, mape->p_y, mape);
		if (check_exit(mape) == 1)
			map_ultimates6(mape);
		if (read_check_map(mape) == 0)
			map_ultimates6(mape);
		else
			render_map_mv(mape);
	}
	else
	{
		ft_printf("Error\nThere is an error in parsing the arguments !\n");
		return (0);
	}
}

void	free_map(t_map_data *mape)
{
	int	i;

	i = 0;
	while (i < mape->row_count)
	{
		free(mape->map[i]);
		i++;
	}
	free(mape->map);
}

void	free_map1(t_map_data *mape)
{
	int	i;

	i = 0;
	while (i < mape->row_count)
	{
		free(mape->raw_map[i]);
		i++;
	}
	free(mape->raw_map);
}

void	map_ultimates(t_map_data *mape, char *path)
{
	if (ber_check(path) == 0)
		map_ultimates0(mape);
	get_map_data(mape, path);
	copie_the_map(mape, path);
	copie_the_map1(mape, path);
}

void	map_mega_ultimates(t_map_data *mape)
{
	int	elements;

	elements = elements_check(mape, mape->map);
	if (check_the_map(mape) == 0)
		map_ultimates1(mape);
	else if (elements == 0)
		map_ultimates2(mape);
	else if (allignement_check(mape) == 0)
		map_ultimates4(mape);
	else if (surrounded_by_walls(mape, mape->map) == 0)
		map_ultimates5(mape);
}
