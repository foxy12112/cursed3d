/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:19:22 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/30 17:54:34 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->duplicated_map[i])
	{
		j = 0;
		while (map->duplicated_map[i][j])
		{
			if (map->duplicated_map[i][j] == 'N'
				|| map->duplicated_map[i][j] == 'S'
				|| map->duplicated_map[i][j] == 'W'
				|| map->duplicated_map[i][j] == 'E')
			{
				map->x = j;
				map->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_angle(t_mlx *mlx)
{
	char	c;

	c = mlx->map->duplicated_map[mlx->map->y][mlx->map->x];
	if (c == 'N')
		mlx->ply->angle = 3 * M_PI / 2;
	if (c == 'S')
		mlx->ply->angle = M_PI / 2;
	if (c == 'E')
		mlx->ply->angle = 0;
	if (c == 'W')
		mlx->ply->angle = M_PI;
	mlx->ply->plyr_x = (mlx->map->x * 32) + 32 / 2;
	mlx->ply->plyr_y = (mlx->map->y * 32) + 32 / 2;
	mlx->ply->fov_rd = (60 * M_PI / 180);
}

void	move_player(t_mlx *mlx, double move_x, double move_y)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;

	new_x = roundf(mlx->ply->plyr_x + move_x);
	new_y = roundf(mlx->ply->plyr_y + move_y);
	map_grid_x = (new_x / 32);
	map_grid_y = (new_y / 32);
	if (mlx->map->duplicated_map[map_grid_y][map_grid_x] != '1' && \
	(mlx->map->duplicated_map[map_grid_y][mlx->ply->plyr_x / 32] != '1' && \
	mlx->map->duplicated_map[mlx->ply->plyr_y / 32][map_grid_x] != '1'))
	{
		mlx->ply->plyr_x = new_x;
		mlx->ply->plyr_y = new_y;
	}
}

void	ft_turn_player(t_mlx *mlx, int i)
{
	if (i == 1)
	{
		mlx->ply->angle += 0.045;
		if (mlx->ply->angle > 2 * M_PI)
			mlx->ply->angle -= 2 * M_PI;
	}
	else
	{
		mlx->ply->angle -= 0.045;
		if (mlx->ply->angle < 0)
			mlx->ply->angle += 2 * M_PI;
	}
}

void	ft_hook(t_mlx *mlx, double move_x, double move_y)
{
	if (mlx->ply->rot == 1)
		ft_turn_player(mlx, 1);
	if (mlx->ply->rot == -1)
		ft_turn_player(mlx, 0);
	if (mlx->ply->l_r == 1)
	{
		move_x = -sin(mlx->ply->angle) * 4;
		move_y = cos(mlx->ply->angle) * 4;
	}
	if (mlx->ply->l_r == -1)
	{
		move_x = sin(mlx->ply->angle) * 4;
		move_y = -cos(mlx->ply->angle) * 4;
	}
	if (mlx->ply->u_d == 1)
	{
		move_x = cos(mlx->ply->angle) * 4;
		move_y = sin(mlx->ply->angle) * 4;
	}
	if (mlx->ply->u_d == -1)
	{
		move_x = -cos(mlx->ply->angle) * 4;
		move_y = -sin(mlx->ply->angle) * 4;
	}
	move_player(mlx, move_x, move_y);
}
