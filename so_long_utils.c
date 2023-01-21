/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:23:18 by brahim            #+#    #+#             */
/*   Updated: 2023/01/20 18:27:49 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	free(data);
	exit (EXIT_SUCCESS);
}

void	text_to_display(char *text, int code)
{
	ft_printf("%s", text);
	exit(code);
}

void	check_extension(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len <= 4 || ft_strncmp(".ber", &name[len - 4], 5))
		text_to_display("Error\n\033[1;31mFilename Problem !\033[0m\n", 1);
}

void	recreate(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	create_map(data);
}
