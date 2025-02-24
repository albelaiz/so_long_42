/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:27 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/24 10:31:11 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **duplicte(t_game *game)
{
	int i = 0;
	char **new_map;
	new_map = (malloc(sizeof(char *) + game->n));
	while(game->map[i])
	{
		new_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	new_map[i] = NULL;
	return(new_map);
}
int flood_fill(char **map,int x, int y,int collectible)
{
	static int door;
	static int collected;
	int toul = 0;
	while(map[toul])
		toul++;
	if(x >= ft_strlen1(map[0]) - 1 || y >= toul || map[y][x] == '1' || x <= 0 || y <= 0)
		return 0;
	if (map[y][x] == 'C')
		collected++;
	if (map[y][x] == 'E' && !door)
		door = 1;
	if (door && collected == collectible)
		return 1;
	map[y][x] = '1';
	return(flood_fill(map, x + 1, y ,collectible)||
	flood_fill(map, x - 1, y ,collectible)||
	flood_fill(map, x, y + 1,collectible)||
	flood_fill(map, x, y - 1,collectible));
}
