/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 02:42:53 by tmuramba          #+#    #+#             */
/*   Updated: 2018/09/14 11:43:28 by tmuramba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rot_l(t_data *z)
{
	z->old_dir_x = z->dir_x;
	z->dir_x = z->dir_x * cos(-z->rotspeed) - z->dir_y * sin(-z->rotspeed);
	z->dir_y = z->old_dir_x * sin(-z->rotspeed) + z->dir_y * cos(-z->rotspeed);
	z->old_plane_x = z->plane_x;
	z->plane_x = z->plane_x * cos(-z->rotspeed) -
	z->plane_y * sin(-z->rotspeed);
	z->plane_y = z->old_plane_x * sin(-z->rotspeed) +
	z->plane_y * cos(-z->rotspeed);
}

void	rot_r(t_data *z)
{
	z->old_dir_x = z->dir_x;
	z->dir_x = z->dir_x * cos(z->rotspeed) - z->dir_y * sin(z->rotspeed);
	z->dir_y = z->old_dir_x * sin(z->rotspeed) + z->dir_y * cos(z->rotspeed);
	z->old_plane_x = z->plane_x;
	z->plane_x = z->plane_x * cos(z->rotspeed) -
	z->plane_y * sin(z->rotspeed);
	z->plane_y = z->old_plane_x * sin(z->rotspeed) +
	z->plane_y * cos(z->rotspeed);
}

void	up(t_data *z)
{
	if (z->map[(int)(z->pos_y)][(int)(z->pos_x + z->dir_x)] == 0)
		z->pos_x += z->dir_x;
	if (z->map[(int)(z->pos_y + z->dir_y)][(int)(z->pos_x)] == 0)
		z->pos_y += z->dir_y;
}

void	down(t_data *z)
{
	if (z->map[(int)(z->pos_y)][(int)(z->pos_x - z->dir_x)] == 0)
		z->pos_x -= z->dir_x;
	if (z->map[(int)(z->pos_y - z->dir_y)][(int)(z->pos_x)] == 0)
		z->pos_y -= z->dir_y;
}
