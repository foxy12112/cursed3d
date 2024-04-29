/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:02:40 by rallouan          #+#    #+#             */
/*   Updated: 2024/04/29 22:24:48 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_free_all(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (list);
}

void	clean_up(t_map *map)
{
	ft_free_all(map->duplicated_map);
	ft_free_all(map->map_splited);
	ft_free_all(map->text_f);
	ft_free_all(map->text_c);
	free(map->text_no);
	free(map->text_so);
	free(map->text_we);
	free(map->text_ea);
	free(map);
}

void	ft_exit(t_mlx *mlx)
{
	clean_up(mlx->map);
	free(mlx->ply);
	free(mlx->ray);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	mlx_terminate(mlx->mlx_p);
	printf("Game closed\n");
	exit(0);
}
