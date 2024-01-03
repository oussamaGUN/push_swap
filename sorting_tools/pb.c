/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:47:47 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/03 10:46:13 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	pb(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*node;

	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = NULL;
	ft_lstadd_front(stack_b, node);
	if (c == 'b')
		write(1, "pb\n", 3);
}
