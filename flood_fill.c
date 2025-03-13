/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:27 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/08 22:14:37 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_map(t_game *game)
{
	int		i;
	int rows = 0;
	char	**new_map;

	i = 0;
	while (game->map[rows])
		rows++;
	new_map = (malloc(sizeof(char *) * (rows + 1)));
	while (game->map[i])
	{
		new_map[i] = ft_strdup(game->map[i]);
		if (!new_map[i])
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
int	flood_fill(char **map, int x, int y, int collectible)
{
	static int	door;
	static int	collected;
	int			toul;

	toul = 0;
	while (map[toul])
		toul++;
	if (x < 0 || y < 0 || x > ft_strlen2(map[0]) - 1 || y > toul|| map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		collected++;
	if (map[y][x] == 'E')
		door = 1;
	if (door && collected == collectible)
		return (1);
	map[y][x] = '1';
	return (flood_fill(map, x + 1, y, collectible) || flood_fill(map, x - 1, y,
			collectible) || flood_fill(map, x, y + 1, collectible)
		|| flood_fill(map, x, y - 1, collectible));
}
