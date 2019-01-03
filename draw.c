/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 01:56:13 by tmuramba          #+#    #+#             */
/*   Updated: 2018/09/18 16:00:09 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	render(t_data *z)
{
	z->x = 0;
	z->img = mlx_new_image(z->mlx, z->imagewidth, z->imageheight);
	z->imagedata = (int *)mlx_get_data_addr(z->img, &z->i, &z->j, &z->k);
	while (z->x < WIDTH)
	{
		z->camera_x = 2 * z->x / (double)WIDTH - 1;
		z->raydir_x = z->dir_x + z->plane_x * z->camera_x;
		z->raydir_y = z->dir_y + z->plane_y * z->camera_x;
		z->map_x = (int)z->pos_x;
		z->map_y = (int)z->pos_y;
		z->deltadist_x = fabs(1 / z->raydir_x);
		z->deltadist_y = fabs(1 / z->raydir_y);
		z->hit = 0;
		direction(z);
		hit(z);
		draw(z);
		z->x++;
	}
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
	mlx_destroy_image(z->mlx, (char *)z->img);
}

void	draw(t_data *z)
{
	if (z->side == 0)
		z->prepwalldist = (z->map_x - z->pos_x +
		(1 - z->step_x) / 2) / z->raydir_x;
	else
		z->prepwalldist = (z->map_y - z->pos_y +
		(1 - z->step_y) / 2) / z->raydir_y;
	z->lineheight = (int)(HEIGHT / z->prepwalldist);
	z->drawstart = -z->lineheight / 2 + HEIGHT / 2;
	if (z->drawstart < 0)
		z->drawstart = 0;
	z->drawend = z->lineheight / 2 + HEIGHT / 2;
	if (z->drawend >= HEIGHT)
		z->drawend = HEIGHT - 1;
	while (z->drawstart < z->drawend)
	{
		color(z);
		z->imagedata[(z->drawstart * z->imagewidth) + z->x] = z->colour;
		z->drawstart++;
	}
}

void	direction(t_data *z)
{
	if (z->raydir_x < 0)
	{
		z->step_x = -1;
		z->sidedist_x = (z->pos_x - z->map_x) * z->deltadist_x;
	}
	else
	{
		z->step_x = 1;
		z->sidedist_x = (z->map_x + 1.0 - z->pos_x) * z->deltadist_x;
	}
	if (z->raydir_y < 0)
	{
		z->step_y = -1;
		z->sidedist_y = (z->pos_y - z->map_y) * z->deltadist_y;
	}
	else
	{
		z->step_y = 1;
		z->sidedist_y = (z->map_y + 1.0 - z->pos_y) * z->deltadist_y;
	}
}

void	color(t_data *z)
{
	if (z->map[z->map_y][z->map_x] == 1)
		z->colour = 0x00FFFF56;
	else if (z->map[z->map_y][z->map_x] == 2)
		z->colour = 0x00FF0000;
	else if (z->map[z->map_y][z->map_x] == 3)
		z->colour = 0x0000FF00;
	else if (z->map[z->map_y][z->map_x] == 4)
		z->colour = 0x00FF15FF;
	else if (z->map[z->map_y][z->map_x] == 5)
		z->colour = 0x00264903;
	else
		z->colour = 0x00FFFFF;
}

void	hit(t_data *z)
{
	while (z->hit == 0)
	{
		if (z->sidedist_x < z->sidedist_y)
		{
			z->sidedist_x += z->deltadist_x;
			z->map_x += z->step_x;
			z->side = 0;
		}
		else
		{
			z->sidedist_y += z->deltadist_y;
			z->map_y += z->step_y;
			z->side = 1;
		}
		if (z->map[z->map_y][z->map_x] > 0)
			z->hit = 1;
	}
	put_floor(z, z->x);
}
