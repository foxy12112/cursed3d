/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:29:19 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 22:17:27 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_no_so(t_map *map, char **str, int *i, int *count)
{
	int	index;

	index = 0;
	if (str[(*i)][0] == 'N' && str[(*i)][1] == 'O')
	{
		ft_get_north(map, str[(*i)]);
		(*count)++;
		(*i)++;
		index = 1;
	}
	if (str[(*i)][0] == 'S' && str[(*i)][1] == 'O')
	{
		ft_get_south(map, str[(*i)]);
		(*count)++;
		(*i)++;
		index = 1;
	}
	return (index);
}
