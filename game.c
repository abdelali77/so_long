/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:49:44 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/22 20:13:37 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures_to_images(t_solong *game)
{
	game->fruit_load = mlx_texture_to_image(game->mlx_ptr, game->fruit);
	if (!game->fruit_load)
		print_err();
	game->marshall = mlx_texture_to_image(game->mlx_ptr, game->player);
	if (!game->marshall)
		print_err();
	game->ship_load = mlx_texture_to_image(game->mlx_ptr, game->ship);
	if (!game->ship_load)
		print_err();
	game->wall_load = mlx_texture_to_image(game->mlx_ptr, game->wall);
	if (!game->wall_load)
		print_err();
	game->space_load = mlx_texture_to_image(game->mlx_ptr, game->space);
	if (!game->space_load)
		print_err();
	_fill_map1(game);
}

void	load_png(t_solong *game)
{
	game->fruit = mlx_load_png("./textures/fruit.png");
	if(!game->fruit)
		print_err();
	game->player = mlx_load_png("./textures/marshall.png");
	if(!game->player)
		print_err();
	game->ship = mlx_load_png("./textures/ship.png");
	if(!game->ship)
		print_err();
	game->wall = mlx_load_png("./textures/wall.png");
	if(!game->wall)
		print_err();
	game->space = mlx_load_png("./textures/space.png");
	if(!game->space)
		print_err();
	textures_to_images(game);
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
	if (!game->mlx_ptr)
		print_err();
	load_png(game);
	mlx_image_to_window(game->mlx_ptr, game->marshall,
		game->x * 64, game->y * 64);
	mlx_key_hook(game->mlx_ptr, &on_key_press, game);
	mlx_loop(game->mlx_ptr);
}
