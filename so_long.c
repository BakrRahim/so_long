/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:43:12 by brahim            #+#    #+#             */
/*   Updated: 2023/01/20 18:53:53 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*get_map_data(char	*name)
{
	int			fd;
	int			i;
	char		*line;
	static char	*l;
	t_map		*mapdata;

	fd = open(name, O_RDONLY);
	mapdata = malloc(sizeof(t_map));
	line = get_next_line(fd);
	if (!line)
		text_to_display("Error\n\033[1;31mFile empty !\n", 1);
	mapdata->w = (int)ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		l = ft_join(l, line);
		line = get_next_line(fd);
		i++;
	}
	mapdata->map = ft_split(l, '\n');
	mapdata->copy_e = ft_split(l, '\n');
	mapdata->copy_c = ft_split(l, '\n');
	mapdata->h = i;
	return (mapdata);
}

void	get_map_data2(t_map *map)
{
	int			i;
	int			j;

	map->coins = 0;
	map->steps = 1;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				map->coins++;
			else if (map->map[i][j] == 'P')
			{
				map->x = i;
				map->y = j;
			}
		}
	}
}

t_data	*put_data(char	*name)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	d->m = get_map_data(name);
	get_map_data2(d->m);
	check_map(d->m);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->m->w * 50, d->m->h * 50, "so_long");
	get_images(d);
	return (d);
}

void	create_map(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	if (!d->mlx && !d->win)
	{
			d->mlx = mlx_init();
		d->win = mlx_new_window(d->mlx, d->m->w * 50, d->m->h * 50, "so_long");
	}
	while (d->m->map[++i])
	{
		j = -1;
		while (d->m->map[i][++j])
		{
			mlx_put_image_to_window(d->mlx, d->win, d->e, j * 50, i * 50);
			if (d->m->map[i][j] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->wl, j * 50, i * 50);
			else if (d->m->map[i][j] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->c, j * 50, i * 50);
			else if (d->m->map[i][j] == 'P')
				mlx_put_image_to_window(d->mlx, d->win, d->pl, j * 50, i * 50);
			else if (d->m->map[i][j] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->ex, j * 50, i * 50);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		check_extension(argv[1]);
		data = put_data(argv[1]);
		create_map(data);
		mlx_hook(data->win, 17, 0, ft_exit, data);
		mlx_key_hook(data->win, key_press, data);
		mlx_loop(data->mlx);
	}
	else
		text_to_display("Error\n\033[1;31mUsage : ./so_long [MAP]\033[0m\n", 1);
}
