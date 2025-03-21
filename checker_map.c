/* ************************************************************************** */
/*						                                                     */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:27:02 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/21 01:26:31 by albelaiz         ###   ########.fr       */
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
		return (1);
	while (game->map[1][j] != '\n' && game->map[1][j] != '\0')
		j++;
	i = 0;
	while (i <= game->n)
	{
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

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
			if (n == 0)
				return (write(1, "Error: Invalid character\n", 25), 1);
			j++;
		}
		i++;
	}
	return (0);
}

void	position(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
	}
}

int	checker_all(char c, t_game **game)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '1' || c == '0')
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

int	check_map_row_lengths(t_game *game)
{
	int	first_len;
	int	i;
	int	curr_len;

	i = 0;
	if (!game->map || !game->map[0])
		return (ft_printf("Error: Map is empty\n"), 1);
	first_len = ft_strlen2(game->map[0]);
	if (game->map[0][first_len - 1] == '\n')
		first_len--;
	while (game->map[++i])
	{
		curr_len = ft_strlen2(game->map[i]);
		if (game->map[i][curr_len - 1] == '\n')
			curr_len--;
		if (curr_len != first_len)
			return (ft_printf("Error: Row %d has wrong length\n", i), exit(1),
				1);
	}
	return (0);
}

void	checker_map(t_game *game)
{
	check_map_row_lengths(game);
	if (game->n == ft_strlen2(game->map[0]))
		ft_printf("Error: the map is not rectangular\n");
	if (checker_characters(&game))
		return (ft_free(game), exit(1));
	if (checker_wall(game))
		return (ft_printf("Error: Invalid wall\n"), ft_free(game), exit(1));
	if (game->c_exit != 1 || game->c_collectible < 1 || game->c_player !=  1)
	{
		write(1, "error\ninvalid map\n", 18);
		ft_free_dop(game->map);
		exit(1);
	}
}
