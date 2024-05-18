/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:49:44 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/18 18:27:44 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_fill_map2(t_solong *game, void *f, void *p, void *s, void *sp)
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
				mlx_image_to_window(game->mlx_ptr, f, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx_ptr, p, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx_ptr, s, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_image_to_window(game->mlx_ptr, sp, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	_fill_map1(t_solong *game, void *f, void *p, void *s, void *w, void *sp)
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
				mlx_image_to_window(game->mlx_ptr, sp, j * 64, i * 64);
			else
				mlx_image_to_window(game->mlx_ptr, w, j * 64, i * 64);
			j++;
		}
		i++;
	}
	_fill_map2(game, f, p, s, sp);
}

void	load_textures(t_solong *game)
{
	void	*fruit;
	void	*player;
	void	*ship;
	void	*wall;
	void	*space;
	void	*fruit_load;
	void	*player_load;
	void	*ship_load;
	void	*wall_load;
	void	*space_load;

	fruit = mlx_load_png("./textures/fruit.png");
	player = mlx_load_png("./textures/marshall.png");
	ship = mlx_load_png("./textures/ship.png");
	wall = mlx_load_png("./textures/wall.png");
	space = mlx_load_png("./textures/space.png");
	fruit_load = mlx_texture_to_image(game->mlx_ptr, fruit);
	player_load = mlx_texture_to_image(game->mlx_ptr, player);
	ship_load = mlx_texture_to_image(game->mlx_ptr, ship);
	wall_load = mlx_texture_to_image(game->mlx_ptr, wall);
	space_load = mlx_texture_to_image(game->mlx_ptr, space);
	_fill_map1(game, fruit_load, player_load, ship_load, wall_load, space_load);
}

void	game_init(t_solong *game)
{
	game->mlx_ptr = mlx_init(game->width * 64, game->height * 64, "so_long", true);
	load_textures(game);
	mlx_loop(game->mlx_ptr);
}
