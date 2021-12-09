/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:59:13 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/09 18:16:54 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
//	void	*pix_ptr;
	int		a;
	int		b;
	int	c;
	int	d;

	a = 100;
	b = 100;
	c = 200;
	d = 200;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "game 42");
	while (a < 200)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a++, b, 0xFFFFFF);
//		mlx_pixel_put(mlx_ptr, win_ptr, c++, d++, 0xFFFFFF);
	}
	while (b < 200)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a, b++, 0x34eb9e);
//		mlx_pixel_put(mlx_ptr, win_ptr, c++, d++, 0xFFFFFF);
	}

	while (a > 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a--, b--, 0x3380ff);
	}
	b = 200;
	while (b > 100)
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, a, b--, 0xFFFFFF);
	}
	b = 200;
	while (c > 100)
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, c--, b, 0xFFFFFF);
	}
	mlx_loop(mlx_ptr);
}
