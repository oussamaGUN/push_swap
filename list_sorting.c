/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:48:33 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 10:33:42 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list	*sort_list(t_list *a, t_list *b)
{
	t_list	*ptr;
	long	closest;

	if (ft_lstsize(a) > 4)
		pb(&a, &b);
	pb(&a, &b);
	ptr = a;
	while (ptr && ft_lstsize(a) > 3)
	{
		if (find_closest_smaller(ptr->data, b) == LONG_MIN)
			closest = find_max_in_list(b);
		else
			closest = find_closest_smaller(ptr->data, b);
		b = turn_closest(b, closest, 'b');
		ptr = ptr->next;
		pb(&a, &b);
	}
	b = sort_b_from_biggest_to_smallest(b);
	a = sort_three_numbers(a);
	a = push_all_the_nodes_to_a(a, b);
	a = sort_a_from_smallest_to_biggest(a);
	return (a);
}
