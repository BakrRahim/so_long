/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:37:43 by brahim            #+#    #+#             */
/*   Updated: 2022/11/11 23:42:09 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnum(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n >= 10)
	{
		ret += printnum(n / 10);
		ret += printnum(n % 10);
	}
	else if (n < 0)
	{
		ret += printchr('-');
		ret += printnum(n * (-1));
	}
	else
		ret += printchr(n + 48);
	return (ret);
}
