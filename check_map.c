/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:10:32 by kadam             #+#    #+#             */
/*   Updated: 2024/03/24 00:16:36 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	normine(char **line, char **ptr_line, t_map *map)
{
	*line = get_next_line(map->fd);
	*ptr_line = ft_strdup("");
	if (*line == NULL)
	{
		ft_putstr_fd("Error\nInvalid file : empty file\n", 2);
		free(*ptr_line);
		exit(1);
	}
	if (*ptr_line == NULL)
		return ;
	map->horizontal = ft_strlen(*line) - 1;
	map->vertical = 0;
}

char	**read_all_map(t_map *map)
{
	char	*line;
	char	*tmp;
	char	*ptr_line;
	char	*tmp1;

	normine(&line, &ptr_line, map);
	while (line != NULL)
	{
		if (line[0] == '\n')
			return (free(line), free(ptr_line), NULL);
		tmp = ft_strjoin(ptr_line, line);
		if (tmp == NULL)
			return (free(line), free(ptr_line), NULL);
		tmp1 = line;
		line = get_next_line(map->fd);
		free(tmp1);
		free(ptr_line);
		ptr_line = tmp;
		map->vertical++;
	}
	map->str = ft_split(ptr_line, '\n');
	free(ptr_line);
	if (map->str == NULL)
		return (NULL);
	return (map->str);
}

static int	check_help(char *av, t_map *map)
{
	map->fd = open(av, O_RDONLY);
	if (map->fd == -1)
		return (0);
	map->str = read_all_map(map);
	if (map->str == NULL)
	{
		ft_putstr_fd("Error\nInvalid file : find a new line \n", 2);
		return (0);
	}
	if (check_path(av, ft_strlen(av)) == 0)
	{
		ft_putstr_fd("Error\nInvalid path\n", 2);
		return (0);
	}
	if (check_border(map->str[0]) == 0 || 
		check_border(map->str[map->vertical - 1]) == 0)
	{
		ft_putstr_fd("Error\nInvalid border\n", 2);
		return (0);
	}
	return (1);
}

static int	check_help2(t_map *map, int i)
{
	int	j;

	j = 1;
	while (j != i)
	{
		if (j == i - 1)
			if (check_line(map->str[j], ft_strlen(map->str[j]), 1, 0) == 0)
				return (0);
		if (check_line(map->str[j], ft_strlen(map->str[j]), 0, 0) == 0)
			return (0);
		j++;
	}
	return (1);
}

int	check_all_map(char *av, t_map *map)
{
	int	i;

	i = 0;
	if (check_help(av, map) == 0)
		return (0);
	while (map->str[i] != NULL && map->str[i + 1] != NULL)
	{
		if (check_shape(map->str[i], map->str[i + 1]) == 0)
			return (0);
		i++;
	}
	if (check_help2(map, i) == 0)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		return (0);
	}
	free_map(map, 1);
	close(map->fd);
	return (1);
}
