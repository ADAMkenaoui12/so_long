/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:08:38 by kadam             #+#    #+#             */
/*   Updated: 2024/03/24 00:14:10 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		fd;
	char	**str;
	char	**str2;
	int		horizontal;
	int		vertical;
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	int		player_x;
	int		player_y;
	int		collectible_nbr;
	int		move;
}			t_map;

//for get_next_line :
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_strchr(char *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

//for split the line :
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);

//for read all the map :
char		**read_all_map(t_map *map);

//for check the map :
int			check_path(char *str, int len);
int			check_shape(char *line_prev, char *line_next);
int			check_border(char *str);
int			check_line(char *line, int len_str, int status, int i);
int			check_all_map(char *av, t_map *map);

//for check the player and the collectible and the exit :
void		flood_fill(t_map *map, int x, int y);
void		position_player_collectible(t_map *map);

//for initialize the map and draw it :
void		initialize_map(t_map *map);
void		draw_the_map(t_map *map, int x, int y);

//for move the player :
int			key_hook(int keycode, t_map *map);
int			close_window(t_map *map);
//for move the player up and down and left and right :
void		move_player_up(t_map *map);
void		move_player_down(t_map *map);
void		move_player_right(t_map *map);
void		move_player_left(t_map *map);

//for free the map :
void		free_map(t_map *map, int x);

//for print the error or move :
void		ft_putstr_fd(char *str, int fd);
void		ft_print_moves(t_map *map);

#endif