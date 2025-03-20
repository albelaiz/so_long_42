/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:24:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/14 17:13:39 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(int key, t_game **game)
{
	if (key == 13 || key == 126)
		move_player(game, 0, -1);
	if (key == 1 || key == 125)
		move_player(game, 0, 1);
	if (key == 0 || key == 123)
		move_player(game, -1, 0);
	if (key == 2 || key == 124)
		move_player(game, 1, 0);
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
		return (ft_free_dop((*game)->map), exit(0));
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
		ft_printf("%d\n", (*game)->cont_move++);
	}
}
