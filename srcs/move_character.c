/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:41:58 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/08 16:30:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if we have all the coins, if so print a message and exit() */
int	exit_finish(t_window *wind)
{
	if (wind->obj.collected / wind->obj.collectible == 1)
	{
		if (wind->obj.collected % wind->obj.collectible == 0)
		{
			printf("Congratualations ! You finished this level ");
			printf("in %d moves and collected ", wind->obj.mvmt);
			if (wind->obj.collected > 1)
				printf("the %d collectibles !\n", wind->obj.collected);
			else
				printf("the collectible !\n");
			exit(EXIT_SUCCESS);
		}
	}
	return (-1);
}

/* If we can't move : return
 * If we are on a coin, collect it ;
 * If we have all the coins and we are on exit : finish ;
 * Else : we can move to the next position, move. */
int	move_forward(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x - 1][wind->obj.player_y] != '1')
	{
		if (wind->map[wind->obj.player_x - 1][wind->obj.player_y] == 'E')
			if (exit_finish(wind) == -1)
				return (key);
		wind->obj.mvmt++;
		wind->obj.player_x -= 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x + 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d ", wind->obj.collected, wind->obj.collectible);
			printf("collected\n");
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
			exit_finish(wind);
		else
		{
			wind->map[wind->obj.player_x + 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Top\n", wind->obj.mvmt);
	}
	return (key);
}

int	turn_left(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x][wind->obj.player_y - 1] != '1')
	{
		if (wind->map[wind->obj.player_x][wind->obj.player_y - 1] == 'E')
			if (exit_finish(wind) == -1)
				return (key);
		wind->obj.mvmt++;
		wind->obj.player_y -= 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x][wind->obj.player_y + 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d ", wind->obj.collected, wind->obj.collectible);
			printf("collected\n");
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
			exit_finish(wind);
		else
		{
			wind->map[wind->obj.player_x][wind->obj.player_y + 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Left\n", wind->obj.mvmt);
	}
	return (key);
}

int	move_back(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x + 1][wind->obj.player_y] != '1')
	{
		if (wind->map[wind->obj.player_x + 1][wind->obj.player_y] == 'E')
			if (exit_finish(wind) == -1)
				return (key);
		wind->obj.mvmt++;
		wind->obj.player_x += 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x - 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d ", wind->obj.collected, wind->obj.collectible);
			printf("collected\n");
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
			exit_finish(wind);
		else
		{
			wind->map[wind->obj.player_x - 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Back\n", wind->obj.mvmt);
	}
	return (key);
}

int	turn_right(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x][wind->obj.player_y + 1] != '1')
	{
		if (wind->map[wind->obj.player_x][wind->obj.player_y + 1] == 'E')
			if (exit_finish(wind) == -1)
				return (key);
		wind->obj.mvmt++;
		wind->obj.player_y += 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x][wind->obj.player_y - 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d ", wind->obj.collected, wind->obj.collectible);
			printf("collected\n");
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
			exit_finish(wind);
		else
		{
			wind->map[wind->obj.player_x][wind->obj.player_y - 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Right\n", wind->obj.mvmt);
	}
	return (key);
}