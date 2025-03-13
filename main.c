/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:29:34 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/13 18:06:20 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ptr_to_img(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width, game->height,
			"so_long");
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
void	func_img(t_game *game)
{
	game->width = (ft_strlen2(game->map[0]) - 1) * 64;
	game->height = (game->n + 1) * 64;
	ptr_to_img(game);
	img(game);
	ft_link(game);
}
t_game	*ft_malloc(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		write(2, "Memory allocation failed\n", 24);
		exit(1);
	}
	ft_memset(game, 0, sizeof(t_game));
	return (game);
}

void	func_norm(t_game *game)
{
	char	**new_map;

	read_map(game);
	checker_map(game);
	new_map = duplicate_map(game);
	if (flood_fill(new_map, game->player_x, game->player_y,game->c_collectible) == 0)
	{
		ft_free_dop(new_map);
		exit(1);
	}
	ft_free_dop(new_map);
}
void	ft_ft(void)
{
	system("leaks so_long");
}

int	close_win(t_game **game)
{
	ft_free_dop((*game)->map);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	atexit(ft_ft);
	if (argc == 2)
	{
		game = ft_malloc();
		ft_memset(game, 0, sizeof(t_game));
		game->fd = open(argv[1], O_RDONLY);
		if (game->fd < 0)
		{
			write(2, "error open file", 15);
			free(game);
			return (1);
		}
		func_norm(game);
		func_img(game);
		mlx_hook(game->mlx_win, 2, 1L << 0, key, &game);
		mlx_hook(game->mlx_win, 17, 0, close_win, &game);
		mlx_loop(game->mlx);
	}
}
