/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:07:39 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/16 20:00:43 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *arg)
{
	int			fd;
	t_solong	st;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		print_err();
	while ((st.line = get_next_line(fd)))
	{
		st.str = ft_strjoin(st.str, st.line);
		free(st.line);
	}
	_check(st.str);
	st.map = ft_split(st.str, '\n');
	free(st.str);
	check_len(st.map);
	if (!check_walls(st.map))
	{
		ft_printf("Error, Map is not surrounded by walls\n");
		free_arr(st.map);
		exit(1);
	}
	player_pos(st.map);
	free_arr(st.map);
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
		ft_printf("Usage: ./so_long *.ber\n");
	return (0);
}
