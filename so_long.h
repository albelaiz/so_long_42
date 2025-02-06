/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:07 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/06 18:26:18 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//#include "minilibx_opengl/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "minilibx/mlx.h"
#include "get_next_line.h"

typedef struct s_game
{
	int fd;
	char **map;
	void *wall;
	void *floor;
	void *player;
	void *collectible;
	void *exit;
	int x;
	int y;
	int n;
	void *mlx;
	void *mlx_win;
	void *img;
}		t_game;

void img(t_game *game);
int checker_all(char c);
int	ft_strlen1(char *str);
void read_map(t_game *game);
void checker_map(t_game *game);
void checker_wall(t_game *game);
int checker_map_shape(t_game *game);
void checker_characters(t_game *game);

#endif