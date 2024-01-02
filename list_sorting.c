/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:48:33 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/02 13:06:08 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list	*sort_list(t_list *a, t_list *b)
{

	t_list *perfect;
	// long	closest;

	if (ft_lstsize(a) > 4)
		pb(&a, &b);
	pb(&a, &b);

	while (ft_lstsize(a) > 3)
	{
		// if (find_closest_smaller(ptr->data, b) == LONG_MIN)
		// 	closest = find_max_in_list(b);
		// else
		// 	closest = find_closest_smaller(ptr->data, b);
		perfect = find_cheapest(a, b);
		// printf("%d\n", perfect->data);
		
		adjust(&a, &b, perfect);
		pb(&a, &b);
		// printf("--\n");
	}
	b = sort_b_from_biggest_to_smallest(b);
	a = sort_three_numbers(a);
	a = push_all_the_nodes_to_a(a, b);
	a = sort_a_from_smallest_to_biggest(a);
	return (a);
}
