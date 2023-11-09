/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:32:10 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/11/08 21:17:24 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	mark_winnable_areas(char **tmp_map, int x, int y)
{
	tmp_map[y][x] = 'x';
	if (tmp_map[y][x - 1] != '1' && tmp_map[y][x - 1] != 'x'
		&& tmp_map[y][x - 1] != 'E')
		mark_winnable_areas(tmp_map, x - 1, y);
	if (tmp_map[y + 1][x] != '1' && tmp_map[y + 1][x] != 'x'
		&& tmp_map[y + 1][x] != 'E')
		mark_winnable_areas(tmp_map, x, y + 1);
	if (tmp_map[y - 1][x] != '1' && tmp_map[y - 1][x] != 'x'
		&& tmp_map[y - 1][x] != 'E')
		mark_winnable_areas(tmp_map, x, y - 1);
	if (tmp_map[y][x + 1] != '1' && tmp_map[y][x + 1] != 'x'
		&& tmp_map[y][x + 1] != 'E')
		mark_winnable_areas(tmp_map, x + 1, y);
	else
		tmp_map[y][x] = 'x';
}

void	invalid_game_exit(char **map, t_game *game)
{
	ft_printf("Error!\nThe game is not winnable!\n");
	destroy_map(map, *game);
	exit(0);
}

void	check_winnability_and_obstacles(char **tmp_map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (tmp_map[y] && y < game->heightmap)
	{
		x = 0;
		while (tmp_map[y][x])
		{
			if (tmp_map[y][x] == 'E')
				if (tmp_map[y - 1][x] != 'x' && tmp_map[y + 1][x] != 'x'
					&& tmp_map[y][x - 1] != 'x' && tmp_map[y][x + 1] != 'x')
					invalid_game_exit(tmp_map, game);
			if (tmp_map[y][x] == 'C' || tmp_map[y][x] == 'P')
				invalid_game_exit(tmp_map, game);
			x++;
		}
		y++;
	}
}

void	validate_game_map(t_game *game)
{
	mark_winnable_areas(game->temp_map, game->x_axis, game->y_axis);
	check_winnability_and_obstacles(game->temp_map, game);
}

void	if_walls(t_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
		error_message("Error! Invalid Map", game);
}
