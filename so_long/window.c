/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:21:43 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/14 19:11:16 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map_mv(t_map_data *mape)
{
	mape->mlx = mlx_init();
	mape->win = mlx_new_window(mape->mlx, \
	mape->col_count * 50, mape->row_count * 50, "So Long");
	mape->wall = mlx_xpm_file_to_image(mape->mlx, \
	"./textures/wall.xpm", &mape->w, &mape->h);
	mape->background = mlx_xpm_file_to_image(mape->mlx, \
	"./textures/floor.xpm", &mape->w, &mape->h);
	mape->collectible = mlx_xpm_file_to_image(mape->mlx, \
	"./textures/collectible.xpm", &mape->w, &mape->h);
	mape->player = mlx_xpm_file_to_image(mape->mlx, \
	"./textures/player.xpm", &mape->w, &mape->h);
	mape->door = mlx_xpm_file_to_image(mape->mlx, \
	"./textures/door.xpm", &mape->w, &mape->h);
	image_error(mape);
	paint(mape);
	mape->moves = 0;
	mlx_key_hook(mape->win, mouvements_p, mape);
	mlx_hook(mape->win, 17, 0, exito, mape);
	mlx_loop(mape->mlx);
}

void	paint(t_map_data *mape)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mape->col_count)
	{
		j = -1;
		while (++j < mape->row_count)
		{
			mape->cur_char = mape->map[j][i];
			put_imagetowindow(mape, i, j);
		}
	}
}

void	image_error(t_map_data *mape)
{
	if (mape->wall == NULL)
	{
		ft_printf("Error\n");
		exito(mape);
	}
	if (mape->background == NULL)
	{
		ft_printf("Error\n");
		exito(mape);
	}
	if (mape->collectible == NULL)
	{
		ft_printf("Error\n");
		exito(mape);
	}
	if (mape->player == NULL)
	{
		ft_printf("Error\n");
		exito(mape);
	}
	if (mape->door == NULL)
	{
		ft_printf("Error\n");
		exito(mape);
	}
}

int	mouvements_p(int keycode, t_map_data *mape)
{
	if (keycode == 53)
		exito(mape);
	if (keycode == 13 || keycode == 126)
		up_up(mape);
	if (keycode == 0 || keycode == 123)
		left_left(mape);
	if (keycode == 1 || keycode == 125)
		down_down(mape);
	if (keycode == 2 || keycode == 124)
		right_right(mape);
	return (0);
}

int	exito(t_map_data *mape)
{
	annihilation(mape);
	free_map(mape);
	free_map1(mape);
	free(mape);
	exit(0);
}
