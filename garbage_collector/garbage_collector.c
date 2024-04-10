/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:44:31 by rallouan          #+#    #+#             */
/*   Updated: 2024/04/10 19:47:27 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_mem_block	*ft_new_mem_block(void *pointer)
{
	t_mem_block	*block;

	block = malloc(sizeof(t_mem_block));
	if (!block)
		return (0);
	block->block_pointer = pointer;
	block->next = NULL;
	return (block);
}

static void	ft_add_mem_block(t_mem_block **lst, void *pointer)
{
	t_mem_block	*temp;

	if (!*lst)
	{
		*lst = ft_new_mem_block(pointer);
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ft_new_mem_block(pointer);
	}
}

void	*ft_malloc(t_mem_block **lst, int size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		return (NULL);
	ft_add_mem_block(lst, p);
	return (p);
}

void	ft_free_alll(t_mem_block **lst)
{
	t_mem_block	*temp;

	temp = (*lst);
	while ((*lst) != NULL)
	{
		temp = (*lst);
		if (temp->block_pointer)
			free(temp->block_pointer);
		temp->block_pointer = NULL;
		(*lst) = (*lst)->next;
		free(temp);
		temp = NULL;
	}
	*lst = NULL;
}

