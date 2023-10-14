/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:56:28 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/11 13:04:39 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void print_move(t_game *game, char movement)
{
    game->collectables--;
    if (movement == 'R')
        printf("Sağa hareket edildi. Hareket sayısı: %d\n", game->counter);
    else if (movement == 'L')
        printf("Sola hareket edildi. Hareket sayısı: %d\n", game->counter);
    else if (movement == 'U')
        printf("Yukarı hareket edildi. Hareket sayısı: %d\n", game->counter);
    else if (movement == 'D')
        printf("Aşağı hareket edildi. Hareket sayısı: %d\n", game->counter);   
    printf("Toplanabilir nesne sayısı: %d\n", game->collectables);
}
void make_move(t_game *game, char movement, int i, int j)
{
    if (movement == 'R')
    {
        if (game->map[i][j + 1] == 'C')
            print_move(game, 'R');
        game->map[i][j + 1] = 'P';
    } 
    else if (movement == 'L')
    {
        if (game->map[i][j - 1] == 'C')
            print_move(game, 'L');
        game->map[i][j - 1] = 'P';
    }
    else if (movement == 'U')
    {
        if (game->map[i - 1][j] == 'C')
            print_move(game, 'U');
        game->map[i - 1][j] = 'P';
    }
    else if (movement == 'D')
    {
        if (game->map[i + 1][j] == 'C')
            print_move(game, 'D');
        game->map[i + 1][j] = 'P';
    }
}

void player_found(t_game *game, char movement, int i, int j, int new_y)
{
    game->map[i][j] = '0';
    make_move(game, movement, i, j);
    game->counter++;
    if (movement == 'D')
    {
        game->y_axis = new_y;
        draw_map(game);
    }
}

void end_game(t_game *game)
{
    game->counter++;
    printf("Oyun tamamlandı. Hareket sayısı: %d\n", game->counter);
    exit(0); 
}

void start_move(t_game *game, char movement, int new_y)
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
                if (movement == 'R')
                    player_found(game, 'R', i, j, 0);
                else if (movement == 'L')
                    player_found(game, 'L', i, j, 0);
                else if (movement == 'U')
                    player_found(game, 'U', i, j, 0);
                else if (movement == 'D')
                    player_found(game, 'D', i, j, new_y);
                break;
            }
            j++;
        }
        i++;
    }
}
