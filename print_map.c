/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:06:02 by kadam             #+#    #+#             */
/*   Updated: 2024/03/24 00:14:35 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, int x)
{
	int	i;

	i = 0;
	if (x == 2)
	{
		while (map->str2[i] != NULL)
		{
			free(map->str2[i]);
			i++;
		}
		free(map->str2);
		map->str2 = NULL;
	}
	else if (x == 1)
	{
		while (map->str[i] != NULL)
		{
			free(map->str[i]);
			i++;
		}
		free(map->str);
		map->str = NULL;
	}
}

static int	check_flood_fill(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->str2[x] != NULL)
	{
		y = 0;
		while (map->str2[x][y] != '\0')
		{
			if (map->str2[x][y] == 'E' || map->str2[x][y] == 'P'
				|| map->str2[x][y] == 'C')
			{
				ft_putstr_fd("Error\nInvalid map C P E\n", 2);
				free_map(map, 2);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

static void	create_clone_map(t_map *map)
{
	int	i;

	i = 0;
	map->str2 = (char **)ft_calloc(map->vertical + 1, sizeof(char *));
	if (map->str2 == NULL)
		exit(1);
	while (map->str[i] != NULL)
	{
		map->str2[i] = ft_strdup(map->str[i]);
		i++;
	}
	position_player_collectible(map);
	flood_fill(map, map->player_x, map->player_y);
	if (check_flood_fill(map) == 0)
		exit(1);
}

static void	xpm_to_img(t_map *map)
{
	map->player = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm",
			&map->width, &map->height);
	map->collectible = mlx_xpm_file_to_image(map->mlx, "./img/collectible.xpm",
			&map->width, &map->height);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm", &map->width,
			&map->height);
	map->wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &map->width,
			&map->height);
	if (map->player == NULL || map->collectible == NULL || map->exit == NULL
		|| map->wall == NULL)
		exit(1);
}

void	initialize_map(t_map *map)
{
	create_clone_map(map);
	free_map(map, 2);
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		exit(1);
	map->width = map->horizontal * 50;
	map->height = map->vertical * 50;
	if (map->vertical >= 164 || map->horizontal >= 164)
	{
		ft_putstr_fd("Error\nInvalid map : too many lines\n", 2);
		exit(1);
	}
	map->mlx_win = mlx_new_window(map->mlx, map->width, map->height,
			"My So_long");
	if (map->mlx_win == NULL)
		exit(1);
	xpm_to_img(map);
	draw_the_map(map, 0, 0);
	mlx_hook(map->mlx_win, 17, 0, close_window, map);
	mlx_key_hook(map->mlx_win, key_hook, map);
	mlx_loop(map->mlx);
}
