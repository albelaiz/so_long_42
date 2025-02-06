/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:29:34 by albelaiz          #+#    #+#             */
/*   Updated: 2025/02/06 18:41:17 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void gg(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 64, game->n * 64, "so_long");
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &game->x, &game->y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/tree.xpm", &game->x, &game->y);
	game->player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &game->x, &game->y);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "img/collectible.xpm", &game->x, &game->y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &game->x, &game->y);
	
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
	t_game *game = malloc(sizeof(t_game));
	if (!game)
	{
		write(1,"Malloc error\n",13);
		return(1);
	}
	game->fd = open(argv[1],O_RDONLY);
	if (game->fd < 0)
	{
		write(1,"error open file",15);
		return(1);
	}
	read_map(game);
	checker_map(game);
	gg(game);
	img(game);
	mlx_loop(game->mlx);
}
}
