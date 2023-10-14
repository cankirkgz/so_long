/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:38:15 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/12 19:26:49 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    error_message(void)
{
    printf("Error\nInvalid Map\n");
}

void	exit_or_error(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	mlx_destroy_window(game->mlxpointer, game->winpointer);
	exit_point(game);
	exit(0);
}

void	malloc_error_exit(t_game *game)
{
	ft_printf("Error\nMalloc error\n!");
	exit_point(game);
	exit(1);
}