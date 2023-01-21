/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:34:51 by brahim            #+#    #+#             */
/*   Updated: 2022/11/12 19:32:14 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printuns(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
	{
		ret += printuns(n / 10);
		ret += printuns(n % 10);
	}
	else
		ret += printchr(n + 48);
	return (ret);
}
