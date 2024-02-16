/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grabge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:41:39 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/05 11:39:23 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/parsing.h"

t_col	*lst_new(void *ptr, t_col **col)
{
	t_col	*new;

	if (search_for_address(col, ptr))
		return (NULL);
	new = malloc(sizeof(t_col));
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

int	search_for_address(t_col **col, void *ptr)
{
	t_col	*tmp;

	tmp = *col;
	while (tmp)
	{
		if (tmp->ptr == ptr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	lst_add(t_col **alst, t_col *news)
{
	t_col	*tmp;

	if (NULL == news)
		return ;
	if (!*alst)
	{
		*alst = news;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = news;
}

void	free_garbage(t_col **col)
{
	t_col	*tmp;
	t_col	*tmp2;

	if (!col)
		return ;
	tmp = *col;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->ptr);
		free(tmp);
		tmp = tmp2;
	}
}
