/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_til_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:24:37 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/14 15:31:57 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
