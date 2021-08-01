/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:53:58 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/01 17:42:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_characters(char *line, t_map_objects *map_objects)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			map_objects->space += 1;
		else if (line[i] == '1')
			map_objects->wall += 1;
		else if (line[i] == 'P')
			map_objects->start += 1;
		else if (line[i] == 'C')
			map_objects->collectible += 1;
		else if (line[i] == 'E')
			map_objects->exit += 1;
		else if (line[i] != '\n')
		{
			ft_putstr("Error\nThe map have unauthorized characters.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_firt_and_last_line(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1' && map_line[i] != '\n')
		{
			ft_putstr("Error\nThe map is not surround by walls.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_other_lines(char *map_line)
{
	int	len;

	if (map_line[0] != '1')
		return (-1);
	len = ft_strlen(map_line);
	if (map_line[len - 2] != '1')
	{
		ft_putstr("Error\nThe map is not surround by walls.\n");
		return (-1);
	}
	return (0);
}

int	ft_check_wall(char *map, int i)
{
	int	last_index;
	int	j;

	last_index = -1;
	j = 0;
	while (map[j++])
		last_index++;
	if (i == 0 || i == last_index)
	{
		if (ft_check_firt_and_last_line(map) == -1)
			return (-1);
	}
	else
	{
		if (ft_check_other_lines(map) == -1)
			return (-1);
	}
	return (0);
}

int	ft_check_map(char **map)
{
	int				i;
	t_map_objects	*map_objects;

	map_objects = malloc(sizeof(t_map_objects));
	if (!map_objects)
		return (-1);
	ft_initialize(map_objects);
	i = 0;
	while (map[i])
	{
		if (ft_check_characters(map[i], map_objects) == -1)
			return (-1);
		if (ft_check_wall(map[i], i) == -1)
			return (-1);
		i++;
	}
	if (ft_check_objects(map_objects) == -1)
		return (-1);
	return (0);
}