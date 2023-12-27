/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:29:58 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 14:39:17 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void del(int *d)
{
    free(d);
}
void	ft_lstdelone(t_list *lst, void (*del)(int *))
{
	if (lst && del)
	{
		del(&lst->data);
		free(lst);
	}
}
void	ft_lstclear(t_list **lst, void (*del)(int *))
{
	t_list	*s;

	s = *lst;
	if (s && del)
	{
		while (s)
		{
			s = s->next;
			ft_lstdelone(*lst, del);
			*lst = s;
		}
		*lst = NULL;
	}
}