/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:21:38 by brahim            #+#    #+#             */
/*   Updated: 2023/01/06 17:33:17 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join || !s2 || !s1)
		return (NULL);
	i = -1;
	while (s1 && s1[++i] != '\0')
		join[i] = s1[i];
	j = 0;
	while (s2 && s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	free (s1);
	free (s2);
	return (join);
}
