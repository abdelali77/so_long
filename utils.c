/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:49:38 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/16 19:59:52 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(char **map)
{
	t_solong	st;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				st.x = j;
				st.y = i;
			}
			j++;
		}
		i++;	
	}
	ft_printf("%d %d\n", st.x, st.y);
}

/* void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1')
		return ;
} */
