/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:01:28 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/27 20:37:35 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
// # include "./MLX42/include/MLX42/MLX42.h"
# define MAP_INSIDE "02NSEW"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>	
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include "MLX/MLX42.h"
# define MAP_CHARS "012NSEW"


typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	double	angle;
	float	fov_rd;
	int		rot;
	int		l_r;
	int		u_d;
	int		m_x;
	int		m_y;
}	t_player;

typedef struct s_ray
{
	int		index;
	double	ray_ngl;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_tex
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}	t_tex;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	// t_data			*dt;
	t_ray			*ray;
	t_player		*ply;
	t_tex			*tex;
	// t_txtr			*l_ture;
	mouse_mode_t	mouse_mode;
}	t_mlx;

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
int		ft_get_map(t_map *map);
char	**copy_map(char **input_array, int size, int *ik);

int ft_get_north(t_map *map , char *str);
int ft_get_south(t_map *map , char *str);
int ft_get_west(t_map *map , char *str);
int ft_get_east(t_map *map , char *str);
int	get_wall(t_map *map, char **str, int *i, int *count);

int	ft_get_floor(t_map *map, char *str);
int	ft_get_ceiling(t_map *map, char *str);
int	get_fc(t_map *map, char **str, int *i, int *count);

int	check_closed_map(char **str);
int	ft_valid_wall(char **str);
int	ft_check(t_map *map, int *i, int *count);
int	valid_components(t_map *map);

int	ft_isspace(char c);
int	check_char(t_map *map, char c);
int	ft_empty_line(char *str);
int	ft_size(t_map *map, int *i);


int	ft_textures(t_map *map, char **textures, int *i, int *count);
int ft_check_wall(char *str);
int check_edges(char *str);
int	check_all_sides(char **strs, int j);


#endif