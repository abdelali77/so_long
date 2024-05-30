/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:59:55 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/29 16:40:40 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_error(t_solong *game)
{
	ft_printf("Error\n");
	ft_free(game);
	exit(1);
}

void	check_rect(t_solong *game)
{
	ft_printf("Error, Map is not surrounded by walls\n");
	ft_free(game);
	exit(1);
}

void	empty_map(t_solong *game)
{
	ft_printf("Map Empty !!\n");
	ft_free(game);
	exit(1);
}
