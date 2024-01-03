/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:59:54 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/03 15:45:45 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list	*sa(t_list *stack_a, char c)
{
	t_list	*first;
	t_list	*second;

	first = stack_a;
	stack_a = stack_a->next;
	second = stack_a->next;
	stack_a->next = first;
	first->next = second;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	return (stack_a);
}
