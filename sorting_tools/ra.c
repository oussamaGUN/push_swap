/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:32:43 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/28 15:10:43 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list	*ra(t_list *stack_a, char c)
{
	t_list	*first;
	t_list	*tmp;

	first = stack_a;
	stack_a = stack_a->next;
	tmp = stack_a;
	first->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else if (c == 'd')
		write(1, "rr\n", 4);
	return (stack_a);
}
