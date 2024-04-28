/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:01:26 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/27 20:17:39 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_position(t_map *map)
{
	int i = 0;
	int j ;
	while (map->duplicated_map[i])
	{
		j = 0;
		while (map->duplicated_map[i][j])
		{
			if (map->duplicated_map[i][j] == 'N')
			{
				map->x = i;
				map->y = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

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
			map->colums = j;
		i++;
	}
	map->rows = i;
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
	{
		printf("\n III =  %i \n", i);
		return (0);
	}
	
	player_position(map);
	get_cols_rows(map);
	// printf("\n text 1 : %d \n", map->rows);
	// printf("\n text 2 : %d \n", map->colums);
	// printf("\n text 3 : %s \n", map->text_we);
	// printf("\n text 4 : %s \n", map->text_ea);
	// printf("\n text 5 : %s \n", map->text_f);
	// printf("\n text 6 : %s \n", map->text_c);
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

	i = 0;
	map = (struct s_map *)malloc(sizeof(struct s_map));
	if (!map)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	ft_open_map(argc, argv, map);
	ft_get_map(map);
	// i = 0;
	// while (map->map_splited[i] != NULL)
	// {
	// 	printf("%s", map->map_splited[i]);
	// 	i++;
	// }
	ft_parse_map(map);
	clean_up(map);
	return (0);
}
