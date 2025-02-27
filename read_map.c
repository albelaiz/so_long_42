/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:33 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/27 17:42:22 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	int		i;
	int		x;
	int		y;
	char	*line;

	i = 0;
	y = 0;
	line = NULL;
	game->map = malloc(100 * sizeof(char *));
	game->map[i] = get_next_line(game->fd);
	line = game->map[i];
	while (game->map[i])
	{
		x = 0;
		chekchek(game, line, x, y);
		i++;
		y++;
		game->map[i] = get_next_line(game->fd);
		if (game->map[i] == NULL)
			break ;
	}
	game->n = i - 1;
}
