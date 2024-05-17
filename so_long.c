/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:07:39 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/17 19:15:00 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *arg, t_solong *game)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		print_err();
	while ((game->line = get_next_line(fd)))
	{
		game->str = ft_strjoin(game->str, game->line);
		free(game->line);
	}
	_check(game);
	game->map = ft_split(game->str, '\n');
	free(game->str);
	check_len(game->map);
	if (!check_walls(game->map))
	{
		ft_printf("Error, Map is not surrounded by walls\n");
		free_arr(game->map);
		exit(1);
	}
	player_pos(game->map, game);
	flood_fill(game, game->x, game->y);
	flood_check(game, game->c, game->e);
	free_arr(game->map);
}

// void leaks(){system("leaks so_long");}

int	main(int ac, char **av)
{
	// atexit(leaks);
	t_solong	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_solong));
		if (!check_extension(av[1]))
			print_err();
		read_map(av[1], game);
		free(game);
	}
	else
		ft_printf("Usage: ./so_long *.ber\n");
	return (0);
}
