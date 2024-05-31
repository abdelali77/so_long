/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:48:05 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/31 16:55:32 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_arr(t_solong *game)
{
	int	n;

	if (!game->map)
		return ;
	n = 0;
	while (game->map[n])
	{
		free(game->map[n]);
		n++;
	}
	free(game->map);
}

void	ft_free(t_solong *game)
{
	if (game->str != NULL)
		free(game->str);
	if (game->map != NULL)
		free_arr(game);
	free(game);
}

void	ft_exit(t_solong *game)
{
	ft_printf("map must contain 1 E, at least 1 C, and 1 P\n");
	ft_free(game);
	exit(1);
}

void	textures_err(t_solong *game)
{
	ft_printf("Error\n");
	if (game->fruit)
		mlx_delete_texture(game->fruit);
	if (game->ship)
		mlx_delete_texture(game->ship);
	if (game->wall)
		mlx_delete_texture(game->wall);
	if (game->player)
		mlx_delete_texture(game->player);
	if (game->space)
		mlx_delete_texture(game->space);
	if (game->enemy)
		mlx_delete_texture(game->enemy);
	if (game->enemy_r)
		mlx_delete_texture(game->enemy_r);
	ft_free(game);
	exit(1);
}

void	free_textures(t_solong *game)
{
	mlx_delete_texture(game->fruit);
	mlx_delete_texture(game->ship);
	mlx_delete_texture(game->wall);
	mlx_delete_texture(game->player);
	mlx_delete_texture(game->space);
	mlx_delete_texture(game->enemy);
	mlx_delete_texture(game->enemy_r);
	mlx_close_window(game->mlx_ptr);
}
