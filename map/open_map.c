/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:15:40 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 18:00:39 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/gnl.h"
#include "map.h"
#include <fcntl.h>

int	ft_file_linecount(char *file)
{
	int		read_bytes;
	int		fd;
	int		linecount;
	char	c;

	fd = open (file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (fd)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 1)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close (fd);
	return (linecount);
}

char	**ft_alloc_lines(char *file)
{
	char	**map;
	int		linecount;

	linecount = ft_file_linecount(file);
	if (linecount <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * linecount + 1);
	if (map == NULL)
		return (null_error("malloc error on ft_alloc_lines"));
	return (map);
}

char	**ft_get_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	map = ft_alloc_lines(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	printf("fd = %d\n", fd);
	while (fd)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
//	map[i] = NULL;
	close (fd);
	return (map);
}

int    main(int argc, char **argv)
{
	char    **map;
	int     y;
	int		x;

	if (!ft_valid_file(argc, argv[1]))
		return (0);
	printf("map file  is valid\n");
	map = ft_get_map(argv[1]);
	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		printf("%s", map[y]);
		y++;
	}
	y = 0;
	printf("-------------------\n");
	while (map[y])
	{
		while (map[y][x])
		{
			if (ft_valid_char(map[y][x]))
				printf("%c", map[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
	if (ft_valid_map(map) == 1)
		printf("Valid map, Well Done \n");
	else 
		printf("non valid map \n");
	free (map);
    return (0);
}
