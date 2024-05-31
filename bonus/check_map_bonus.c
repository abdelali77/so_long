/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:34:07 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/31 15:27:46 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	check_len(t_solong *game)
{
	int		i;
	size_t	len;

	if (!game->map)
		return ;
	i = 0;
	len = ft_strlen(game->map[i]);
	game->width = len;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
		{
			ft_printf("Error, map is not rectangular\n");
			ft_free(game);
			exit(1);
		}
		i++;
	}
	game->height = i;
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

void	_extra_check(t_solong *game)
{
	int	i;

	i = 0;
	while (game->str[i])
	{
		if (game->str[0] == '\n' || (game->str[i] == '\n'
				&& game->str[i + 1] == '\n')
			|| game->str[ft_strlen(game->str) - 1] == '\n')
			ft_exit(game);
		if (game->str[i] != '1' && game->str[i] != '0' 
			&& game->str[i] != 'C' && game->str[i] != 'E' 
			&& game->str[i] != 'P' && game->str[i] != '\n'
			&& game->str[i] != 'X')
			ft_exit(game);
		i++;
	}
}

void	_check(t_solong *game)
{
	int	i;

	if (!game->str)
		empty_map(game);
	i = 0;
	while (game->str[i] != '\0')
	{
		if (game->str[i] == 'C')
			game->collectible++;
		else if (game->str[i] == 'E')
			game->exit++;
		else if (game->str[i] == 'P')
			game->p++;
		else if (game->str[i] == '0')
			game->s++;
		else if (game->str[i] == 'X')
			game->enemy_count++;
		_extra_check(game);
		i++;
	}
	if (!(game->collectible >= 1 && game->exit == 1 && game->p == 1
			&& game->s >= 1 && game->enemy_count >= 1))
		ft_exit(game);
}
