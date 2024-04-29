/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_left_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:55:48 by kadam             #+#    #+#             */
/*   Updated: 2024/03/24 00:21:06 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	for_exit_right(t_map *map)
{
	map->str[map->player_x][map->player_y] = '0';
	if (map->collectible_nbr == 0)
	{
		map->player_y += 1;
		map->str[map->player_x][map->player_y] = 'P';
		ft_print_moves(map);
		mlx_clear_window(map->mlx, map->mlx_win);
		exit(0);
	}
	else if (map->collectible_nbr != 0)
	{
		if (map->str[map->player_x][map->player_y + 2] != '1')
		{
			map->player_y += 1;
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
			map->str[map->player_x][map->player_y] = 'M';
			ft_print_moves(map);
			draw_the_map(map, 0, 0);
		}
	}
}

void	move_player_right(t_map *map)
{
	if (map->str[map->player_x][map->player_y + 1] != '1'
		&& map->str[map->player_x][map->player_y + 1] != 'E')
		ft_print_moves(map);
	if (map->str[map->player_x][map->player_y + 1] == '0'
		|| map->str[map->player_x][map->player_y + 1] == 'C')
	{
		if (map->str[map->player_x][map->player_y] == 'M')
		{
			map->str[map->player_x][map->player_y] = 'E';
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
		}
		else
			map->str[map->player_x][map->player_y] = '0';
		map->player_y += 1;
		if (map->str[map->player_x][map->player_y] == 'C')
			map->collectible_nbr--;
		map->str[map->player_x][map->player_y] = 'P';
		mlx_clear_window(map->mlx, map->mlx_win);
		draw_the_map(map, 0, 0);
	}
	else if (map->str[map->player_x][map->player_y + 1] == 'E')
		for_exit_right(map);
}

static void	for_exit_left(t_map *map)
{
	map->str[map->player_x][map->player_y] = '0';
	if (map->collectible_nbr == 0)
	{
		map->player_y -= 1;
		map->str[map->player_x][map->player_y] = 'P';
		ft_print_moves(map);
		mlx_clear_window(map->mlx, map->mlx_win);
		exit(0);
	}
	else if (map->collectible_nbr != 0)
	{
		if (map->str[map->player_x][map->player_y - 2] != '1')
		{
			map->player_y -= 1;
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
			map->str[map->player_x][map->player_y] = 'M';
			ft_print_moves(map);
			draw_the_map(map, 0, 0);
		}
	}
}

void	move_player_left(t_map *map)
{
	if (map->str[map->player_x][map->player_y - 1] != '1'
		&& map->str[map->player_x][map->player_y - 1] != 'E')
		ft_print_moves(map);
	if (map->str[map->player_x][map->player_y - 1] == '0'
		|| map->str[map->player_x][map->player_y - 1] == 'C')
	{
		if (map->str[map->player_x][map->player_y] == 'M')
		{
			map->str[map->player_x][map->player_y] = 'E';
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
		}
		else
			map->str[map->player_x][map->player_y] = '0';
		map->player_y -= 1;
		if (map->str[map->player_x][map->player_y] == 'C')
			map->collectible_nbr--;
		map->str[map->player_x][map->player_y] = 'P';
		mlx_clear_window(map->mlx, map->mlx_win);
		draw_the_map(map, 0, 0);
	}
	else if (map->str[map->player_x][map->player_y - 1] == 'E')
		for_exit_left(map);
}
