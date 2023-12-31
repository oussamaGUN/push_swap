/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:03:29 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/03 10:47:52 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	pa(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*node;

	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = NULL;
	ft_lstadd_front(stack_a, node);
	if (c == 'a')
		write(1, "pa\n", 3);
}
