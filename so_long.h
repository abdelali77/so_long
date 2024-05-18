/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:00:31 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/18 16:32:06 by abmahfou         ###   ########.fr       */
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
	void		*mlx_ptr;
	char		**map;
	char		*line;
	char		*str;
	mlx_image_t	*marshall;
	int			collectible;
	int			e;
	int			c;
	int			exit;
	int			player;
	int			width;
	int			height;
	int			x;
	int			y;
}	t_solong;

bool	check_extension(char *arg);
char	**ft_split(char const *s, char c);
void	check_len(t_solong *game);
bool	check_walls(char **map);
void	_check(t_solong *game);
void	print_err(void);
int		arr_len(char **arr);
void	free_arr(char **split);
void	ft_exit(char *s);
void	flood_fill(t_solong *st, int x, int y);
void	player_pos(t_solong *game);
void	flood_check(t_solong *game, int	c, int e);
void	game_init(t_solong *game);
void	ft_free(t_solong *st);

#endif