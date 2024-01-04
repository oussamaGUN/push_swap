/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:29:00 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 16:08:51 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list	*sa_rra_function(t_list *a)
{
	a = sa(a, 'a');
	a = rra(a, 'a');
	return (a);
}

t_list	*sort_three_numbers(t_list *a)
{
	t_list	*top;
	t_list	*middle;
	t_list	*bottom;

	top = a;
	middle = a->next;
	bottom = a->next->next;
	if (top->data > middle->data && top->data < bottom->data
		&& middle->data < bottom->data)
		a = sa(a, 'a');
	else if (top->data > bottom->data && top->data > middle->data
		&& middle->data > bottom->data)
		a = sa_rra_function(a);
	else if (top->data > bottom->data && top->data < middle->data)
		a = rra(a, 'a');
	else if (top->data < middle->data && top->data < bottom->data
		&& middle->data > bottom->data)
	{
		a = sa(a, 'a');
		a = ra(a, 'a');
	}
	else if (top->data > bottom->data && top->data > middle->data
		&& middle->data < bottom->data)
		a = ra(a, 'a');
	return (a);
}

t_list	*sort_two(t_list *a)
{
	if (a->data > a->next->data)
		a = sa(a, 'a');
	return (a);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len == 2)
		*stack_a = sort_two(*stack_a);
	else if (len == 3)
		*stack_a = sort_three_numbers(*stack_a);
	else if (len >= 4)
		*stack_a = sort_list(*stack_a, *stack_b);
}
