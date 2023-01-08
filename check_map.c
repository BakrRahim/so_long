/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:16:00 by brahim            #+#    #+#             */
/*   Updated: 2023/01/05 15:31:55 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = check_horizontal_walls(map, i - 1);
	check_vertical_walls(map, j, i - 2);
	return (0);
}

char	**check_elements(char *name)
{
	char	**map;

	map = get_map(name);
	check_walls(map);
	check_chars(map);
	return (map);
}

int	check_name(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (len > 4 && ft_strncmp(&name[len - 4], ".ber", 4) == 0)
		return (0);
	write (2, "Invalid file !\n", 15);
	exit (EXIT_FAILURE);
}

char	**check_map(char *name)
{
	char	**map;

	check_name(name);
	map = check_elements(name);
	return (map);
}
