/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:36:45 by brahim            #+#    #+#             */
/*   Updated: 2023/01/06 17:27:14 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wc(char	const *s, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && j == 1)
			j = 0;
		else if (s[i] != c && j == 0)
		{
			count++;
			j = 1;
		}
		i++;
	}
	return (count);
}

static char	**fr(char	**str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		k;
	int		j;

	k = 0;
	list = (char **)malloc(sizeof(char *) * (wc(s, c) + 1));
	if (!s || !list)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j > 0)
		{
			list[k] = ft_substr(s, 0, j);
			if (!list[k++])
				return (fr(list));
		}
		s = s + j;
	}
	list[k] = NULL;
	return (list);
}
