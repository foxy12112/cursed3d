/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:01:28 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 22:24:18 by rallouan         ###   ########.fr       */
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
# include <math.h>
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
	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	char		**text_f;
	char		**text_c;
	int			moves;
}				t_map;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	t_map			*map;
	t_ray			*ray;
	t_player		*ply;
	t_tex			*tex;
	mouse_mode_t	mouse_mode;
}	t_mlx;

void			clean_up(t_map *map);
int				check_map_extension(char *filename, char *extension);
void			ft_open_map(int argc, char *argv[], t_map *map);
int				ft_get_map(t_map *map);
char			**copy_map(char **input_array, int size, int *ik);

int				ft_get_north(t_map *map, char *str);
int				ft_get_south(t_map *map, char *str);
int				ft_get_west(t_map *map, char *str);
int				ft_get_east(t_map *map, char *str);
int				get_wall(t_map *map, char **str, int *i, int *count);

int				ft_get_floor(t_map *map, char *str);
int				ft_get_ceiling(t_map *map, char *str);
int				get_fc(t_map *map, char **str, int *i, int *count);
int				ft_no_so(t_map *map, char **str, int *i, int *count);

int				check_closed_map(char **str);
int				ft_valid_wall(char **str);
int				ft_check(t_map *map, int *i, int *count);
int				valid_components(t_map *map);

int				ft_isspace(char c);
int				check_char(t_map *map, char c);
int				ft_empty_line(char *str);
int				ft_size(t_map *map, int *i);

int				ft_textures(t_map *map, char **textures, int *i, int *count);
int				ft_check_wall(char *str);
int				check_edges(char *str);
int				check_all_sides(char **strs, int j);

int				load_img(t_tex *tex, t_map *map);
char			*get_png(char *str);
int				get_rgba(int r, int g, int b, int a);

void			get_angle(t_mlx *mlx);
void			move_player(t_mlx *mlx, double move_x, double move_y);
void			rotate_player(t_mlx *mlx, int i);
void			cub_hook(t_mlx *mlx, double move_x, double move_y);
void			player_position(t_map *map);

void			ft_reles(mlx_key_data_t keydata, t_mlx *mlx);
void			ft_key(mlx_key_data_t keydata, void *ml);

void			draw_map_pixel(void *mlxl);
void			cast_rays(t_mlx *mlx);
void			render_wall(t_mlx *mlx, int ray);
float			get_v_inter(t_mlx *mlx, float angl);
float			get_h_inter(t_mlx *mlx, float angl);

void			draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix);
double			get_x_o(mlx_texture_t	*texture, t_mlx *mlx);
float			nor_angle(float angle);
mlx_texture_t	*get_texture(t_mlx *mlx, int flag);
void			draw_wall(t_mlx *mlx, int t_pix, int b_pix, double wall_h);

int				unit_circle(float angle, char c);
int				inter_check(float angle, float *inter,
					float *step, int is_horizon);
int				wall_hit(float x, float y, t_mlx *mlx);

int				get_cols_rows(t_map *map);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int				reverse_bytes(int c);

void			*ft_free_all(char **list);
void			ft_exit(t_mlx *mlx);

#endif