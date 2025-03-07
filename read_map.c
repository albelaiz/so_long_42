/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/07 01:49:19 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_malloc2(t_game *game)
{
	game->map = malloc(100 * sizeof(char *));
	if (!game->map)
	{
		write(1, "Memory allocation failed\n", 24);
		return ;
	}
}
void	read_map(t_game *game)
{
	int		i;
	int		x;
	int		y;
	
	i = 0;
	y = 0;
	ft_malloc2(game);
	game->map[i] = get_next_line(game->fd);
	if (!game->map[i])
	{
		write(1, "Error reading map\n", 18);
		exit(1);
	}
	while (game->map[i])
	{
		x = 0;
		chekchek(game, game->map[i], x, y);
		i++;
		y++;
		game->map[i] = get_next_line(game->fd);
		if (game->map[i] == NULL)
			break ;
	}
	game->n = i - 1;
}
