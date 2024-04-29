/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:23:06 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 19:28:21 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_up(t_map *map)
{
	// free(map->player);
	// free(map->show);
	free(map);
}

int	check_map_extension(char *filename, char *extension)
{
	int	filename_len;
	int	extension_len;

	filename_len = ft_strlen(filename) - 4;
	extension_len = ft_strlen(extension);
	if (filename_len < extension_len)
		return (0);
	if (ft_strncmp(filename + (filename_len - extension_len), extension, 4))
		return (1);
	return (0);
}

void	ft_open_map(int argc, char *argv[], t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	if (argc != 2 || check_map_extension(argv[1], ".cub") == 1 || map->fd < 0)
	{
		ft_putstr_fd("ERROR : INVALID FILE", 2);
		exit(1);
	}
	else
	{
		ft_putstr_fd("VALID FILE\n", 2);
	}
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
	while (!ft_strncmp(input_array[*ik] ,"\n", 2) || !ft_empty_line(input_array[*ik]))
		(*ik)++;
	while (input_array[(*ik)])
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
		printf("ik= %d\n", (*ik));
	duplicate_array[size] = NULL;
	return (duplicate_array);
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
