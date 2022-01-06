/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:06:56 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 18:00:38 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include "../so_long.h"

typedef struct	s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_collect;
	t_bool		b_exit;
}	t_mapcheckerdata;

char	**ft_get_map(char *file);
int		ft_valid_char(char c);
//int		ft_valid_border(char c, t_vector point, t_vector size);
int		ft_valid_file(int argc, char *file);
int		ft_valid_map(char **map);

#endif
