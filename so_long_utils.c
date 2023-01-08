/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:19:30 by brahim            #+#    #+#             */
/*   Updated: 2023/01/06 17:32:24 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *name)
{
	char		*line;
	static char	*map;
	char		**dmap;
	int			fd;
	int			i;

	i = 0;
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_join(map, line);
		line = get_next_line(fd);
		i++;
	}
	dmap = ft_split(map, '\n');
	free (map);
	return (dmap);
}

void	check_vertical_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (++i <= height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			write(1, "Invalid walls in map !\n", 23);
			exit (EXIT_FAILURE);
		}
	}
}

int	check_horizontal_walls(char	**map, int last_wall)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0' && map[last_wall][i] != '\0')
	{
		if (map[0][i] != '1' || map[last_wall][i] != '1')
		{
			write(1, "Invalid walls in map !\n", 23);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	return (i);
}

void	check_frequency(int p, int z, int e, int c)
{
	if (p != 1)
	{
		write(2, "Invalid number of players !\n", 28);
		exit (EXIT_FAILURE);
	}
	else if (e != 1)
	{
		write(2, "Invalid number of exits !\n", 26);
		exit (EXIT_FAILURE);
	}
	else if (c < 1)
	{
		write(2, "Invalid number of collectibles !\n", 33);
		exit (EXIT_FAILURE);
	}
	else if (z < (p + e + c))
	{
		write(2, "Empty path invalid !\n", 21);
		exit (EXIT_FAILURE);
	}
}

void	check_chars(char **map)
{	
	int	i;
	int	j;
	int	k;
	int	chars[4];

	i = -1;
	k = 0;
	while (k < 4)
		chars[k++] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				chars[0] += 1;
			else if (map[i][j] == '0')
				chars[1] += 1;
			else if (map[i][j] == 'E')
				chars[2] += 1;
			else if (map[i][j] == 'C')
				chars[3] += 1;
		}
	}
	check_frequency(chars[0], chars[1], chars[2], chars[3]);
}
