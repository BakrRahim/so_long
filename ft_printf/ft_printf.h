/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:48:37 by brahim            #+#    #+#             */
/*   Updated: 2022/11/12 19:24:35 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	printchr(int c);
int	printstr(char *str);
int	printhex(unsigned int n);
int	printhxup(unsigned int n);
int	printnum(int num);
int	printuns(unsigned int n);
int	printprcnt(void);
int	printaddr(unsigned long n);

#endif
