/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:03:15 by brahim            #+#    #+#             */
/*   Updated: 2023/01/08 14:03:40 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	ret = malloc(size * count);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * count);
	return (ret);
}
