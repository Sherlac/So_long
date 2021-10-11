/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:23:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/11 16:21:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The height of the map = number of char * in the array */
int	count_array_height(char **array)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (array[i])
	{
		height++;
		i++;
	}
	return (height);
}

/* Check if there is at least a Start, a Coin and an Exit */
int	check_objects(t_obj *objects)
{
	if (!objects->start)
	{
		ft_putstr_fd("Error\nThere is no start on the map.\n", 2);
		return (-1);
	}
	else if (!objects->collectible)
	{
		ft_putstr_fd("Error\nThere is no collectible on the map.\n", 2);
		return (-1);
	}
	else if (!objects->exit)
	{
		ft_putstr_fd("Error\nThere is no  exit on the map.\n", 2);
		return (-1);
	}
	else
		return (0);
}

/* The last 'P' will be the start position */
void	set_player_position(t_obj *objects, int x, int i)
{
	objects->player_y = i;
	objects->player_x = x;
	objects->start += 1;
}
