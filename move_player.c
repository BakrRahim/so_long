/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 01:40:14 by brahim            #+#    #+#             */
/*   Updated: 2023/01/05 02:49:47 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_a(t_data *m)
{
	if (m->map[m->p_pos[1]][m->p_pos[0] - 1] != '1')
	{
		m->map[m->p_pos[1]][m->p_pos[0]] = '0';
		m->map[m->p_pos[1]][m->p_pos[0] - 1] = 'P';
		m->p_pos[0] -= 1;
		printf("Steps :%d\n", ++m->steps);
	}
}

void	move_s(t_data *m)
{
	if (m->map[m->p_pos[1] + 1][m->p_pos[0]] != '1')
	{
		m->map[m->p_pos[1]][m->p_pos[0]] = '0';
		m->map[m->p_pos[1] + 1][m->p_pos[0]] = 'P';
		m->p_pos[0] -= 1;
		printf("Steps :%d\n", ++m->steps);
	}
}

void	move_w(t_data *m)
{
	if (m->map[m->p_pos[1] - 1][m->p_pos[0]] != '1')
	{
		m->map[m->p_pos[1]][m->p_pos[0]] = '0';
		m->map[m->p_pos[1] - 1][m->p_pos[0]] = 'P';
		m->p_pos[0] -= 1;
		printf("Steps :%d\n", ++m->steps);
	}
}

void	move_d(t_data *m)
{
	if (m->map[m->p_pos[1]][m->p_pos[0] + 1] != '1')
	{
		m->map[m->p_pos[1]][m->p_pos[0]] = '0';
		m->map[m->p_pos[1]][m->p_pos[0] + 1] = 'P';
		m->p_pos[0] -= 1;
		printf("Steps :%d\n", ++m->steps);
	}
}

int	key_press(int key, t_data *map)
{
	if (key == 53)
		ft_exit(map);
	else if (key == 0)
		move_a(map);
	else if (key == 1)
		move_s(map);
	else if (key == 2)
		move_d(map);
	else if (key == 13)
		move_w(map);
	return (0);
}
