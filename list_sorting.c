/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:48:33 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/03 10:47:14 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list	*sort_list(t_list *a, t_list *b)
{
	t_list	*perfect;

	if (ft_lstsize(a) > 4)
		pb(&a, &b, 'b');
	pb(&a, &b, 'b');
	while (ft_lstsize(a) > 3)
	{
		perfect = find_cheapest(a, b);
		adjust(&a, &b, perfect);
		pb(&a, &b, 'b');
	}
	b = sort_b_from_biggest_to_smallest(b);
	a = sort_three_numbers(a);
	a = push_all_the_nodes_to_a(a, b);
	a = sort_a_from_smallest_to_biggest(a);
	return (a);
}
