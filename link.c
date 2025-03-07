/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:09:14 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/06 22:44:48 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_norm_link(t_game *game, int i, int j, int x, int y)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, x, y);
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, x, y);
		game->char_x = x;
		game->char_y = y;
	}
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectible, x,
			y);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x, y);
}
void	ft_link(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (game->map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (game->map[i][j] != '\0')
		{
			ft_norm_link(game, i, j, x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
}
