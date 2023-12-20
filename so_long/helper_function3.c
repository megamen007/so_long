/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:54:36 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/14 19:25:38 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vree(t_map_data *mape)
{
	ft_printf("Error\nThere is a Problem in your file\n");
	free(mape);
	exit (1);
}

void	tree(t_map_data *mape, char *line)
{
	free(line);
	vree(mape);
}
