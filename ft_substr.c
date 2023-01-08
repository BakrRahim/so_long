/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:57:41 by brahim            #+#    #+#             */
/*   Updated: 2023/01/06 17:33:11 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	slen = ft_strlen((char *)s);
	if (len > slen)
		len = slen;
	if (start >= slen)
		return (ft_calloc(1, 1));
	if (len + start > slen)
		sub = (char *)malloc(sizeof(char) * (slen - start) + 1);
	else
		sub = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (!sub)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
