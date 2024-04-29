/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:10:12 by kadam             #+#    #+#             */
/*   Updated: 2024/03/23 20:13:09 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (map->str2[x][y] == '1')
		return ;
	map->str2[x][y] = '1';
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
}

void	position_player_collectible(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->str[x] != NULL)
	{
		y = 0;
		while (map->str[x][y] != '\0')
		{
			if (map->str[x][y] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			if (map->str[x][y] == 'C')
				map->collectible_nbr++;
			y++;
		}
		x++;
	}
}
