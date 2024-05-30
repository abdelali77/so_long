/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:06:16 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/30 17:03:12 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_fill_map3(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				mlx_image_to_window(game->mlx_ptr, game->ship_load,
					j * 64, i * 64);
				game->ship_x = j * 64;
				game->ship_y = i * 64;
			}
			else if (game->map[i][j] == 'X')
				mlx_image_to_window(game->mlx_ptr, game->enemy_load,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	_fill_map2(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx_ptr, game->fruit_load,
					j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_image_to_window(game->mlx_ptr, game->space_load, 
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	_fill_map3(game);
}

void	_fill_map1(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'X') 
				mlx_image_to_window(game->mlx_ptr, game->space_load,
					j * 64, i * 64);
			else
				mlx_image_to_window(game->mlx_ptr, game->wall_load,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	_fill_map2(game);
}
