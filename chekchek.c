/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekchek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:31:17 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/20 16:01:33 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chekchek(t_game *game, char *line, int x, int y)
{
	while (line[x])
	{
		if (line[x] == 'P')
		{
			game->player_x = x;
			game->player_y = y;
		}
		x++;
	}
}

