/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:23:06 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/30 18:22:33 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_extension(char *argv)
{
	char	**path;
	char	**name;
	int		i;

	path = ft_split(argv, '/');
	if (!path || !*path)
		return (0);
	i = 0;
	while (path[i])
		i++;
	if (path[i - 1][ft_strlen(path[i - 1]) - 1] == '.')
		return (ft_free_all(path), 0);
	name = ft_split(path[i - 1], '.');
	if (!name || !*name)
		return (ft_free_all(path), 0);
	ft_free_all(path);
	if (ft_strlen(name[1]) == 3
		&& ft_strncmp(name[1], "cub", ft_strlen(name[1])) == 0 && !name[2])
	{
		ft_free_all(name);
		return (1);
	}
	ft_free_all(name);
	return (0);
}

void	ft_open_map(int argc, char *argv[], t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	if (argc != 2 || !check_map_extension(argv[1]) || map->fd < 0)
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
	int		i;
	char	**duplicate_array;

	duplicate_array = (char **)malloc((size + 1) * sizeof(char *));
	if (!duplicate_array)
		return (NULL);
	i = 0;
	while (!ft_strncmp(input_array[*ik], "\n", 2)
		|| !ft_empty_line(input_array[*ik]))
		(*ik)++;
	while (input_array[(*ik)])
	{
		duplicate_array[i] = ft_strdup(input_array[(*ik)]);
		if (!duplicate_array[i])
		{
			ft_free_all(duplicate_array);
			return (NULL);
		}
		i++;
		(*ik)++;
	}
	duplicate_array[size] = NULL;
	return (duplicate_array);
}

int	ft_get_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	map->map_splited = (char **)malloc(sizeof(char *) * 2);
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		map->map_splited[i] = line;
		i++;
		map->map_splited = (char **)
			realloc(map->map_splited, sizeof(char *) * (i + 1));
		if (!map->map_splited)
		{
			perror("Memory allocation error");
			clean_up(map);
			exit(EXIT_FAILURE);
		}
		line = get_next_line(map->fd);
	}
	map->map_splited[i] = NULL;
	return (1);
}
