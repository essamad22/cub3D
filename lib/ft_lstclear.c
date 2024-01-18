/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:47:01 by aakhtab           #+#    #+#             */
/*   Updated: 2022/11/12 15:52:32 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*save;

	if (!(*lst) || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		save = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = save;
	}
	*lst = NULL;
}
