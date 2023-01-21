/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:45:22 by brahim            #+#    #+#             */
/*   Updated: 2022/11/12 20:23:46 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list lst, int c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += printchr(va_arg(lst, int));
	else if (c == 's')
		ret += printstr(va_arg(lst, char *));
	else if (c == 'p')
	{
		ret += write (1, "0x", 2);
		ret += printaddr(va_arg(lst, unsigned long));
	}
	else if (c == 'd' || c == 'i')
		ret += printnum(va_arg(lst, int));
	else if (c == 'u')
		ret += printuns(va_arg(lst, unsigned int));
	else if (c == 'x')
		ret += printhex(va_arg(lst, unsigned int));
	else if (c == 'X')
		ret += printhxup(va_arg(lst, unsigned int));
	else if (c == '%')
		ret += printprcnt();
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		ret;
	int		i;

	va_start(list, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret += ft_format(list, format[i + 1]);
			i++;
		}
		else
		{
			ret += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(list);
	return (ret);
}
