/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:29:58 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 15:46:32 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*s;

	s = *lst;
	if (s)
	{
		while (s)
		{
			s = s->next;
			ft_lstdelone(*lst);
			*lst = s;
		}
		*lst = NULL;
	}
}