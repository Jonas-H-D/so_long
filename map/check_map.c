/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:21:22 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 18:00:40 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../so_long.h"
#include "../gnl/gnl.h"


int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);

	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}
int	ft_valid_file(int argc, char *file)
{
	if (argc == 1)
		return (0);
	if (argc > 2)
		return (0);
	if (!ft_strend_cmp(file, ".ber"))
		return (0);
	return (1);
}

int ft_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' 
		|| c == 'P' || c == '\n')
		return (1);
	return (0);
}

int	ft_table_linecount(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);

}

int	ft_border_check(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0 
		|| point.y  == size.y || point.x == size.x)
		if (c != '1')
			return (error("border not valid"));
//	printf("*** valid border with c = %c point.y = %d, point.x = %d\n", c, point.y, point.x);
	return (1);

}

int	ft_uniq_char(char c, t_bool *bool)
{
	if (c == 'P' && *bool == FALSE)
		*bool = TRUE;
	else if (c == 'P' && *bool == TRUE)
		return (error("char is not unique"));
	return (1);
}
static t_mapcheckerdata	init_data_check(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_table_linecount(map);
	data.point.x = 0;
	data.point.y = 0;
	data.b_player = FALSE;
	data.b_collect = FALSE;
	data.b_exit = FALSE;
	return (data);
}

// check every tile and return false if any error is found
// to do = personalise error messages
int	ft_checks(char c, t_mapcheckerdata *data)
{
//	printf("ft_checked char is ==== %c\n", c);
	if (!ft_valid_char(c))
		return (error("non valid char"));
	if (!ft_uniq_char(c, &data->b_player))
		return (error("non unique P"));
	if (c == 'E')
		printf("found a E*******************\n");
		data->b_exit = TRUE;
	if (c == 'C')
		printf("found a C*********************\n");
		data->b_collect = TRUE;
	if (!ft_border_check(c, data->point, data->size))
		return (error("border not valid"));
//	printf("this was a valid char !!! *** !!!!\n");
	return (1);
}

// returns true if the map is valid
int	ft_valid_map(char **map)
{
	t_mapcheckerdata	data;
	int					size_x;

	data = init_data_check(map);
//	valid = TRUE;
//	printf("len of data.point.y = %zu, ", ft_strlen(map[data.point.y]));
//	printf("point.x = %zu\n", ft_strlen(map[data.point.x]));
//	printf("size of data.size.x = %d, size.y = %d\n", data.size.x, data.size.y);
	while (map[data.point.y])
	{
		// check if map is rectangular
		if (ft_strlen(map[data.point.y]) != data.size.x)
			return(error("map should be a rectangle"));
		data.point.x = 0;
//		printf("--------------- data.point.x = %d\n", data.point.x);
		while (map[data.point.y][data.point.x] && data.point.x <= data.size.x - 2)
		{
			if (ft_checks(map[data.point.y][data.point.x], &data) == FALSE)
				return (error("ft_checks is false"));
			data.point.x++;
		}
		data.point.y++;
	}
	printf("player %d, exit %d, collect %d\n", data.b_player, data.b_exit, data.b_collect);
	if (data.b_player == 0 || data.b_exit == 0 
		|| data.b_collect == 0)
//		printf("data not valid\n");
//		size_x = (data.size.y);
//		printf("point.y = %d size.y = %d\n", data.point.y, size_x);
		return (error("player, exit, collect not TRUE"));
	return (1);
}
