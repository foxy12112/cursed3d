/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:23:06 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/04 16:25:33 by mbelhaj-         ###   ########.fr       */
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

