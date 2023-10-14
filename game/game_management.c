/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:51:18 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/14 10:36:02 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void  find_player(t_game *game)
{
	char **map;
	int x;
	int y;

	map = game->map;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				game->x_axis = x;
				game->y_axis = y;
			}
			x++;
		}
		y++;
	}
}

int count_coin(t_game *game)
{
	int	count;
	int	i;
	int j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	place_images_in_game(t_game *game)
{
	int	i;
	int	j;

	i = 64;
	j = 64;
	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/door.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/coin.xpm", &i, &j);
}
void draw_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			draw_tile(game, j * TILE_SIZE, i * TILE_SIZE, game->map[i][j]);
			j++;
		}
		i++;
	}
}

void draw_tile(t_game *game, int x, int y, char type)
{
	char	*file_path;

	file_path = NULL;
	mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->floor, x, y);
	if (type == '1')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->barrier, x, y);
	else if (type == '0')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->floor, x, y);
	else if( type == 'C')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->collectable, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->player, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->exit, x, y);
}