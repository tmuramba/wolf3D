/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:13:13 by tmuramba          #+#    #+#             */
/*   Updated: 2018/09/18 14:52:29 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# define HEIGHT 1000
# define WIDTH 1000
# include "./libft/libft.h"
# include "get_next_line.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		x;
	double	w;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	prepwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		h;
	int		drawstart;
	int		drawend;
	int		colour;
	int		i;
	int		k;
	int		j;
	int		max_x;
	int		max_y;
	double	old_dir_x;
	double	old_plane_x;
	int		imagewidth;
	int		imageheight;
	int		*imagedata;
	int		y;
	char	*mapinfo;
	int		map[4096][4096];
	double	rotspeed;
}				t_data;

void			render(t_data *z);
int				keyhooks(int key, t_data *z);
void			getinfo(t_data *z, char *str);
void			color(t_data *z);
void			draw(t_data *z);
void			getdata(char *str, t_data *z, int i);
void			direction(t_data *z);
void			hit(t_data *z);
void			put_floor(t_data *z, int x);
void			rot_l(t_data *z);
void			rot_r(t_data *z);
void			up(t_data *z);
void			down(t_data *z);
void			map_error(t_data *z);
void			borders(t_data *z);
void			edge(t_data *z);
void			do_stuff(void);
int				exit_wolf(void);
#endif
