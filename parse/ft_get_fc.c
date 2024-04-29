/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:40:38 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 21:56:15 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_floor(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_f = ft_split(&str[i], ',');
	if (!map->text_f)
		return (clean_up(map), 0);
	return (1);
}

int	ft_get_ceiling(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_c = ft_split(&str[i], ',');
	if (!map->text_c)
		return (clean_up(map), 0);
	return (1);
}

int	ft_check_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int	check_colors(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!ft_check_rgb(map->text_f))
		{
			printf("\n Error Colors \n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (!ft_check_rgb(map->text_c))
		{
			printf("\n Error Colors \n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_fc(t_map *map, char **str, int *i, int *count)
{
	while (!ft_strncmp(str[(*i)], "\n", 2))
		(*i)++;
	if (str[(*i)][0] == 'F' && str[(*i)][1] == ' ')
	{
		ft_get_floor(map, str[(*i)]);
		(*count)++;
		(*i)++;
	}
	if (str[(*i)][0] == 'C' && str[(*i)][1] == ' ')
	{
		ft_get_ceiling(map, str[(*i)]);
		(*count)++;
		(*i)++;
	}
	if (!check_colors(map))
		return (0);
	return (1);
}
