/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:57:42 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/14 11:00:13 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define TILE_SIZE 64

typedef struct s_game
{
	int		fd;
	int		temp_fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;
	char 	**temp_map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
	void	*imgpointer;
}   t_game;

char	*ft_strdup(const char *s1);
int	map_reading(t_game *game, char **argv);
void	place_images_in_game(t_game *game);
void  find_player(t_game *game);
void draw_map(t_game *game);
int count_coin(t_game *game);
void draw_tile(t_game *game, int x, int y, char type);
int	ft_close(t_game *map);
int right_move(t_game *game);
int left_move(t_game *game);
int up_move(t_game *game);
int down_move(t_game *game);
void start_move(t_game *game, char movement, int new_y);
void end_game(t_game *game);
void player_found(t_game *game, char movement, int i, int j, int new_y);
int	exit_point(t_game *game);
void	check_errors(t_game *game);
void    error_message(void);
void	exit_or_error(char *str, t_game *game);
void	validate_game_map(t_game *game);
void	malloc_error_exit(t_game *game);
char* copy_string(const char* original);

#endif
