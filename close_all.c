/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:11:18 by albelaiz          #+#    #+#             */
/*   Updated: 2025/03/05 23:16:22 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_all(void *param)
{
    t_game *game = (t_game *)param;
    // Cleanup code here
    mlx_destroy_window(game->mlx, game->mlx_win);
    exit(0);
    return (0);
}