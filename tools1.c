/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:50:26 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/02 15:21:11 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

long	find_closest_smaller(int data, t_list *b)
{
	long	closest;

	closest = LONG_MIN;
	while (b)
	{
		if (data > b->data && b->data > closest && data > closest)
			closest = b->data;
		b = b->next;
	}
	// printf("----%d %lu----\n", data, closest);
	return (closest);
}

int	find_max_in_list(t_list *b)
{
	t_list	*tmp;
	long		max;

	tmp = b;
	max = LONG_MIN;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*turn_closest(t_list *b, int closest, char c)
{
	int		median;
	t_list	*tmp;
	int		flag;
	int		i;

	median = ft_lstsize(b) / 2;
	tmp = b;
	flag = 0;
	i = 0;
	while (i <= median)
	{
		if (tmp->data == closest)
			flag = 1;
		i++;
		tmp = tmp->next;
	}
	if (flag == 1)
	{
		while (b->data != closest)
			b = ra(b, c);
	}
	else
		while (b->data != closest)
			b = rra(b, c);
	return (b);
}

t_list	*sort_b_from_biggest_to_smallest(t_list *b)
{
	int		median;
	t_list	*tmp;
	int		flag;
	int		max;
	int		i;

	median = ft_lstsize(b) / 2;
	tmp = b;
	max = find_max_in_list(b);
	i = 0;
	flag = 0;
	while (i <= median)
	{
		if (tmp->data == max)
			flag = 1;
		i++;
		tmp = tmp->next;
	}
	if (flag == 1)
		while (b->data != max)
			b = ra(b, 'b');
	else
		while (b->data != max)
			b = rra(b, 'b');
	return (b);
}
