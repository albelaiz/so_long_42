/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:29:34 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/27 13:39:58 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ptr_to_img(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, (ft_strlen2(game->map[0]) - 1)
			* 64, (game->n + 1) * 64, "so_long");
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &game->x,
			&game->y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/tree.xpm", &game->x,
			&game->y);
	game->player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &game->x,
			&game->y);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "img/collectible.xpm",
			&game->x, &game->y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &game->x,
			&game->y);
}
int	main(int argc, char **argv)
{
	char	**new_map;
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		game->fd = open(argv[1], O_RDONLY);
		if (game->fd < 0)
		{
			write(1, "error open file", 15);
			return (1);
		}
		game->c_collectible = 0;
		game->c_exit = 0;
		game->c_player = 0;
		read_map(game);
		checker_map(game);
		new_map = duplicate_map(game);
		flood_fill(new_map,game->player_x,game->player_y,game->c_collectible);
		ptr_to_img(game);
		img(game);
		ft_link(game);
		mlx_key_hook(game->mlx_win, key, &game);
		mlx_loop(game->mlx);
	}
}
