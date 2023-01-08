/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:12:20 by brahim            #+#    #+#             */
/*   Updated: 2023/01/08 14:04:48 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *map)
{
	free (map->map);
	(void)map;
	exit (EXIT_SUCCESS);
}

t_data	put_data(char	**map)
{
	int		i;
	t_data	mapd;

	i = 0;
	while (map[i])
		i++;
	mapd.map = map;
	mapd.p_pos[0] = 0;
	mapd.p_pos[1] = 0;
	mapd.steps = 0;
	mapd.mlx = mlx_init();
	mapd.w = ft_strlen(map[0]);
	mapd.h = i;
	mapd.win = mlx_new_window(mapd.mlx, mapd.w * 50, mapd.h * 50, "so_long");
	mapd.wl = mlx_xpm_file_to_image(mapd.mlx, WALL, &mapd.wi, &mapd.hi);
	mapd.e = mlx_xpm_file_to_image(mapd.mlx, EMPTY, &mapd.wi, &mapd.hi);
	mapd.p = mlx_xpm_file_to_image(mapd.mlx, PLAYER, &mapd.wi, &mapd.hi);
	mapd.c = mlx_xpm_file_to_image(mapd.mlx, COLLECT, &mapd.wi, &mapd.hi);
	mapd.ex = mlx_xpm_file_to_image(mapd.mlx, EXIT, &mapd.wi, &mapd.hi);
	if (!mapd.wl || !mapd.e || !mapd.p || !mapd.c || !mapd.ex)
	{
		write(2, "Invalid xpm file !\n", 19);
		exit(EXIT_FAILURE);
	}
	return (mapd);
}

int	create_map(t_data *m)
{
	int	i;
	int	j;

	j = -1;
	while (m->map[++j])
	{
		i = -1;
		while (m->map[j][++i])
		{
			mlx_put_image_to_window(m->mlx, m->win, m->e, i * 50, j * 50);
			if (m->map[j][i] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->wl, i * 50, j * 50);
			else if (m->map[j][i] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->c, i * 50, j * 50);
			else if (m->map[j][i] == 'P')
			{
				mlx_put_image_to_window(m->mlx, m->win, m->p, i * 50, j * 50);
				m->p_pos[0] = i;
				m->p_pos[1] = j;
			}
			else if (m->map[j][i] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->ex, i * 50, j * 50);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_data	map_d;

	if (argc == 2)
	{
		map = check_map(argv[1]);
		map_d = put_data(map);
		create_map(&map_d);
		mlx_hook(map_d.win, 17, 0, ft_exit, &map_d);
		mlx_key_hook(map_d.win, key_press, &map_d);
		mlx_loop_hook(map_d.mlx, create_map, &map_d);
		mlx_loop(map_d.mlx);
	}
	else
	{
		write(2, "Invalid number of arguments !", 29);
		exit (EXIT_FAILURE);
	}
}
