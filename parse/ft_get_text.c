/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:52:36 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 22:13:34 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_north(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_no = ft_strdup(&str[i]);
	if (!map->text_no)
		return (clean_up(map), 0);
	return (1);
}

int	ft_get_south(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_so = ft_strdup(&str[i]);
	if (!map->text_so)
		return (clean_up(map), 0);
	return (1);
}

int	ft_get_west(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_we = ft_strdup(&str[i]);
	if (!map->text_we)
		return (clean_up(map), 0);
	return (1);
}

int	ft_get_east(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_ea = ft_strdup(&str[i]);
	if (!map->text_ea)
		return (clean_up(map), 0);
	return (1);
}

int	get_wall(t_map *map, char **str, int *i, int *count)
{
	int	index;

	index = ft_no_so(map, str, i, count);
	if (str[(*i)][0] == 'W' && str[(*i)][1] == 'E')
	{
		ft_get_west(map, str[(*i)]);
		(*count)++;
		(*i)++;
		index = 1;
	}
	if (str[(*i)][0] == 'E' && str[(*i)][1] == 'A')
	{
		ft_get_east(map, str[(*i)]);
		(*count)++;
		(*i)++;
		index = 1;
	}
	if (!index)
		exit(1);
	return (1);
}
