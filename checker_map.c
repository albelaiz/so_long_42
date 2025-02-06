/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:27:02 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/06 12:32:06 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void checker_wall(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	if (!game->map || game->n < 1)
	{
		write(1,"Error: Invalid map\n", 19);
		exit(1);
	}
	while (game->map[0][i] == '1')
		i++;
	while (game->map[game->n][j] == '1')
		j++;
	if ((game->map[0][i] != '\n') || (game->map[game->n][j] != '\0'))
		write(1,"Error\n",6);
	while (game->map[1][j] != '\n' && game->map[1][j] != '\0')
		j++;
	i = 0;
	while (i <= game->n)
	{
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
		{
			write(1,"Erorr :Second line does not '1' in end\n",39);
			exit(1);
		}
		i++;
	}
}
int checker_map_shape(t_game *game)
{
    // Implement your map validation logic here
    // Return 1 if the map is valid, 0 otherwise
    // For example, check if the map is rectangular, has valid characters, etc.
    int i;
    int len;

	i = 0;
	len = 0;
	if (!game->map || game->n < 1)
	{
		write(1,"Error: Invalid map\n", 19);
		exit(1);
	}
    while (game->map[i])
    {
        if (i == 0)
            len = ft_strlen1(game->map[i]);
        else if (ft_strlen1(game->map[i]) != len)
            return (0); // Map is not rectangular
        i++;
    }
    return (1); // Placeholder, replace with actual validation logic
}
// void cheker_map_shape(t_game *game)
// {
// 	int x;
// 	int y;
// 	int j;

// 	x = 1;
// 	y = 0;
// 	int j = 0;
// 	if (!game->map || game->n < 1)
// 	{
// 		write(1,"Error: Invalid map\n", 19);
// 		exit(1);
// 	}
// 	while (game->map[0][y] != '\n' && game->map[0][y] != '\0')
// 		y++;
// 	while (x <= game->n)
// 	{
// 		j = 0;
// 		while (game->map[x][j] != '\n' && game->map[x][j] != '\0')
// 			j++;
// 		if (j != y)
// 		{
// 			write(1,"EROOR: map not rectangular",30);
// 			exit(1);
// 		}
// 		x++;
// 	}
// 	if (y == game->n + 1)
// 		write(1,"map is square\n",14);
// 	else
// 		write(1,"map is rectangular\n",19);
// }
void checker_characters(t_game *game)
{
	int i;
	int j;
	int n;
	
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;

		while (game->map[i][j] != '\0' && game->map[i][j] != '\n')
		{
			n = checker_all(game->map[i][j]);
		if (n == 0) 
		{
            write(1, "Error: Invalid character\n", 25);
			exit(1);
		}
		j++;
		}
		i++;
	}
	write(1, "The map has all valid characters\n", 33);
}
int checker_all(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
	
		return (1);
	return (0);
}
void checker_map(t_game *game)
{
	checker_characters(game);
	checker_wall(game);
	checker_map_shape(game);
}