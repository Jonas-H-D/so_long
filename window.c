/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:16:21 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:32 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	ft_close ()
{
	exit(0);
}
t_window	ft_new_window(void *mlx_ptr, int width, int height, char *name)
{
	t_window	window;

	window.pointer = mlx_new_window(mlx_ptr, width, height, name);
	window.size.x = width;
	window.size.y = height;
	mlx_hook(window.pointer, 17, 0, ft_close, 0);
	return (window);
}
