/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:07 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/19 15:22:57 by albelaiz         ###   ########.fr       */
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
	int		width;
	int		height;
	int		i_link;
	int		j_link;
	int		cont_move;
}			t_game;

t_game		*ft_malloc(void);
void		img(t_game *game);
int			close_win(t_game **game);
void		ft_free(t_game *game);
int			ft_strlen2(char *str);
void		ft_link(t_game *game);
void		func_img(t_game *game);
void		read_map(t_game *game);
void		ft_free_dop(char **map);
void		ptr_to_img(t_game *game);
void		checker_map(t_game *game);
int			checker_wall(t_game *game);
int			key(int key, t_game **game);
char		**duplicate_map(t_game *game);
int			checker_characters(t_game **game);
int			checker_all(char c, t_game **game);
void		position(t_game *game, int i, int j);
void		ft_norm_link(t_game *game, int x, int y);
void		move_player(t_game **game, int dx, int dy);
void		*ft_memset(void *ptr, int value, size_t num);
void		next_til_c(t_game **game, int new_x, int new_y);
void		next_til_c(t_game **game, int new_x, int new_y);
void		chekchek(t_game *game, char *line, int x, int y);
int			flood_fill(char **map, int x, int y, int collectible);
#endif