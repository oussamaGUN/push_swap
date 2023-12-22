/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:39:32 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/20 10:25:16 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
    t_list *tmp = lst;
	if(tmp)
	{
		while (tmp)
		{
			i++;
		tmp = tmp->next;
            if (tmp == lst)
                return i;
        }
	}
	return (i);
}