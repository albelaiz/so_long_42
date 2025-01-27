/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:14:07 by albelaiz          #+#    #+#             */
/*   Updated: 2025/01/27 13:50:51 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "ft_printf.h"
typedef struct
{
	int fd;
	char **map;
	void *lhayt;
	void *lard;
	void *carrtier;
	void *colrc;
}		t_game;

#endif