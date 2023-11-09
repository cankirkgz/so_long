/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:24:56 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/11/08 20:35:24 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	horizontalwall(t_game *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (!(game->map[0][j] == '1'
			&& game->map[game->heightmap - 1][j] == '1'))
			return (0);
		j++;
	}
	return (1);
}

int	verticalwall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("Error Here! %c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->collectables++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->collectables > 0
			&& game->exitcount == 1))
	{
		printf("Error\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		exit_point(game);
	}
}

void	check_errors(t_game *game)
{
	if (game->heightmap > 20)
		exit_or_error("Too many lines!", game);
	if (game->widthmap > 40)
		exit_or_error("Too many columns!", game);
	if_walls(game);
	character_valid(game);
}
