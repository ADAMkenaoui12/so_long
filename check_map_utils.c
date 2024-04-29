/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:12:09 by kadam             #+#    #+#             */
/*   Updated: 2024/03/22 23:16:53 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char *str, int len)
{
	if (str[len - 1] == 'r' && str[len - 2] == 'e' && str[len - 3] == 'b'
		&& str[len - 4] == '.')
	{
		return (1);
	}
	return (0);
}

int	check_border(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_shape(char *line_prev, char *line_next)
{
	int	i;
	int	j;

	i = ft_strlen(line_prev);
	j = ft_strlen(line_next);
	if (i != j)
	{
		ft_putstr_fd("Error\nMap is not a rectangle.\n", 2);
		return (0);
	}
	return (1);
}

int	check_line(char *line, int len_str, int status, int i)
{
	static int	e;
	static int	p;
	static int	c;

	if (line[0] == '1' && line[len_str - 1] == '1')
		i++;
	else if (line[0] != '1' || line[len_str - 1] != '1')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P')
			return (0);
		if (line[i] == 'E')
			e++;
		if (line[i] == 'P')
			p++;
		if (line[i] == 'C')
			c++;
		i++;
	}
	if ((e != 1 || p != 1 || c < 1) && status == 1)
		return (0);
	return (1);
}
