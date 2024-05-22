/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:49:44 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/22 13:53:05 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			else if (game->map[i][j] == 'E')
			{
				mlx_image_to_window(game->mlx_ptr, game->ship_load, 
					j * 64, i * 64);
				game->ship_x = j * 64;
				game->ship_y = i * 64;
			}
			j++;
		}
		i++;
	}
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
			if (game->map[i][j] == 'P' || game->map[i][j] == 'C')
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

void	textures_to_images(t_solong *game)
{
	game->fruit = mlx_load_png("./textures/fruit.png");
	game->player = mlx_load_png("./textures/marshall.png");
	game->ship = mlx_load_png("./textures/ship.png");
	game->wall = mlx_load_png("./textures/wall.png");
	game->space = mlx_load_png("./textures/space.png");
	game->fruit_load = mlx_texture_to_image(game->mlx_ptr, game->fruit);
	game->marshall = mlx_texture_to_image(game->mlx_ptr, game->player);
	game->ship_load = mlx_texture_to_image(game->mlx_ptr, game->ship);
	game->wall_load = mlx_texture_to_image(game->mlx_ptr, game->wall);
	game->space_load = mlx_texture_to_image(game->mlx_ptr, game->space);
	_fill_map1(game);
}

void	on_key_press(mlx_key_data_t key, void *param)
{
	t_solong	*game;

	game = param;
	if (game->map[game->marshall->instances->y / 64]
		[game->marshall->instances->x / 64] == 'E' && game->collectible == 0)
		exit(0);
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx_ptr);
		exit(0);
	}
	else if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& key.action == MLX_PRESS)
		move_down(game);
	else if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& key.action == MLX_PRESS)
		move_up(game);
	else if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& key.action == MLX_PRESS)
		move_right(game);
	else if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& key.action == MLX_PRESS)
		move_left(game);
}

void	game_init(t_solong *game)
{
	game->moves = 1;
	game->mlx_ptr = mlx_init(game->width * 64, game->height * 64,
			"so_long", true);
	textures_to_images(game);
	mlx_image_to_window(game->mlx_ptr, game->marshall,
		game->x * 64, game->y * 64);
	mlx_key_hook(game->mlx_ptr, &on_key_press, game);
	mlx_loop(game->mlx_ptr);
}
