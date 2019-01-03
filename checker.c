/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:16:36 by tmuramba          #+#    #+#             */
/*   Updated: 2018/09/18 15:09:05 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	map_error(t_data *z)
{
	if (z->map[0][0] == '\0')
	{
		ft_putstr("Invalid Map\n");
		exit(1);
	}
	if (z->map[1][1] != 0)
	{
		ft_putstr("Check Starting Position\n");
		exit(1);
	}
	borders(z);
}

void	do_stuff(void)
{
	ft_putstr("Invalid Map\n");
	exit(0);
}

void	borders(t_data *z)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= z->max_x)
	{
		if (z->map[y][x] >= 1)
			x++;
		else
			do_stuff();
	}
	while (y < z->max_y)
	{
		if (z->map[y][x - 1] != 0)
			y++;
		else
			do_stuff();
	}
	edge(z);
}

void	edge(t_data *z)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < z->max_y)
	{
		if (z->map[y][x] != 0)
			y++;
		else
			do_stuff();
	}
	while (x <= z->max_x)
	{
		if (z->map[y - 1][x] != 0)
			x++;
		else
			do_stuff();
	}
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, HEIGHT, WIDTH, "wolf_3d");
}

int		exit_wolf(void)
{
	exit(1);
}
