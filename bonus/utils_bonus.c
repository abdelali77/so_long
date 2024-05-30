/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:49:38 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/30 17:02:52 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	arr_len(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	player_pos(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_solong *game, int c, int e)
{
	if (c != game->collectible || e != game->exit)
	{
		ft_printf("Invalid path!\n");
		ft_free(game);
		exit(1);
	}
	free_arr(game);
}

void	flood_fill(t_solong *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'X')
		return ;
	if (game->map[y][x] == 'C')
		game->c++;
	if (game->map[y][x] == 'E')
		game->e++;
	game->map[y][x] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

