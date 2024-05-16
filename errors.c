/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:59:55 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/16 16:10:26 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err()
{
	ft_printf("Error\n");
	exit(1);
}

bool	check_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '.')
		i++;
	if (i == 0)
		return (false);
	i++;
	if (arg[i] == 'b' && arg[i + 1] == 'e' && arg[i + 2] == 'r')
		return (true);
	else
		return (false);
}

void	check_len(char **map)
{
	int		i;
	size_t	len;

	if (!map)
		return ;
	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_printf("Error, map is not rectangular\n");
			free_arr(map);
			exit(1);
		}
		i++;
	}
}

bool	check_walls(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (false);
	i = 1;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j++] != '1')
			return (false);
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (false);
		i++;
	}
	j = 0;
	while (map[arr_len(map) - 1][j])
	{
		if (map[arr_len(map) - 1][j++] != '1')
			return (false);
	}
	return (true);
}

void	_check(char *map)
{
	int			i;
	t_solong	p;

	if (!map)
		return ;
	p.collectible = 0;
	p.exit = 0;
	p.player = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			p.collectible++;
		else if (map[i] == 'E')
			p.exit++;
		else if (map[i] == 'P')
			p.player++;
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n'))
			ft_exit(map);
		else if (map[i] != '1' && map[i] != '0' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			ft_exit(map);
		i++;
	}
	if (!(p.collectible >= 1 && p.exit == 1 && p.player == 1))
		ft_exit(map);
}
