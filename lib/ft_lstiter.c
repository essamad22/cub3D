/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:39:52 by aakhtab           #+#    #+#             */
/*   Updated: 2022/11/12 15:55:54 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{	
	t_list	*ptr;

	if (!lst || !f)
		return ;
	if (lst)
	{
		ptr = lst;
		while (ptr)
		{
			f(ptr->content);
			ptr = ptr->next;
		}
	}
}
