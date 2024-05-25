/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:48:05 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/24 21:56:19 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_exit(t_solong *game)
{
	ft_printf("Error! Map not valid\n");
	free(game->str);
	free(game);
	exit(1);
}

void	ft_free(t_solong *st)
{
	free_arr(st);
	free(st->str);
	free(st);
}

void	free_textures(t_solong *game)
{
	mlx_delete_texture(game->fruit);
	mlx_delete_texture(game->ship);
	mlx_delete_texture(game->wall);
	mlx_delete_texture(game->player);
	mlx_delete_texture(game->space);
	mlx_close_window(game->mlx_ptr);
}
