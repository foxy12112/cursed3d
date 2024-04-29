/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:01:26 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 22:19:05 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game(t_map *map)
{
	t_mlx	mlx;

	mlx.ply = (t_player *)ft_calloc(sizeof(t_player), 1);
	mlx.ray = (t_ray *)ft_calloc(sizeof(t_ray), 1);
	mlx.tex = (t_tex *)ft_calloc(sizeof(t_tex), 1);
	mlx.map = map;
	mlx.mlx_p = mlx_init(1900, 1000, "cub3D", false);
	if (!mlx.mlx_p)
		ft_exit(&mlx);
	if (!load_img(mlx.tex, map))
		ft_exit(&mlx);
	get_angle(&mlx);
	mlx_key_hook(mlx.mlx_p, &ft_key, &mlx);
	mlx_loop_hook(mlx.mlx_p, &draw_map_pixel, &mlx);
	mlx_loop(mlx.mlx_p);
	ft_exit(&mlx);
	return (1);
}

int	ft_parse_map(t_map *map)
{
	int	i;
	int	count;
	int	count_e;

	map->count_p = 0;
	count_e = 0;
	i = 0;
	count = 0;
	if (!ft_check(map, &i, &count_e))
		return (clean_up(map), 0);
	player_position(map);
	get_cols_rows(map);
	ft_game(map);
	return (1);
}

void	print_map(char **map_splited)
{
	int	i;

	i = 0;
	while (map_splited[i] != NULL)
	{
		printf("%s", map_splited[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	if (argc == 2)
	{
		i = 0;
		map = (struct s_map *)malloc(sizeof(struct s_map));
		if (!map)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		ft_open_map(argc, argv, map);
		ft_get_map(map);
		ft_parse_map(map);
	}
	else
		printf("Error\n");
	return (0);
}
