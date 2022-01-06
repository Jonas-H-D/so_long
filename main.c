/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:39:42 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:30 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map/map.h"

int	main(void)
{
	t_program			program;
	t_mapcheckerdata	data;
	// initialise
	program.mlx = mlx_init();
	// open a new window
	program.window = ft_new_window(program.mlx, (data.size.x * 64), (data.size.y * 64), "so_long 42");
	// create a sprite (character, collect, door...
	program.sprite = ft_new_sprite(program.mlx, "idle.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	mlx_put_image_to_window(program.mlx, program.window.pointer, program.sprite.pointer, program.sprite_position.x, program.sprite_position.y);
	// hook the key pressed event function
	mlx_key_hook(program.window.pointer, *ft_input, &program);
	// hook a function to the loop to make sure that position is cleared
	mlx_loop_hook(program.mlx, *ft_update, &program);
	// constant loop
	mlx_loop(program.mlx);
}
