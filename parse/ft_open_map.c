/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:23:06 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/03/17 08:24:16 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_up(t_map *map)
{
	free(map->player);
	free(map->show);
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

char	*ft_split_map_while(int fd, char *line, t_map *map, char *temp)
{
	int	ret;

	while (1)
	{
		line = ft_calloc(1, BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		ret = read(fd, line, BUFFER_SIZE);
		if (ret <= 0)
		{
			free(line);
			break ;
		}
		temp = map->str;
		map->str = ft_strjoin(map->str, line);
		free(temp);
		free(line);
	}
	return (map->str);
}

char	**ft_split_map(int fd, t_map *map)
{
	char	*line;
	char	*temp;
	char	**map_splited;
	int		total_chars;

	line = NULL;
	temp = NULL;
	map->str = ft_calloc(1, 1);
	map->str = ft_split_map_while(fd, line, map, temp);
	total_chars = ft_strlen(map->str);
	if (total_chars == 0)
		return (NULL);
	map_splited = ft_split(map->str, '\n');
	if (!map_splited)
		return (free(map->str), NULL);
	return (map_splited);
}