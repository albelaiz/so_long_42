/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:24:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/06 16:17:09 by albelaiz         ###   ########.fr       */
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
// void	key_s(t_game **game)
// {
// 	if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == '1')
// 		return ;
// 	else if ((*game)->map[((*game)->char_y / 64) + 1][(*game)->char_x
// 		/ 64] == 'E' && !(*game)->c_collectible)
// 		mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
// 	else if (((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x
// 				/ 64)] == '0') || ((*game)->map[((*game)->char_y / 64)
// 			+ 1][((*game)->char_x / 64)] == 'P'))
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x, (*game)->char_y + 64);
// 		(*game)->char_y += 64;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x
// 			/ 64)] == 'C')
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x, (*game)->char_y + 64);
// 		(*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] = '0';
// 		(*game)->char_y += 64;
// 		(*game)->c_collectible--;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x
// 			/ 64)] == 'E' && !(*game)->c_collectible)
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		exit(0);
// 	}
// }
// void	key_w(t_game **game)
// {
// 	if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == '1')
// 		return ;
// 	else if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x
// 			/ 64)] == 'E' && !(*game)->c_collectible)
// 		mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
// 	else if (((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x
// 				/ 64)] == '0') || ((*game)->map[((*game)->char_y / 64)
// 			- 1][((*game)->char_x / 64)] == 'P'))
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x, (*game)->char_y - 64);
// 		(*game)->char_y -= 64;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x
// 			/ 64)] == 'C')
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x, (*game)->char_y - 64);
// 		(*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] = '0';
// 		(*game)->char_y -= 64;
// 		(*game)->c_collectible--;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x
// 			/ 64)] == 'E' && !(*game)->c_collectible)
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		exit(0);
// 	}
// }
// void	key_a(t_game **game)
// {
// 	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == '1')
// 		return ;
// 	else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 		- 1] == 'E' && !(*game)->c_collectible)
// 		mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
// 	else if (((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 			- 1] == '0') || ((*game)->map[((*game)->char_y
// 				/ 64)][((*game)->char_x / 64) - 1] == 'P'))
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x - 64, (*game)->char_y);
// 		(*game)->char_x -= 64;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 		- 1] == 'C')
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x - 64, (*game)->char_y);
// 		(*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] = '0';
// 		(*game)->char_x -= 64;
// 		(*game)->c_collectible--;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 		- 1] == 'E' && !(*game)->c_collectible)
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		exit(0);
// 	}
// }
// void	key_d(t_game **game)
// {
// 	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == '1')
// 		return ;
// 	else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 		+ 1] == 'E' && !(*game)->c_collectible)
// 		mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
// 	else if (((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 			+ 1] == '0') || ((*game)->map[((*game)->char_y
// 				/ 64)][((*game)->char_x / 64) + 1] == 'P'))
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x + 64, (*game)->char_y);
// 		(*game)->char_x += 64;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 		+ 1] == 'C')
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
// 			(*game)->char_x + 64, (*game)->char_y);
// 		(*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] = '0';
// 		(*game)->char_x += 64;
// 		(*game)->c_collectible--;
// 	}
// 	else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64)
// 		+ 1] == 'E' && !(*game)->c_collectible)
// 	{
// 		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
// 			(*game)->char_x, (*game)->char_y);
// 		exit(0);
// 	}
// }

void	move_player(t_game **game, int dx, int dy)
{
	int new_x = ((*game)->char_x / 64) + dx;
	int new_y = ((*game)->char_y / 64) + dy;
	char next_tile = (*game)->map[new_y][new_x];

	if (next_tile == '1')
		return ;
	else if (next_tile == 'E' && !(*game)->c_collectible)
	{
		mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
		exit(0);
	}
	else
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor,
			(*game)->char_x, (*game)->char_y);
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,
			(*game)->char_x + dx * 64, (*game)->char_y + dy * 64);
		(*game)->char_x += dx * 64;
		(*game)->char_y += dy * 64;
		if (next_tile == 'C')
		{
			(*game)->map[new_y][new_x] = '0';
			(*game)->c_collectible--;
		}
	}
}

void	key_w(t_game **game) { move_player(game, 0, -1); }
void	key_s(t_game **game) { move_player(game, 0, 1); }
void	key_a(t_game **game) { move_player(game, -1, 0); }
void	key_d(t_game **game) { move_player(game, 1, 0); }
