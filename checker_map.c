/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:27:02 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/26 20:27:11 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i] == '1')
		i++;
	while (game->map[game->n][j] == '1')
		j++;
	if ((game->map[0][i] != '\n') || (game->map[game->n][j] != '\0'))
			return(1);
	while (game->map[1][j] != '\n' && game->map[1][j] != '\0')
		j++;
	i = 0;
	while (i <= game->n)
	{
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
			return (1);
		i++;
	}
	return(0);
}

// int	checker_map_shape(t_game *game)
// {
// 	int	i;
// 	int	len;

// 	// Implement your map validation logic here
// 	// Return 1 if the map is valid, 0 otherwise
// 	// For example, check if the map is rectangular, has valid characters, etc.
// 	i = 0;
// 	len = 0;
// 	while (game->map[i])
// 	{
// 		if (i == 0)
// 			len = ft_strlen1(game->map[i]);
// 		else if (ft_strlen1(game->map[i]) != len)
// 			return (0); // Map is not rectangular
// 		i++;
// 	}
// 	return (1);
// }
int	checker_characters(t_game **game)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while ((*game)->map[i] != NULL)
	{
		j = 0;
		while ((*game)->map[i][j] != '\0' && (*game)->map[i][j] != '\n')
		{
			n = checker_all((*game)->map[i][j], game);
			if ((*game)->map[i][j] == 'P')
			{
				(*game)->player_x = j;
				(*game)->player_y = i;
			}
			if (n == 0)
				return (write(1, "Error: Invalid character\n", 25), 1);
			j++;
		}
		i++;
	}
	return(0);
}

int	checker_all(char c, t_game **game)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == 'P')
			(*game)->c_player++;
		if (c == 'C')
			(*game)->c_collectible++;
		if (c == 'E')
			(*game)->c_exit++;
		return (1);
	}
	return (0);
}

void	checker_map(t_game *game)
{
	int i = 0;
	if (game->n == ft_strlen1(game->map[0]))
		ft_printf("Error: the map is not rectangular\n", i++);
	if (checker_characters(&game))
		ft_printf("Error: Invalid character\n",i++);
	if (checker_wall(game))
		ft_printf("Error: Invalid wall\n",i++);
	if (checker_map_shape(game))
		ft_printf("Error: Invalid map shape\n",i++);
	if (i)
		exit(1);
}