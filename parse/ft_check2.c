/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:53:38 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/27 17:56:23 by mbelhaj-         ###   ########.fr       */
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
				return (0);
		}
		j++;
	}
	return (1);
}

int	ft_valid_wall(char **str)
{
	int	i;

	i = 0;
	// int j = 0;
	while (str[i])
	{
		while (!ft_empty_line(str[i]))
			i++;
	// printf("Error 1 :\n");
		if (!ft_check_wall(str[i]))
			return (0);
		while (str[i] != NULL && ft_empty_line(str[i]))
			i++;
		if (!ft_check_wall(str[i - 1]))
			return (0);
	}
	i = 0;
	while (str[i])
	{
		while (!ft_empty_line(str[i]))
			i++;
		if (!check_edges(str[i]))
			return (0);
		i++;
	}
	i = 0;
	while (!ft_empty_line(str[i]))
		i++;
	while (str[i])
	{
		if (!check_closed_map(&str[i]))
		{
			printf("\n not closed \n");
			return (0);
		}
		i++;
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

	while (map->map_splited[(*i)] && (*count) < 5)
	{
		if (!ft_textures(map, map->map_splited, i, count))
		{
			printf("\n ft_check NOT okay \n");
			return (0);
		}
	}
	j = ft_size(map, i);
	map->duplicated_map = (char **)malloc((j + 1) * sizeof(char *));
	if (map->duplicated_map == NULL)
	{
		printf("Memory allocation failed for duplicated_map\n");
		return (0);
	}
	map->duplicated_map = copy_map(map->map_splited, j, i);
	if (valid_components(map) && map->count_p == 1)
		printf("\n Valid \n");
	else
		printf("\nNOT Valid ---- ft_check \n");
	if (!ft_valid_wall(map->duplicated_map))
		printf("\n invalid map ft_valid_wall \n");
	return (1);
}
