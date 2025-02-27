/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:09:14 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/27 17:48:26 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void ft_link(t_game *game)
// {
// 	int i = 0;
// 	int j = 0;
// 	int x = 0;
// 	int y = 0;

// 	while (game->map[i] != NULL)
// 	{
// 		while (game->map[i][j] != '\0')
// 		{
// 			if (game->map[i][j] == '1')
// 				mlx_put_image_to_window(game->mlx,game->mlx_win,game->wall,game->x,
// game->y);
// 			else if (game->map[i][j] == 'P')
// 			{
// 				mlx_put_image_to_window(game->mlx,game->mlx_win,game->player,game->x,
// game->y);
// 				game->char_x = game->x;
// 				game->char_y = game->y;
// 			}
// 			else if (game->map[i][j] == 'C')
// 				mlx_put_image_to_window(game->mlx,game->mlx_win,game->collectible,game->x,
// game->y);
// 			else if (game->map[i][j] == 'E')
// 				mlx_put_image_to_window(game->mlx,game->mlx_win,game->exit,game->x,
// game->y);
// 			j++;
// 			x+= 64;
// 		}
// 		i++;
// 		j = 0;
// 		x = 0;
// 		y += 64;
// 	}
// }
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
