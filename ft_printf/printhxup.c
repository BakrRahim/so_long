/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhxup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:37:40 by brahim            #+#    #+#             */
/*   Updated: 2022/11/12 19:32:28 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhxup(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += printhxup(n / 16);
		ret += printhxup(n % 16);
	}
	else if (n <= 9)
	{
		ret += printchr(n + 48);
	}
	else
		ret += printchr(n + 55);
	return (ret);
}
