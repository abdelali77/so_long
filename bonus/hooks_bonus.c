/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:52:08 by abmahfou          #+#    #+#             */
/*   Updated: 2024/06/01 13:14:12 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	close_win(void *param)
{
	t_solong	*game;

	game = param;
	free_textures(game);
}

void	_animate_enemy(void *param)
{
	t_solong	*game;
	static int	timer;

	game = param;
	if (timer == 10)
		fill_map(game, 1);
	else if (timer == 50)
		fill_map(game, 0);
	else if (timer == 90)
		fill_map(game, 1);
	else if (timer == 91)
		timer = 0;
	timer++;
}
