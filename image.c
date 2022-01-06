/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:45:43 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:35 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// creates an image with the sprite found in path .xpm

t_image	ft_new_sprite(void *mlx_ptr, char *path)
{
	t_image	image;

	image.pointer = mlx_xpm_file_to_image(mlx_ptr, path, &image.size.x, &image.size.y);
	return (image);  
}
