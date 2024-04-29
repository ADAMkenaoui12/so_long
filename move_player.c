/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:41:10 by kadam             #+#    #+#             */
/*   Updated: 2024/03/26 21:55:08 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_the_map(t_map *map, int x, int y)
{
	while (map->str[x] != NULL)
	{
		y = 0;
		while (map->str[x][y] != '\0')
		{
			if (map->str[x][y] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall, y
					* 50, x * 50);
			else if (map->str[x][y] == 'E')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit, y
					* 50, x * 50);
			else if (map->str[x][y] == 'P')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->player, y
					* 50, x * 50);
			else if (map->str[x][y] == 'C')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->collectible, y * 50, x * 50);
			else if (map->str[x][y] == 'M')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->player, y
					* 50, x * 50);
			y++;
		}
		x++;
	}
}

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}
	else if (keycode == 13)
		move_player_up(map);
	else if (keycode == 1)
		move_player_down(map);
	else if (keycode == 0)
		move_player_left(map);
	else if (keycode == 2)
		move_player_right(map);
	return (0);
}
