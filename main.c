/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:01:26 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/03/22 09:25:15 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	ft_textures(t_map *map, char **textures, int *i, int *count)
{
	if (!get_wall(map, textures, i, count))
		return (0);
	if (!get_fc(map, textures, i, count))
		return (0);
	return (1);
}

int	check_char(t_map *map, char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	else if  (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		map->count_p++;
		return (1);
	}
	return (0);
}

int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int		check_all_sides(char **strs, int j)
{
	if (ft_isspace(strs[-1][j - 1]) || !strs[-1][j - 1])
		return (0);
	if (ft_isspace(strs[-1][j]) || !strs[-1][j])
		return (0);
	if (ft_isspace(strs[-1][j + 1]) || !strs[-1][j + 1])
		return (0);
	if (ft_isspace(strs[0][j - 1]) || !strs[0][j - 1])
		return (0);
	if (ft_isspace(strs[0][j + 1]) || !strs[0][j + 1])
		return (0);
	if (ft_isspace(strs[1][j - 1]) || !strs[1][j - 1])
		return (0);
	if (ft_isspace(strs[1][j]) || !strs[1][j])
		return (0);
	if (ft_isspace(strs[1][j + 1]) || !strs[1][j + 1])
		return (0);
	return (1);
}

int		checkmapclosed(char **strs)
{
	int j;

	j = 0;
	while (strs[0][j])
	{
		if (ft_strchr(MAP_INSIDE, strs[0][j]))
		{
			if (!check_all_sides(strs, j))
				return (0);
		}
		j++;
	}
	return (1);
}




int	valid_components(t_map *map, int j)
{
	int	y;
	int	x;

	y = j;
	while (map->map_splited[y])
	{
		x = 0;
		while (map->map_splited[y][x])
		{
			if (!check_char(map,map->map_splited[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	**copy_map(char **input_array, int size, int *ik)
{
	int		j;
	int		i;
	char	**duplicate_array;
	
	duplicate_array = (char **)malloc((size + 1) * sizeof(char *));
	if (!duplicate_array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		duplicate_array[i] = ft_strdup(input_array[(*ik)]);
		if (!duplicate_array[i])
		{
			j = 0;
			while (j < i)
			{
				free(duplicate_array[j]);
				j++;
			}
			return (free(duplicate_array), NULL);
		}
		i++;
		(*ik)++;
	}
	duplicate_array[size] = NULL;
	return (duplicate_array);
}

int ft_size(t_map *map, int *i)
{
	int j = (*i);
	while (map->map_splited[j] != (void *) 0)
	{
		j++;
	}
	return(j - (*i));
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
	j = (*i);
	if (valid_components(map, j) && map->count_p == 1)
	{
		printf("\n Valid \n");
	}
	else
	{
		printf("\nNOT Valid ---- \n");
	}
	j = ft_size(map,i);
	map->duplicated_map = copy_map(map->map_splited, j, i);
	
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
	// printf("\n text 1 : %s \n", map->text_no);
	// printf("\n text 2 : %s \n", map->text_so);
	// printf("\n text 3 : %s \n", map->text_we);
	// printf("\n text 4 : %s \n", map->text_ea);
	// printf("\n text 5 : %s \n", map->text_f);
	// printf("\n text 6 : %s \n", map->text_c);
	return (1);
}
void print_map(char **map_splited) {
    int i = 0;
    while (map_splited[i] != NULL) {
        int j = 0;
        while (map_splited[i][j] != '\0') {
            printf("%c", map_splited[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (struct s_map *)malloc(sizeof(struct s_map));
	if (!map)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	map->player = (struct s_player *)malloc(sizeof(struct s_player));
	map->show = (struct s_show *)malloc(sizeof(struct s_show));
	if (!map->player || !map->show)
	{
		perror("Memory allocation error");
		clean_up(map);
		exit(EXIT_FAILURE);
	}
	ft_open_map(argc, argv, map);
	map->map_splited = ft_split_map(map->fd, map);
	print_map(map->map_splited);
	ft_parse_map(map);
	print_map(map->duplicated_map);
	return (0);
}
