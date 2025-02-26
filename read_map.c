/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/26 15:16:08 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	int		i;
	int		map_size;
	int		x;
	int		y;
	char	*line;

	i = 0;
	map_size = 100;
	y = 0;
	line = NULL;
	game->map = malloc(map_size * sizeof(char *));
	if (!game->map)
	{
		write(1, "Error: Memory allocation failed\n", 32);
		exit(1);
	}
	game->map[i] = get_next_line(game->fd);
	line = game->map[i];
	while (game->map[i])
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		i++;
		y++;
		game->map[i] = get_next_line(game->fd);
		if (game->map[i] == NULL)
			break ;
	}
	game->n = i - 1;
}
