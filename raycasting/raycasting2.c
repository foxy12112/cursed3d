/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:15:27 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 20:53:16 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
	int		i;
	int		c;

	i = b_pix;
	c = get_rgba(ft_atoi(mlx->map->text_f[0]), ft_atoi(mlx->map->text_f[1]), \
		ft_atoi(mlx->map->text_f[2]), 255);
	while (i < 1000)
		my_mlx_pixel_put(mlx, ray, i++, c);
	c = get_rgba(ft_atoi(mlx->map->text_c[0]), ft_atoi(mlx->map->text_c[1]), \
		ft_atoi(mlx->map->text_c[2]), 255);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(mlx, ray, i++, c);
}

double	get_x_o(mlx_texture_t	*texture, t_mlx *mlx)
{
	double	x_o;

	if (mlx->ray->flag == 1)
		x_o = (int)fmodf((mlx->ray->horiz_x * \
		(texture->width / 32)), texture->width);
	else
		x_o = (int)fmodf((mlx->ray->vert_y * \
		(texture->width / 32)), texture->width);
	return (x_o);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

mlx_texture_t	*get_texture(t_mlx *mlx, int flag)
{
	mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl);
	if (flag == 0)
	{
		if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
			return (mlx->tex->ea);
		else
			return (mlx->tex->we);
	}
	else
	{
		if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
			return (mlx->tex->so);
		else
			return (mlx->tex->no);
	}
}

void	draw_wall(t_mlx *mlx, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_texture(mlx, mlx->ray->flag);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, mlx);
	y_o = (t_pix - (1000 / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		my_mlx_pixel_put(mlx, mlx->ray->index, t_pix, reverse_bytes \
		(arr[(int)y_o * texture->width + (int)x_o]));
		y_o += factor;
		t_pix++;
	}
}
