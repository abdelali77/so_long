/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:52:04 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/23 15:39:03 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_solong *game)
{
	int	y;
	int	x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y][x + 1] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectible--;
	}
	mlx_image_to_window(game->mlx_ptr, game->space_load, x * 64, y * 64);
	game->marshall->instances->x += 64;
	mlx_image_to_window(game->mlx_ptr, game->marshall,
		game->marshall->instances->x,
		game->marshall->instances->y);
	mlx_image_to_window(game->mlx_ptr, game->ship_load,
		game->ship_x, game->ship_y);
	ft_printf("moves : %d\n", game->moves++);
}

void	move_left(t_solong *game)
{
	int	y;
	int	x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y][x - 1] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectible--;
	}
	mlx_image_to_window(game->mlx_ptr, game->space_load, x * 64, y * 64);
	game->marshall->instances->x -= 64;
	mlx_image_to_window(game->mlx_ptr, game->marshall,
		game->marshall->instances->x,
		game->marshall->instances->y);
	mlx_image_to_window(game->mlx_ptr, game->ship_load,
		game->ship_x, game->ship_y);
	ft_printf("moves : %d\n", game->moves++);
}

void	move_up(t_solong *game)
{
	int	y;
	int	x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y - 1][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectible--;
	}
	mlx_image_to_window(game->mlx_ptr, game->space_load, x * 64, y * 64);
	game->marshall->instances->y -= 64;
	mlx_image_to_window(game->mlx_ptr, game->marshall,
		game->marshall->instances->x,
		game->marshall->instances->y);
	mlx_image_to_window(game->mlx_ptr, game->ship_load,
		game->ship_x, game->ship_y);
	ft_printf("moves : %d\n", game->moves++);
}

void	move_down(t_solong *game)
{
	int	y;
	int	x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y + 1][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectible--;
	}
	mlx_image_to_window(game->mlx_ptr, game->space_load, x * 64, y * 64);
	game->marshall->instances->y += 64;
	mlx_image_to_window(game->mlx_ptr, game->marshall,
		game->marshall->instances->x,
		game->marshall->instances->y);
	mlx_image_to_window(game->mlx_ptr, game->ship_load,
		game->ship_x, game->ship_y);
	ft_printf("moves : %d\n", game->moves++);
}
