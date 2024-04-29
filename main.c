/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:13:32 by kadam             #+#    #+#             */
/*   Updated: 2024/03/22 22:37:21 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(1);
	}
	if (check_all_map(av[1], &map) == 0)
		exit(1);
	map.fd = open(av[1], O_RDONLY);
	if (map.fd == -1)
		exit(1);
	map.str = read_all_map(&map);
	if (map.str == NULL)
		exit(1);
	initialize_map(&map);
	close(map.fd);
	return (0);
}
