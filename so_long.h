/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:43:25 by brahim            #+#    #+#             */
/*   Updated: 2023/01/21 15:56:21 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

# define WALL "sprites/wall.xpm"
# define EMPTY "sprites/empty.xpm"
# define COIN "sprites/coin.xpm"
# define EXIT "sprites/exit.xpm"
# define PLAYER "sprites/player.xpm"

typedef struct map
{
	char	**map;
	char	**copy_e;
	char	**copy_c;
	int		x;
	int		y;
	int		coins;
	int		steps;
	int		w;
	int		h;
}	t_map;

typedef struct data
{
	void		*mlx;
	void		*win;
	void		*wl;
	void		*e;
	void		*c;
	void		*ex;
	void		*pl;
	int			h;
	int			w;
	t_map		*m;
}	t_data;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	text_to_display(char *text, int code);
char	**ft_split(char const *s, char c);
char	*ft_join(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	check_chars(char **map);
int		check_walls(char **map);
void	check_path_e(char **map, int x, int y, t_map *data);
void	check_path_c(char **map, int x, int y, t_map *data);
int		key_press(int key, t_data *data);
int		ft_exit(t_data *data);
void	recreate(t_data *data);
void	create_map(t_data *d);
void	check_map(t_map *m);
void	get_images(t_data *data);
void	check_extension(char *name);
#endif