/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:57:18 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/11 13:04:59 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int right_move(t_game *game)
{
    int new_x;

    new_x = game->x_axis;
    if (game->map[game->y_axis][new_x + 1] != '1')
    {
        if(game->map[game->y_axis][new_x + 1] != 'E')
        {
            new_x++;
            start_move(game, 'R', 0);
        }
        else if (game->map[game->y_axis][new_x + 1] == 'E' && game->collectables == 0)
            end_game(game);
        game->x_axis = new_x;
        draw_map(game);
    }
    return 1;
}

int left_move(t_game *game)
{
    int new_x;

    new_x = game->x_axis;
    if (game->map[game->y_axis][new_x - 1] != '1')
    {
        if ((game->map[game->y_axis][new_x - 1] != 'E' && game->collectables != 0) 
            || (game->map[game->y_axis][new_x - 1] != 'E' && game->collectables == 0))
            {
                new_x--;
                start_move(game, 'L', 0);
            }
            else if (game->map[game->y_axis][new_x - 1] == 'E' && game->collectables == 0)
                end_game(game);
        game->x_axis = new_x;
        draw_map(game);
    }
    return 1;
}

int up_move(t_game *game)
{
    int new_y;

    new_y = game->y_axis;
    if (game->map[new_y - 1][game->x_axis] != '1')
    {
        if ((game->map[new_y - 1][game->x_axis] != 'E' && game->collectables != 0) 
            || (game->map[new_y - 1][game->x_axis] != 'E' && game->collectables == 0))
            {
                new_y--;
                start_move(game, 'U', 0);
            }
            else if (game->map[new_y - 1][game->x_axis] == 'E' && game->collectables == 0)
                end_game(game);   
        game->y_axis = new_y;
        draw_map(game);
    }
    return 1;
}
int help_down_move(t_game *game, int new_y)
{
    int i;
    int j;
    
    i = 0;
    while (i < game->heightmap)
    {
        j = 0;
        while (j < game->widthmap)
        {
            if (game->map[i][j] == 'P')
            {
                player_found(game, 'D', i, j, new_y);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}
int down_move(t_game *game)
{
    int new_y;

    new_y = game->y_axis;
    if (new_y + 1 < game->heightmap && game->map[new_y + 1][game->x_axis] != '1')
    {
        if ((new_y + 1 < game->heightmap && game->map[new_y + 1][game->x_axis] != 'E' && game->collectables != 0) 
            || (new_y + 1 < game->heightmap && game->map[new_y + 1][game->x_axis] != 'E' && game->collectables == 0))
            {
                new_y++;
                if (!help_down_move(game, new_y))
                    return (0);
            }
            else if (new_y + 1 < game->heightmap && game->map[new_y + 1][game->x_axis] == 'E' && game->collectables == 0)
                end_game(game);
    }
    return (1);
}
