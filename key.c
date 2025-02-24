/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:24:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/19 17:52:29 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key(int key, t_game **game)
{
	if (key == 13 || key == 126)
		key_w(game);
	if (key == 1 || key == 125)
		key_s(game);
	if (key == 0 || key == 123)
		key_a(game);
	if (key == 2 || key == 124)
		key_d(game);
	if (key == 53)
		exit(0);
	return(0);
}
void key_s(t_game **game)
{
	if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == '1')
			return ;
	else if ((*game)->map[((*game)->char_y / 64) + 1][(*game)->char_x / 64] == 'E' && !(*game)->c_collectible)
		mlx_destroy_window((*game)->mlx,(*game)->mlx_win);
	else if (((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == '0' )
	||((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == 'P'))
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor, (*game)->char_x, (*game)->char_y);
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player, (*game)->char_x, (*game)->char_y + 64);
		(*game)->char_y += 64;
	}
	else if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == 'C')
	{
		mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
		mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->player,(*game)->char_x,(*game)->char_y + 64);
		(*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] = '0';
		(*game)->char_y += 64;
		(*game)->c_collectible--;
	}
	else if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == 'E' && !(*game)->c_collectible)
	{
		mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
		exit(0);
	}
}
void key_w(t_game **game)
{
		if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == '1')
			return ;
		else if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == 'E' && !(*game)->c_collectible)
			mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
		else if (((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == '0' )
		|| ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == 'P'))
		{
			mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor, (*game)->char_x, (*game)->char_y);
			mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player, (*game)->char_x, (*game)->char_y - 64);
			(*game)->char_y -= 64;
		}
		else if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == 'C')
		{
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->player,(*game)->char_x,(*game)->char_y - 64);
			(*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] = '0';
			(*game)->char_y -= 64;
			(*game)->c_collectible--;
		}
		else if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == 'E' && !(*game)->c_collectible)
		{
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
			exit(0);
		}
}
void key_a(t_game **game)
{
		if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == '1')
			return ;
		else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == 'E' && !(*game)->c_collectible)
			mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
		else if (((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == '0' )
		|| ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == 'P'))
		{
			mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor, (*game)->char_x, (*game)->char_y);
			mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player, (*game)->char_x - 64, (*game)->char_y);
			(*game)->char_x -= 64;
		}
		else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == 'C')
		{
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->player,(*game)->char_x - 64,(*game)->char_y);
			(*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] = '0';
			(*game)->char_x -= 64;
			(*game)->c_collectible--;
		}
		else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == 'E' && !(*game)->c_collectible)
		{
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
			exit(0);
		}
}
void key_d(t_game **game)
{
		if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == '1')
			return ;
		else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == 'E' && !(*game)->c_collectible)
			mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
		else if (((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == '0' )
		|| ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == 'P'))
		{
			mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->floor, (*game)->char_x, (*game)->char_y);
			mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player, (*game)->char_x + 64, (*game)->char_y);
			(*game)->char_x += 64;
		}
		else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == 'C')
		{
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->player,(*game)->char_x + 64,(*game)->char_y);
			(*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] = '0';
			(*game)->char_x += 64;
			(*game)->c_collectible--;
		}
		else if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == 'E' && !(*game)->c_collectible)
		{
			mlx_put_image_to_window((*game)->mlx,(*game)->mlx_win,(*game)->floor,(*game)->char_x,(*game)->char_y);
			exit(0);
		}
}
