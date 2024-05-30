/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:49:44 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/30 17:10:45 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	textures_to_images(t_solong *game)
{
	game->fruit_load = mlx_texture_to_image(game->mlx_ptr, game->fruit);
	if (!game->fruit_load)
		textures_err(game);
	game->marshall = mlx_texture_to_image(game->mlx_ptr, game->player);
	if (!game->marshall)
		textures_err(game);
	game->ship_load = mlx_texture_to_image(game->mlx_ptr, game->ship);
	if (!game->ship_load)
		textures_err(game);
	game->wall_load = mlx_texture_to_image(game->mlx_ptr, game->wall);
	if (!game->wall_load)
		textures_err(game);
	game->space_load = mlx_texture_to_image(game->mlx_ptr, game->space);
	if (!game->space_load)
		textures_err(game);
	game->enemy_load = mlx_texture_to_image(game->mlx_ptr, game->enemy);
	if (!game->enemy_load)
		textures_err(game);
	_fill_map1(game);
}

void	load_png(t_solong *game)
{
	game->fruit = mlx_load_png("./textures/fruit.png");
	if (!game->fruit)
		textures_err(game);
	game->player = mlx_load_png("./textures/marshall.png");
	if (!game->player)
		textures_err(game);
	game->ship = mlx_load_png("./textures/ship.png");
	if (!game->ship)
		textures_err(game);
	game->wall = mlx_load_png("./textures/wall.png");
	if (!game->wall)
		textures_err(game);
	game->space = mlx_load_png("./textures/space.png");
	if (!game->space)
		textures_err(game);
	game->enemy = mlx_load_png("./textures/shanks.png");
	if (!game->enemy)
		textures_err(game);
	textures_to_images(game);
}

void	on_key_press(mlx_key_data_t key, void *param)
{
	t_solong	*game;

	game = param;
	if (game->map[game->marshall->instances->y / 64]
		[game->marshall->instances->x / 64] == 'E' && game->collectible == 0)
		free_textures(game);
	if (key.key == MLX_KEY_ESCAPE
		||game->map[game->marshall->instances->y / 64]
		[game->marshall->instances->x / 64] == 'X')
		free_textures(game);
	else if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_down(game);
	else if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_up(game);
	else if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_right(game);
	else if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_left(game);
}

void	close_win(void *param)
{
	t_solong	*game;

	game = param;
	free_textures(game);
}

void	game_init(t_solong *game)
{
	game->moves = 1;
	game->mlx_ptr = mlx_init(game->width * 64, game->height * 64,
			"so_long", true);
	if (!game->mlx_ptr)
		_error(game);
	load_png(game);
	mlx_image_to_window(game->mlx_ptr, game->marshall,
		game->x * 64, game->y * 64);
	if (mlx_image_to_window(game->mlx_ptr, game->marshall,
			game->x * 64, game->y * 64) < 0)
		_error(game);
	mlx_put_string(game->mlx_ptr, "Moves : ", 3, 0);
	mlx_key_hook(game->mlx_ptr, &on_key_press, game);
	mlx_loop_hook(game->mlx_ptr, _animate_coin, game);
	mlx_close_hook(game->mlx_ptr, close_win, game);
	mlx_loop(game->mlx_ptr);
}
