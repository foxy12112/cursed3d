/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_png.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:15:17 by mbelhaj-          #+#    #+#             */
/*   Updated: 2024/04/30 17:51:32 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

char	*get_png(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(ft_strlen(str) + 1);
	if (tmp == NULL)
		return (printf("Error\n"), NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	load_img(t_tex *tex, t_map *map)
{
	tex->no = mlx_load_png(get_png(map->text_no));
	tex->ea = mlx_load_png(get_png(map->text_ea));
	tex->we = mlx_load_png(get_png(map->text_we));
	tex->so = mlx_load_png(get_png(map->text_so));
	if (!tex->no || !tex->ea || !tex->we || !tex->ea)
		return (0);
	return (1);
}
