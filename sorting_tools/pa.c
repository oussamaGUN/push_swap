/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:03:29 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/23 11:37:13 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    (void)stack_b;
    t_list *node = *stack_a;
    *stack_a = (*stack_a)->next;
    node->next = NULL;
    ft_lstadd_front(stack_b, node);
}