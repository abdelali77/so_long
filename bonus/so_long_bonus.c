/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:07:39 by abmahfou          #+#    #+#             */
/*   Updated: 2024/06/01 13:06:19 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	vars_init(t_solong *game)
{
	game->p = 0;
	game->exit_count = 0;
	game->coll_count = 0;
	game->exit = 0;
	game->collectible = 0;
	game->enemy_count = 0;
	game->str = NULL;
	game->map = NULL;
}

void	read_map(char *arg, t_solong *game)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		_error(game);
	while (1)
	{
		game->line = get_next_line(fd);
		if (!game->line)
			break ;
		game->str = ft_strjoin(game->str, game->line);
		free(game->line);
	}
	_check(game);
	game->map = ft_split(game->str, '\n');
	is_rectangular(game);
	if (!check_walls(game->map))
		wall_err(game);
	player_pos(game);
	flood_fill(game, game->pos_x, game->pos_y);
	check_path(game, game->coll_count, game->exit_count);
	game->map = ft_split(game->str, '\n');
}

int	main(int ac, char **av)
{
	t_solong	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_solong));
		if (!game)
			return (ft_printf("Error\n"), 1);
		vars_init(game);
		if (!check_extension(av[1]))
			_error(game);
		read_map(av[1], game);
		game_init(game);
		ft_free(game);
	}
	else
		ft_printf("Usage: ./so_long *.ber\n");
	return (0);
}
