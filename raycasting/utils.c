/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:15:22 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 20:54:29 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_cols_rows(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->duplicated_map[i])
	{
		j = 0;
		while (map->duplicated_map[i][j])
			j++;
		if (j > map->colums)
			map->colums = j - 1;
		i++;
	}
	map->rows = i ;
	return (1);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= 1900)
		return ;
	if (y < 0)
		return ;
	else if (y >= 1000)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}
