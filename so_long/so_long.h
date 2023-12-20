/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 05:38:50 by mboudrio          #+#    #+#             */
/*   Updated: 2023/05/14 20:03:47 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./GET_NEXT_LINE/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct t_map_data
{
	char	**map;
	char	**raw_map;
	void	*mlx;
	void	*win;
	int		row_count;
	int		col_count;
	int		c_col_count;
	int		c_c;
	void	*door;
	void	*player;
	void	*collectible;
	void	*wall;
	void	*background;
	int		p_x;
	int		p_y;
	int		w;
	int		h;
	int		c_e;
	int		c_p;
	char	cur_char;
	int		moves;
}			t_map_data;

void		render_map_mv(t_map_data *mape);
void		paint(t_map_data *mape);
void		image_error(t_map_data *mape);
int			mouvements_p(int keycode, t_map_data *mape);
int			exito(t_map_data *mape);
void		up_up(t_map_data *mape);
void		down_down(t_map_data *mape);
void		right_right(t_map_data *mape);
void		left_left(t_map_data *mape);
int			elements_check(t_map_data *mape, char **map);
void		copie_the_map(t_map_data *mape, char *path);
int			read_check_map(t_map_data *mape);
void		path_check(int x, int y, t_map_data *mape);
int			surrounded_by_walls(t_map_data *mape, char **map);
int			strlen_nn(char *s);
int			ber_check(char *path);
int			check_the_map(t_map_data *mape);
void		print_the_map(t_map_data *mape, char **map);
void		get_map_data(t_map_data *mape, char *path);
int			allignement_check(t_map_data *mape);
void		copie_the_map1(t_map_data *mape, char *path);
void		free_map(t_map_data *mape);
void		map_ultimates0(t_map_data *mape);
void		map_ultimates1(t_map_data *mape);
void		map_ultimates2(t_map_data *mape);
void		map_ultimates4(t_map_data *mape);
void		map_ultimates5(t_map_data *mape);
void		map_ultimates6(t_map_data *mape);
void		map_ultimates(t_map_data *mape, char *path);
void		put_imagetowindow(t_map_data *mape, int i, int j);
void		up_3(t_map_data *mape);
void		down_3(t_map_data *mape);
void		left_3(t_map_data *mape);
void		right_3(t_map_data *mape);
void		map_mega_ultimates(t_map_data *mape);
void		element(t_map_data *mape, char **map);
int			walls(t_map_data *mape, char **map);
void		moves_c(t_map_data *mape);
void		annihilation(t_map_data *mape);
void		free_map1(t_map_data *mape);
void		vree(t_map_data *mape);
void		tree(t_map_data *mape, char *line);
int			check_exit(t_map_data *mape);
size_t		ft_strlen(const char *s);

#endif