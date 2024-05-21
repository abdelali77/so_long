/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:52:04 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/21 14:27:19 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_solong *game)
{
	int	y;
	int x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y][x + 1] == '1')
		return;
	game->marshall->instances->x += 64;
	check_collect(game);
	ft_printf("RIGHT\n");
}

void	move_left(t_solong *game)
{
	int	y;
	int x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y][x - 1] == '1')
		return;
	game->marshall->instances->x -= 64;
	check_collect(game);
	ft_printf("LEFT\n");
}

void	move_up(t_solong *game)
{
	int	y;
	int x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y - 1][x] == '1')
		return;
	game->marshall->instances->y -= 64;
	check_collect(game);
	ft_printf("UP\n");
}

void	move_down(t_solong *game)
{
	int	y;
	int x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y + 1][x] == '1')
		return;
	game->marshall->instances->y += 64;
	check_collect(game);
	ft_printf("DOWN\n");
}

void	check_collect(t_solong *game)
{
	int	y;
	int x;

	y = game->marshall->instances->y / 64;
	x = game->marshall->instances->x / 64;
	if (game->map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx_ptr, game->texture->wall_load,
					y * 64, x * 64);
	}
}