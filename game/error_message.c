/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:38:15 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/11/08 20:38:37 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	destroy_map(char **map, t_game game)
{
	int	i;

	i = 0;
	while (map[i] && i < game.heightmap)
	{
		free(map[i]);
		i++;
	}
}

void	error_message(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	exit_point(game);
}

void	error_and_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	exit_or_error(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	exit_point(game);
	exit(0);
}
