/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:53:38 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/30 18:23:15 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_closed_map(char **str)
{
	int	j;

	j = 0;
	while (str[0][j])
	{
		if (ft_strchr(MAP_INSIDE, str[0][j]))
		{
			if (!check_all_sides(str, j))
				return (printf("Error\n"), 0);
		}
		j++;
	}
	return (1);
}

int	ft_valid_wall2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (!ft_empty_line(str[i]))
			i++;
		if (!check_edges(str[i]))
			return (printf("Error\n"), 0);
		i++;
	}
	i = 0;
	while (!ft_empty_line(str[i]))
		i++;
	while (str[i])
	{
		if (!check_closed_map(&str[i]))
			return (printf("Error\n"), 0);
		i++;
	}
	return (ft_valid_wall2(str));
}

int	ft_valid_wall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (!ft_empty_line(str[i]))
			i++;
		if (!ft_check_wall(str[i]))
			return (printf("Error\n"), 0);
		while (str[i] != NULL && ft_empty_line(str[i]))
			i++;
		if (!ft_check_wall(str[i - 1]))
			return (printf("Error\n"), 0);
	}
	return (1);
}

int	valid_components(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->duplicated_map[y])
	{
		x = 0;
		while (map->duplicated_map[y][x])
		{
			if (!check_char(map, map->duplicated_map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check(t_map *map, int *i, int *count)
{
	int	j;

	while (map->map_splited[(*i)] && (*count) < 6)
		if (!ft_textures(map, map->map_splited, i, count))
			return (clean_up(map), 0);
	j = ft_size(map, i);
	map->duplicated_map = (char **)malloc((j + 1) * sizeof(char *));
	if (map->duplicated_map == NULL)
		return (clean_up(map), 0);
	map->duplicated_map = copy_map(map->map_splited, j, i);
	if (! valid_components(map) && map->count_p != 1)
		return (clean_up(map), 0);
	if (!ft_valid_wall(map->duplicated_map))
		return (clean_up(map), 0);
	return (1);
}
