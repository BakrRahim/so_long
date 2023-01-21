/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:25:37 by brahim            #+#    #+#             */
/*   Updated: 2023/01/20 18:55:29 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	ret = malloc(size * count);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * count);
	return (ret);
}

void	get_images(t_data *data)
{
	data->pl = mlx_xpm_file_to_image(data->mlx, PLAYER, &data->w, &data->h);
	data->wl = mlx_xpm_file_to_image(data->mlx, WALL, &data->w, &data->h);
	data->e = mlx_xpm_file_to_image(data->mlx, EMPTY, &data->w, &data->h);
	data->c = mlx_xpm_file_to_image(data->mlx, COIN, &data->w, &data->h);
	data->ex = mlx_xpm_file_to_image(data->mlx, EXIT, &data->w, &data->h);
	if (!data->pl || !data->wl || !data->e
		|| !data->c || !data->ex)
		text_to_display("Error\n\033[1;31mCorrupt XPM file !\033[0m\n", 1);
}

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
