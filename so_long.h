/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:00:31 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/14 20:05:49 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "./printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_solong
{
	int	space;
	int	collectible;
	int	exit;
	int	player;
}	t_solong;

bool	check_extension(char *arg);
char	**ft_split(char const *s, char c);
void	check_len(char **map);
bool	check_walls(char **map);
void	_check(char *map);
void	print_err(void);
int		arr_len(char **arr);

#endif