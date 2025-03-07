/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:29:34 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/07 01:41:15 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ptr_to_img(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,game->width,game->height, "so_long");
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
void func_img(t_game *game)
{
	game->width = (ft_strlen2(game->map[0]) - 1) * 64;
    game->height = (game->n + 1) * 64;
	ptr_to_img(game);
	img(game);
	ft_link(game);
}
void read_and_check(t_game *game)
{
	read_map(game);
	checker_map(game);
}
t_game *ft_malloc(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		write(1, "Memory allocation failed\n", 24);
		exit(1);
	}
	ft_memset(game, 0, sizeof(t_game));
	return (game);
}

int	main(int argc, char **argv)
{
	char	**new_map;
	t_game	*game;
	
	if (argc == 2)
	{
		game = ft_malloc();
		ft_memset(game, 0, sizeof(t_game));
		game->fd = open(argv[1], O_RDONLY);
		if (game->fd < 0)
		{
			write(1, "error open file", 15);
			return (1);
		}
		read_and_check(game);
		new_map = duplicate_map(game);
		if (flood_fill(new_map, game->player_x, game->player_y,game->c_collectible) == 0)
			exit(0);
		game->mlx = mlx_init();
		func_img(game);
		mlx_key_hook(game->mlx_win, key, &game);
		mlx_loop(game->mlx);
	}
}
