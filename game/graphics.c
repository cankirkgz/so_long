/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:59:26 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/11/07 19:17:08 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_free_lst(t_game *map)
{
	free(map->map);
	if (map->mlxpointer)
		free(map->mlxpointer);
}

int	ft_close(t_game *map)
{
	mlx_destroy_window(map->mlxpointer, map->winpointer);
	ft_free_lst(map);
	exit(EXIT_SUCCESS);
}
