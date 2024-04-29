/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:28:41 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/29 19:43:59 by mbelhaj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_textures(t_map *map, char **textures, int *i, int *count)
{
	if (!get_wall(map, textures, i, count))
		return (0);
	if (!get_fc(map, textures, i, count))
		return (0);
	return (1);
}

int ft_check_wall(char *str)
{
	int i =0;
	while (str[i] )
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] != '1')
			return(0);
		i++;
	}
	return(1);
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
