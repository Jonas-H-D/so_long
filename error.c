/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:48:59 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:40 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// returns 0 and prints error message in red
int	error(char *message)
{
	printf("\033[0;31m" " Error\n    %s\n" 
			"\033[0m", message);
	return (0);
}

// returns NULL and print error message
void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" 
			"\033[0m", message);
	return (NULL);
}
