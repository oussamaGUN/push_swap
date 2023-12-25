/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:47:47 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/23 18:30:51 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *node = *stack_a;
    *stack_a = (*stack_a)->next;
    node->next = NULL;
    ft_lstadd_front(stack_b, node);
    write(1, "pb\n", 3);
}