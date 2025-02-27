/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:07 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/27 12:03:25 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//#include "minilibx_opengl/mlx.h"
# include "ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	int		fd;
	char	**map;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		x;
	int		y;
	int		n;
	int		char_x;
	int		char_y;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		c_player;
	int		c_collectible;
	int		c_exit;
	int		player_x;
	int		player_y;
}			t_game;

void		img(t_game *game);
int			ft_strlen2(char *str);
void		key_w(t_game **game);
void		key_s(t_game **game);
void		key_a(t_game **game);
void		key_d(t_game **game);
void		ptr_to_img(t_game *game);
void		ft_link(t_game *game);
void		read_map(t_game *game);
char		**duplicate_map(t_game *game);
void		checker_map(t_game *game);
int			key(int key, t_game **game);
int			checker_wall(t_game *game);
// int			checker_map_shape(t_game *game);
int			checker_characters(t_game **game);
int			checker_all(char c, t_game **game);
int			flood_fill(char **map, int x, int y, int collectible);
#endif