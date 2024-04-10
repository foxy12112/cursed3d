/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:01:26 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/10 19:11:23 by mbelhaj-         ###   ########.fr       */
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

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	check_char(t_map *map, char c)
{
	if (ft_isspace(c) || c == '0' || c == '1')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		map->count_p++;
		return (1);
	}
	return (0);
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

int	ft_size(t_map *map, int *i)
{
	int	j;

	j = (*i);
	while (map->map_splited[j] != (void *)0)
	{
		j++;
	}
	return (j - (*i));
}

int ft_check_wall(char *str)
{
	int i =0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] != '1')
			return(0);
		i++;
	}
	return(1);
}


int ft_empty_line(char *str)
{
	int i  = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return(1);		
		i++;
	}
	return(0);
}

int check_edges(char *str)
{
	int i = 0;
	int len = ft_strlen(str);
	
	while(ft_isspace(str[i]))
		i++;
	if (str[i] != '1' || str[len - 2] != '1')
		return(0);
	return(1);
}

int ft_valid_wall(char **str)
{
	int i = 0;
	// int j = 0;
	while (str[i])
	{
		while (!ft_empty_line(str[i]))
			i++;
		if (!ft_check_wall(str[i]))
			return(0);
		while (str[i] != NULL && ft_empty_line(str[i]))
			i++;
		if (!ft_check_wall(str[i - 1]))
			return(0);

	}
	i = 0;
	while (str[i])
	{
		
	while (!ft_empty_line(str[i]))
		i++;
	if (!check_edges(str[i]))
		return(0);
	i++;
	}
	return(1);	
}
// printf("\n%s\n",str[i]);

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
    	return 0;
    }
	map->duplicated_map = copy_map(map->map_splited, j, i);
	if (valid_components(map) && map->count_p == 1)
	{
		printf("\n Valid \n");
	}
	else
	{
		printf("\nNOT Valid ---- ft_check \n");
	}
	if (!ft_valid_wall(map->duplicated_map))
	{
		printf("\n invalid map ft_valid_map \n");
	}	
	
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

int	ft_get_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	map->map_splited = (char **)malloc(sizeof(char *) * 2);
	while ((line = get_next_line(map->fd)) != NULL)
	{
		map->map_splited[i] = line;
		i++;
		map->map_splited = (char **)realloc(map->map_splited, sizeof(char *) * (i + 1));
		if (!map->map_splited)
		{
			perror("Memory allocation error");
			clean_up(map);
			exit(EXIT_FAILURE);
		}
	}
	map->map_splited[i] = NULL;
	return (1);
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
	map->player = (struct s_player *)malloc(sizeof(struct s_player));
	map->show = (struct s_show *)malloc(sizeof(struct s_show));
	if (!map->player || !map->show)
	{
		perror("Memory allocation error");
		clean_up(map);
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
	// print_map(map->duplicated_map);
	return (0);
}
