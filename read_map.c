/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/05 16:50:59 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(t_game *game)
{
	int i = 0;
	int map_size = 100;
	game->map = malloc(map_size * sizeof(char *));
	if (!game->map)
	{
		write(1, "Error: Memory allocation failed\n", 32);
		exit(1);
	}
	game->map[i] = get_next_line(game->fd);
	while(game->map[i])
	{
		i++;
		game->map[i] = get_next_line(game->fd);
		if (game->map[i] == NULL)
		break;
	}
	game->n = i - 1;
} 