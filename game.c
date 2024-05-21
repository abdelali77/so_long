/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:49:44 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/21 13:37:04 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_fill_map2(t_solong *game, t_textures *texture)
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
				mlx_image_to_window(game->mlx_ptr, texture->fruit_load,
					j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_image_to_window(game->mlx_ptr, texture->space_load, 
					j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx_ptr, texture->ship_load, 
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx_ptr, game->marshall, 
		game->x * 64, game->y * 64);
}

void	_fill_map1(t_solong *game, t_textures *texture)
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
				mlx_image_to_window(game->mlx_ptr, texture->space_load,
					j * 64, i * 64);
			else
				mlx_image_to_window(game->mlx_ptr, texture->wall_load,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	_fill_map2(game, texture);
}

void	textures_to_images(t_textures *img, t_solong *game)
{
	img->fruit = mlx_load_png("./textures/fruit.png");
	img->player = mlx_load_png("./textures/marshall.png");
	img->ship = mlx_load_png("./textures/ship.png");
	img->wall = mlx_load_png("./textures/wall.png");
	img->space = mlx_load_png("./textures/space.png");
	img->fruit_load = mlx_texture_to_image(game->mlx_ptr, img->fruit);
	game->marshall = mlx_texture_to_image(game->mlx_ptr, img->player);
	img->ship_load = mlx_texture_to_image(game->mlx_ptr, img->ship);
	img->wall_load = mlx_texture_to_image(game->mlx_ptr, img->wall);
	img->space_load = mlx_texture_to_image(game->mlx_ptr, img->space);
	_fill_map1(game, img);
}

void	on_key_press(mlx_key_data_t key, void *param)
{
	t_solong	*game;

	game = param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx_ptr);
		exit(0);
	}
	else if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_down(game);
	else if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_up(game);
	else if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_right(game);
	else if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_left(game);
}

void	game_init(t_solong *game, t_textures *textures)
{
	game->mlx_ptr = mlx_init(game->width * 64, game->height * 64,
			"so_long", true);
	textures_to_images(textures, game);
	mlx_key_hook(game->mlx_ptr, &on_key_press, game);
	mlx_loop(game->mlx_ptr);
}
