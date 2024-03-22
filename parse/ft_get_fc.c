/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:40:38 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/03/22 07:41:01 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_floor(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_f = ft_strdup(&str[i]);
	if (!map->text_ea)
		return (0); // error and free
	return (1);
}

int	ft_get_ceiling(t_map *map, char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	map->text_c = ft_strdup(&str[i]);
	if (!map->text_ea)
		return (0); // error and free
	return (1);
}

int	get_fc(t_map *map, char **str, int *i, int *count)
{
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
	return (1);
}