/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:37:14 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 18:26:36 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../so_long.h"

// allocate memory to save a tile map with same size as map
t_tile	**alloc_tilemap(char *map)
{
	t_tile				**tilemap;
	t_mapcheckerdata	data;
	int					i;

	tilemap = malloc(sizeof(t_tile *) * data.size.y + 1);
	if (!tilemap)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile *) * data.size.x);
		if (tilemap == NULL)
		{
			while (i > 0)
				free(tilemap[--i]);
			return (NULL);
		}
		i++;
	}
	return (tilemap)
}

// returns the tilemap that correspond to definer
t_tiletype	define_tiletype(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == 'C')
		return (COLLECTABLE);
	if (definer == 'E')
		return (EXIT);
	else if (definer == 'P')
		return (PLAYER);
	return (EMPTY);
}

// sets the size, original type and neighboors of the x, y tile of tilemap

void	set_up(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].type;
	tilemap[y][x].position.x = x * IMG_SIZE;
	tilemap[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		tilemap[y][x] = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

// add info to the game struct
void	set_gamevars(t_tile *tile, t_game *game, char c)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == COLLECTABLE)
		game->collects++;
}

// returns a t_tile table filled according to map;
// each line ends in a tile of type 0,
// coloumns ends in a NULL pointer
t_tile **generate_tilemap(char **map, t_game *game)
{
	t_tile	**tilemap;
	int		x;
	int		y;

	tilemap = alloc_tilemap(map);
	if (!tilemap)
		return (null_error("malloc error on alloc_tilemap"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != 0)
		{
			tilemap[y][x].type = define_tiletype(map[y][x]);
			setup_tile(tilemap, x, y);
			set_gamevars(&tilemap[y][x], game, map[y][x]);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	game->wndw_size.x = x * IMG_SIZE;
	game->wndw_size.y = y * IMG_SIZE;
	return (tilemap);
}
