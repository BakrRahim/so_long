/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:28:53 by brahim            #+#    #+#             */
/*   Updated: 2023/01/19 13:18:13 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_vertical_walls(char **map, int w, int h)
{
	int	i;

	i = 0;
	while (++i <= h)
	{
		if ((map[i][0] != '1' || map[i][w - 1] != '1') || map[i][w] != '\0')
			text_to_display("Error\n\033[1;31mInvalid walls !\033[0m\n", 1);
	}
}

int	check_horizontal_walls(char	**map, int last_wall)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0' && map[last_wall][i] != '\0')
	{
		if (map[0][i] != '1' || map[last_wall][i] != '1')
			text_to_display("Error\n\033[1;31mInvalid walls !\033[0m\n", 1);
		i++;
	}
	return (i);
}

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

void	check_frequency(int p, int e, int c, int x)
{
	if (p != 1)
		text_to_display("Error\n\033[1;31mInvalid number of players !\033[0m\n", 1);
	else if (e != 1)
		text_to_display("Error\n\033[1;31mInvalid number of exits !\033[0m\n", 1);
	else if (c < 1)
		text_to_display("Error\n\033[1;31mInvalid number of coins !\033[0m\n", 1);
	else if (x > 0)
		text_to_display("Error\n\033[1;31mInvalid char in map !\033[0m\n", 1);
}

void	check_chars(char **map)
{
	int	i;
	int	j;
	int	*chars;

	i = -1;
	chars = ft_calloc(4, sizeof(int));
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				chars[0] += 1;
			else if (map[i][j] == 'E')
				chars[1] += 1;
			else if (map[i][j] == 'C')
				chars[2] += 1;
			else if (map[i][j] != 'C' && map[i][j] != 'P'
			&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E')
				chars[3] += 1;
		}
	}
	check_frequency(chars[0], chars[1], chars[2], chars[3]);
	free (chars);
}
