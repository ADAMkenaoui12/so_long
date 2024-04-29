/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_up_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:44:01 by kadam             #+#    #+#             */
/*   Updated: 2024/03/24 00:22:33 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	for_exit_up(t_map *map)
{
	map->str[map->player_x][map->player_y] = '0';
	if (map->collectible_nbr == 0)
	{
		map->player_x -= 1;
		map->str[map->player_x][map->player_y] = 'P';
		ft_print_moves(map);
		mlx_clear_window(map->mlx, map->mlx_win);
		exit(0);
	}
	else if (map->collectible_nbr != 0)
	{
		if (map->str[map->player_x - 2][map->player_y] != '1')
		{
			map->player_x -= 1;
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
			map->str[map->player_x][map->player_y] = 'M';
			ft_print_moves(map);
			draw_the_map(map, 0, 0);
		}
	}
}

void	move_player_up(t_map *map)
{
	if (map->str[map->player_x - 1][map->player_y] != '1'
		&& map->str[map->player_x - 1][map->player_y] != 'E')
		ft_print_moves(map);
	if (map->str[map->player_x - 1][map->player_y] == '0'
		|| map->str[map->player_x - 1][map->player_y] == 'C')
	{
		if (map->str[map->player_x][map->player_y] == 'M')
		{
			map->str[map->player_x][map->player_y] = 'E';
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
		}
		else
			map->str[map->player_x][map->player_y] = '0';
		map->player_x -= 1;
		if (map->str[map->player_x][map->player_y] == 'C')
			map->collectible_nbr--;
		map->str[map->player_x][map->player_y] = 'P';
		mlx_clear_window(map->mlx, map->mlx_win);
		draw_the_map(map, 0, 0);
	}
	else if (map->str[map->player_x - 1][map->player_y] == 'E')
		for_exit_up(map);
}

static void	for_exit_down(t_map *map)
{
	map->str[map->player_x][map->player_y] = '0';
	if (map->collectible_nbr == 0)
	{
		map->player_x += 1;
		map->str[map->player_x][map->player_y] = 'P';
		ft_print_moves(map);
		mlx_clear_window(map->mlx, map->mlx_win);
		exit(0);
	}
	else if (map->collectible_nbr != 0)
	{
		if (map->str[map->player_x + 2][map->player_y] != '1')
		{
			map->player_x += 1;
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
			map->str[map->player_x][map->player_y] = 'M';
			ft_print_moves(map);
			draw_the_map(map, 0, 0);
		}
	}
}

void	move_player_down(t_map *map)
{
	if (map->str[map->player_x + 1][map->player_y] != '1'
		&& map->str[map->player_x + 1][map->player_y] != 'E')
		ft_print_moves(map);
	if (map->str[map->player_x + 1][map->player_y] == '0'
		|| map->str[map->player_x + 1][map->player_y] == 'C')
	{
		if (map->str[map->player_x][map->player_y] == 'M')
		{
			map->str[map->player_x][map->player_y] = 'E';
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_the_map(map, 0, 0);
		}
		else
			map->str[map->player_x][map->player_y] = '0';
		map->player_x += 1;
		if (map->str[map->player_x][map->player_y] == 'C')
			map->collectible_nbr--;
		map->str[map->player_x][map->player_y] = 'P';
		mlx_clear_window(map->mlx, map->mlx_win);
		draw_the_map(map, 0, 0);
	}
	else if (map->str[map->player_x + 1][map->player_y] == 'E')
		for_exit_down(map);
}
