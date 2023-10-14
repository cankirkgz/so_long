/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:28 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/14 11:01:59 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int key_press(int keycode, t_game *game)
{
	if (keycode == 2)
		right_move(game);
	else if (keycode == 0)
		left_move(game);
	else if (keycode == 13)
		up_move(game);
	else if (keycode == 1)
		down_move(game);
    if (keycode == 53 || keycode == 17)
        exit(0);
    return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
    map_reading(&game, argv);
	printf("----- ORJINAL ------------\n");
	for (size_t i = 0; game.map[i]; i++)
	{
		printf("%s", game.map[i]);
	}
	printf("\n----- TEMP ------------\n");
	for (size_t i = 0; game.temp_map[i]; i++)
	{
		printf("%s", game.temp_map[i]);
	}
	printf("\n----------------------------\n");
	find_player(&game);
	check_errors(&game);
	//validate_game_map(&game);
	for(int i = 0; i < game.heightmap; i++)
	{
		ft_printf("%s", game.map[i]);
	}
	ft_printf("lalala");
    game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, 
		game.widthmap * TILE_SIZE, game.heightmap * TILE_SIZE, "solong");
	place_images_in_game(&game);
	draw_map(&game);
	game.collectables = count_coin(&game);
    mlx_hook(game.winpointer, 2, 1L << 0, key_press, &game);
    mlx_hook(game.winpointer, 17, 1L << 0, ft_close, &game);
	mlx_loop(game.mlxpointer);
	return (0);
}
