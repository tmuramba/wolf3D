/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 01:53:30 by tmuramba          #+#    #+#             */
/*   Updated: 2018/09/18 15:25:44 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	t_data *z;

	z = (t_data *)malloc(sizeof(t_data));
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "level1.wolf") == 0)
		{
			z->pos_x = 1.1;
			z->pos_y = 1.1;
			z->dir_x = 1;
			z->dir_y = 0;
			z->plane_x = 0;
			z->plane_y = 0.66;
			z->imagewidth = 1000;
			z->imageheight = 1000;
			getinfo(z, argv[1]);
			map_error(z);
			render(z);
			mlx_hook(z->win, 2, 0, keyhooks, z);
			mlx_hook(z->win, 17, 0, exit_wolf, z);
			mlx_loop(z->mlx);
		}
	}
	write(1, "error\n", 6);
	return (0);
}

void	getinfo(t_data *z, char *str)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	z->y = 0;
	fd = open(str, O_RDONLY);
	if (fd >= 0)
	{
		while (get_next_line(fd, &temp) > 0)
		{
			getdata(temp, z, i);
			i++;
			ft_strdel(&temp);
		}
		z->max_y = i;
		close(fd);
	}
	else
	{
		write(1, "Map Not Found\n", 14);
		exit(1);
	}
}

void	getdata(char *str, t_data *z, int i)
{
	int		j;
	int		k;
	char	**line;

	j = 0;
	k = 0;
	z->x = 0;
	line = ft_strsplit(str, ' ');
	while (line[j] != NULL)
		j++;
	z->max_x = j;
	z->max_x -= 1;
	while (k < j)
	{
		z->map[i][k] = ft_atoi(line[k]);
		k++;
	}
	while (j >= 1)
		ft_strdel(&line[--j]);
	free(line);
}

void	put_floor(t_data *z, int x)
{
	int		m;
	int		n;
	int		k;

	m = z->drawstart * WIDTH + x;
	n = z->drawend * WIDTH + x;
	k = x;
	while (k <= m)
	{
		z->imagedata[k] = 0x00565898;
		k += WIDTH;
	}
	k = (HEIGHT * WIDTH + x) - WIDTH;
	while (k >= n)
	{
		z->imagedata[k] = 0x00767953;
		k -= WIDTH;
	}
}

int		keyhooks(int key, t_data *z)
{
	z->rotspeed = 0.1;
	if (key == 53)
		exit_wolf();
	else if (key == 126)
		up(z);
	else if (key == 125)
		down(z);
	else if (key == 123)
		rot_l(z);
	else if (key == 124)
		rot_r(z);
	z->x = 0;
	mlx_clear_window(z->mlx, z->win);
	render(z);
	return (0);
}
