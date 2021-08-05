/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:15:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/05 14:27:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == -1)
			return (-1);
		window.map = ft_parse_map(argv[1]);
		if (!window.map)
			return (-1);
		ft_open_window(&window);
	}
	return (0);
}
