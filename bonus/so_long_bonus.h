/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:00:31 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/31 16:52:54 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "../printf/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_solong
{
	mlx_t			*mlx_ptr;
	char			**map;
	char			*line;
	char			*str;
	mlx_image_t		*marshall;
	int				collectible;
	int				e;
	int				c;
	int				s;
	int				exit;
	int				p;
	int				width;
	int				height;
	int				x;
	int				y;
	int				ship_x;
	int				ship_y;
	int				moves;
	int				enemy_count;
	mlx_texture_t	*fruit;
	mlx_texture_t	*player;
	mlx_texture_t	*ship;
	mlx_texture_t	*wall;
	mlx_texture_t	*space;
	mlx_texture_t	*enemy;
	mlx_texture_t	*enemy_r;
	mlx_image_t		*fruit_load;
	mlx_image_t		*ship_load;
	mlx_image_t		*wall_load;
	mlx_image_t		*space_load;
	mlx_image_t		*enemy_load;
	mlx_image_t		*enemy_load_r;
	mlx_image_t		*move;
}	t_solong;

bool	check_extension(char *arg);
char	**ft_split(char const *s, char c);
void	check_len(t_solong *game);
bool	check_walls(char **map);
void	_check(t_solong *game);
void	_error(t_solong *game);
int		arr_len(char **arr);
void	free_arr(t_solong *game);
void	ft_exit(t_solong *game);
void	flood_fill(t_solong *st, int x, int y);
void	player_pos(t_solong *game);
void	check_path(t_solong *game, int c, int e);
void	game_init(t_solong *game);
void	ft_free(t_solong *st);
void	move_right(t_solong *game);
void	move_left(t_solong *game);
void	move_up(t_solong *game);
void	move_down(t_solong *game);
void	_fill_map1(t_solong *game);
void	check_rect(t_solong *game);
void	free_textures(t_solong *game);
void	textures_err(t_solong *game);
char	*ft_itoa(int n);
void	empty_map(t_solong *game);
void	fill_map(t_solong *game, int flag);
void	close_win(void *param);
void	_animate_coin(void *param);

#endif