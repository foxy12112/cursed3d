/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:01:28 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/05 23:24:35 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./MLX42/include/MLX42/MLX42.h"
# define MAP_INSIDE "02NSEW"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>	
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>

# define MAP_CHARS "012NSEW"

typedef struct s_show
{
	mlx_image_t		*back_ground;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
}				t_show;

typedef struct s_player
{
	int			p_x;
	int			p_y;
}				t_player;

typedef struct s_map
{
	int			fd;
	char		**map_splited;
	char		*str;
	int			x;
	int			y;
	int			line;
	int			count_p;
	char		**duplicated_map;
	int			rows;
	int			colums;
	t_show		*show;
	mlx_t		*mlx;
	t_player	*player;
	char 		*text_no;
	char 		*text_so;
	char 		*text_we;
	char 		*text_ea;
	char 		*text_f;
	char 		*text_c;
	int			moves;
	char  **tt;
}				t_map;

void	clean_up(t_map *map);
int		check_map_extension(char *filename, char *extension);
void	ft_open_map(int argc, char *argv[], t_map *map);
char	*ft_split_map_while(int fd, char *line, t_map *map, char *temp);
char	**ft_split_map(int fd, t_map *map);


int ft_get_north(t_map *map , char *str);
int ft_get_south(t_map *map , char *str);
int ft_get_west(t_map *map , char *str);
int ft_get_east(t_map *map , char *str);
int	get_wall(t_map *map, char **str, int *i, int *count);

int	ft_get_floor(t_map *map, char *str);
int	ft_get_ceiling(t_map *map, char *str);
int	get_fc(t_map *map, char **str, int *i, int *count);

#endif