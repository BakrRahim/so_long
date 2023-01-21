/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:06:51 by brahim            #+#    #+#             */
/*   Updated: 2023/01/20 18:23:37 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *d)
{
	if (d->m->map[d->m->x][d->m->y - 1] != '1')
	{
		if (d->m->map[d->m->x][d->m->y - 1] == 'C')
			d->m->coins--;
		else if (d->m->map[d->m->x][d->m->y - 1] == 'E' && d->m->coins == 0)
			text_to_display("\033[1;32mCongrats, you won !!!\033[1;0m\n", 0);
		else if (d->m->map[d->m->x][d->m->y - 1] == 'E' && d->m->coins > 0)
		{
			ft_printf("\033[1;31mNot all coins collected !\033[0m\n");
			return ;
		}
		d->m->map[d->m->x][d->m->y] = '0';
		d->m->map[d->m->x][d->m->y - 1] = 'P';
		ft_printf("Steps made : %d\n", d->m->steps++);
		d->m->y -= 1;
		recreate(d);
	}
}

void	move_right(t_data *d)
{
	if (d->m->map[d->m->x][d->m->y + 1] != '1')
	{
		if (d->m->map[d->m->x][d->m->y + 1] == 'C')
			d->m->coins--;
		else if (d->m->map[d->m->x][d->m->y + 1] == 'E' && d->m->coins == 0)
			text_to_display("\033[1;32mCongrats, you won !!!\033[1;0m\n", 0);
		else if (d->m->map[d->m->x][d->m->y + 1] == 'E' && d->m->coins > 0)
		{
			ft_printf("\033[1;31mNot all coins collected !\033[0m\n");
			return ;
		}
		d->m->map[d->m->x][d->m->y] = '0';
		d->m->map[d->m->x][d->m->y + 1] = 'P';
		ft_printf("Steps made : %d\n", d->m->steps++);
		d->m->y += 1;
		recreate(d);
	}
}

void	move_up(t_data *d)
{
	if (d->m->map[d->m->x - 1][d->m->y] != '1')
	{
		if (d->m->map[d->m->x - 1][d->m->y] == 'C')
			d->m->coins--;
		else if (d->m->map[d->m->x - 1][d->m->y] == 'E' && d->m->coins == 0)
			text_to_display("\033[1;32mCongrats, you won !!!\033[1;0m\n", 0);
		else if (d->m->map[d->m->x - 1][d->m->y] == 'E' && d->m->coins > 0)
		{
			ft_printf("\033[1;31mNot all coins collected !\033[0m\n");
			return ;
		}
		d->m->map[d->m->x][d->m->y] = '0';
		d->m->map[d->m->x - 1][d->m->y] = 'P';
		ft_printf("Steps made : %d\n", d->m->steps++);
		d->m->x -= 1;
		recreate(d);
	}
}

void	move_down(t_data *d)
{
	if (d->m->map[d->m->x + 1][d->m->y] != '1')
	{
		if (d->m->map[d->m->x + 1][d->m->y] == 'C')
			d->m->coins--;
		else if (d->m->map[d->m->x + 1][d->m->y] == 'E' && d->m->coins == 0)
			text_to_display("\033[1;32mCongrats, you won !!!\033[1;0m\n", 0);
		else if (d->m->map[d->m->x + 1][d->m->y] == 'E' && d->m->coins > 0)
		{
			ft_printf("\033[1;31mNot all coins collected !\033[0m\n");
			return ;
		}
		d->m->map[d->m->x][d->m->y] = '0';
		d->m->map[d->m->x + 1][d->m->y] = 'P';
		ft_printf("Steps made : %d\n", d->m->steps++);
		d->m->x += 1;
		recreate(d);
	}
}

int	key_press(int key, t_data *data)
{
	if (key == 53)
		ft_exit(data);
	else if (key == 0 || key == 123)
		move_left(data);
	else if (key == 1 || key == 125)
		move_down(data);
	else if (key == 2 || key == 124)
		move_right(data);
	else if (key == 13 || key == 126)
		move_up(data);
	return (0);
}
