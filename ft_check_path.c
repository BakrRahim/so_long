/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:55:50 by brahim            #+#    #+#             */
/*   Updated: 2023/01/20 18:27:19 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path_e(char **map, int x, int y, t_map *data)
{
	if (x < 0 || y < 0 || x >= data->h
		|| y >= data->w || map[x][y] == '1')
		return ;
	map[x][y] = '1';
	check_path_e(data->copy_e, x + 1, y, data);
	check_path_e(data->copy_e, x - 1, y, data);
	check_path_e(data->copy_e, x, y + 1, data);
	check_path_e(data->copy_e, x, y - 1, data);
}

void	check_path_c(char **map, int x, int y, t_map *data)
{
	if (x < 0 || y < 0 || x >= data->h
		|| y >= data->w || map[x][y] == '1' || map[x][y] == 'E')
		return ;
	map[x][y] = '1';
	check_path_c(data->copy_c, x + 1, y, data);
	check_path_c(data->copy_c, x - 1, y, data);
	check_path_c(data->copy_c, x, y + 1, data);
	check_path_c(data->copy_c, x, y - 1, data);
}

void	check_map(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	check_chars(m->map);
	check_walls(m->map);
	check_path_e(m->copy_e, m->x, m->y, m);
	check_path_c(m->copy_c, m->x, m->y, m);
	while (m->copy_c[++i])
	{
		j = -1;
		while (m->copy_c[i][++j])
			if (m->copy_c[i][j] == 'C' || m->copy_e[i][j] == 'E')
				text_to_display("Error\n\033[1;31mInvalid path !\033[1;31m\n", 1);
	}
}
