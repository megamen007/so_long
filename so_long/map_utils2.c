/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:22:27 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/13 22:29:38 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_the_map(t_map_data *mape, char **map)
{
	int	j;
	int	i;

	i = 0;
	while (i < mape->row_count)
	{
		j = 0;
		while (j < mape->col_count)
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	get_map_data(t_map_data *mape, char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		vree(mape);
	line = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		tree(mape, line);
	mape->c_col_count = strlen_nn(line);
	mape->col_count = strlen_nn(line);
	mape->row_count = 0;
	while (line)
	{
		(mape->row_count)++;
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	allignement_check(t_map_data *mape)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(mape->map[0]);
	while (i < mape->row_count - 1)
	{
		j = ft_strlen(mape->map[i]);
		if (j != size)
			return (0);
		i++;
	}
	return (1);
}

void	moves_c(t_map_data *mape)
{
	mape->moves++;
	ft_printf("moves : %d\n", mape->moves);
}
