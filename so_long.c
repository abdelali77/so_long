/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:07:39 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/14 19:36:05 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *arg)
{
	int		fd;
	char	**map;
	char	*line;
	char	*str;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		print_err();
	while ((line = get_next_line(fd)))
	{
		str = ft_strjoin(str, line);
		free(line);
	}
	_check(str);
	map = ft_split(str, '\n');
	check_len(map);
	if (!check_walls(map))
	{
		ft_printf("Error, Map is not surrounded by walls\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!check_extension(av[1]))
			print_err();
		read_map(av[1]);
	}
	else
		ft_printf("Usage: ./so_long namefile.ber\n");
	return (0);
}
