/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:48:05 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/18 10:23:32 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **split)
{
	int	n;

	if (!split)
		return ;
	n = 0;
	while (split[n])
	{
		free(split[n]);
		n++;
	}
	free(split);
}

void	ft_exit(char *s)
{
	ft_printf("Error! Map not valid\n");
	free(s);
	exit(1);
}

void	ft_free(t_solong *st)
{
	free_arr(st->map);
	exit(1);
}
