/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:37:37 by brahim            #+#    #+#             */
/*   Updated: 2022/11/12 19:34:11 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhex(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += printhex(n / 16);
		ret += printhex(n % 16);
	}
	else if (n <= 9)
	{
		ret += printchr(n + 48);
	}
	else
		ret += printchr(n + 87);
	return (ret);
}
