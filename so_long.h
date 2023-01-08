/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:13:40 by brahim            #+#    #+#             */
/*   Updated: 2023/01/06 17:31:25 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "gnl/get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL "./sprites/wall.xpm"
# define EXIT "./sprites/exit.xpm"
# define COLLECT "./sprites/collectible.xpm"
# define PLAYER "./sprites/player.xpm"
# define EMPTY "./sprites/empty.xpm"

typedef struct m_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		wi;
	int		hi;
	int		h;
	int		w;
	int		steps;
	int		p_pos[2];
	void	*wl;
	void	*e;
	void	*p;
	void	*c;
	void	*ex;
}	t_data;

char	**check_map(char *name);
char	**get_map(char *name);
void	check_vertical_walls(char **map, int width, int height);
int		check_horizontal_walls(char	**map, int last_wall);
void	check_frequency(int p, int z, int e, int c);
void	check_chars(char **map);
int		key_press(int key, t_data *map);
int		ft_exit(t_data *map);
char	*ft_join(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif