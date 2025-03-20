/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:09:14 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/14 17:13:53 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_norm_link(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = game->i_link;
	j = game->j_link;
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
			game->i_link = i;
			game->j_link = j;
			ft_norm_link(game, x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
}
