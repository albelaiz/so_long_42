/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:24:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/07 20:38:39 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(int key, t_game **game)
{
	if (key == 13 || key == 126)
		key_w(game);
	if (key == 1 || key == 125)
		key_s(game);
	if (key == 0 || key == 123)
		key_a(game);
	if (key == 2 || key == 124)
		key_d(game);
	if (key == 53 || key == 17)
		exit(0);
	return (0);
}
void	move_player(t_game **game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = ((*game)->char_x / 64) + dx;
	new_y = ((*game)->char_y / 64) + dy;
	next_tile = (*game)->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	else if (next_tile == 'E' && !(*game)->c_collectible)
	{
		mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
		exit(0);
	}
	if (next_tile != 'E')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
			(*game)->char_x, (*game)->char_y);
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
			(*game)->char_x + dx * 64, (*game)->char_y + dy * 64);
		(*game)->char_x += dx * 64;
		(*game)->char_y += dy * 64;
if (next_tile == 'C')
		next_til_c(game, new_x, new_y);
}
}
void	next_til_c(t_game **game, int new_x, int new_y)
{
	(*game)->map[new_y][new_x] = '0';
	if ((*game)->map[new_y][new_x] == '0')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
			new_x * 64, new_y * 64);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
		(*game)->char_x, (*game)->char_y);
	(*game)->c_collectible--;
}

void	key_w(t_game **game)
{
	move_player(game, 0, -1);
}
void	key_s(t_game **game)
{
	move_player(game, 0, 1);
}
void	key_a(t_game **game)
{
	move_player(game, -1, 0);
}
void	key_d(t_game **game)
{
	move_player(game, 1, 0);
}
