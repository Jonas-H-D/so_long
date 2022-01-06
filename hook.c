/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:44:59 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:38 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	// mlx fct that cleans the window
	mlx_clear_window(program->mlx, program->window.pointer);
	// key direction
	if (key == 2)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 0)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 1)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 13)
		program->sprite_position.y -= program->sprite.size.y;
	mlx_put_image_to_window(program->mlx, program->window.pointer,program->sprite.pointer, program->sprite_position.x, program->sprite_position.y);
	printf("key pressed = %d\n", key);
   return (0);	
}

int	ft_update(void *param)
{
	t_program	*program = (t_program *)param;
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	 {	
		program->sprite_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.pointer, program->sprite.pointer, program->sprite_position.x, program->sprite_position.y);
	return (0);
}
