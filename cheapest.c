/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:21:50 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/02 18:25:12 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	set_target(int data, t_list *b)
{
	long	closest;

	closest = 0;
	if (find_closest_smaller(data, b) == LONG_MIN)
		closest = find_max_in_list(b);
	else
		closest = find_closest_smaller(data, b);
	return (closest);
}

int	ft_mid(t_list *b, int data, int len)
{
	int	i;

	i = 0;
	while (i <= len / 2)
	{
		if (b->data == data)
			return (0);
		b = b->next;
		i++;
	}
	return (1);
}

int	push_cost(int data, int len, t_list *a)
{
	int		count;
	t_list	*stack_a;

	count = 0;
	stack_a = a;
	if (ft_mid(a, data, len) == 0)
	{
		while (stack_a && stack_a->data != data)
		{
			stack_a = stack_a->next;
			count++;
		}
		return (count);
	}
	else
	{
		while (stack_a && stack_a->data != data)
		{
			stack_a = stack_a->next;
			count++;
		}
		return (ft_lstsize(a) - count);
	}
	return (0);
}

int	push_cost_b(int closest, int len, t_list *b)
{
	int		count;
	t_list	*stack_b;

	count = 0;
	stack_b = b;
	if (ft_mid(b, closest, len) == 0)
	{
		while (stack_b && stack_b->data != closest)
		{
			stack_b = stack_b->next;
			count++;
		}
		return (count);
	}
	else
	{
		while (stack_b && stack_b->data != closest)
		{
			stack_b = stack_b->next;
			count++;
		}
		return (ft_lstsize(b) - count);
	}
	return (0);
}

t_list	*find_cheapest(t_list *a, t_list *b)
{
	int		count_moves;
	int		moves;
	t_list	*tmp;
	t_list	*perfect;

	tmp = a;
	perfect = NULL;
	count_moves = 0;
	moves = INT_MAX;
	while (tmp)
	{
		count_moves = push_cost(tmp->data, ft_lstsize(a), a)
			+ push_cost_b(set_target(tmp->data, b), ft_lstsize(b), b);
		if (count_moves < moves)
		{
			moves = count_moves;
			perfect = tmp;
		}
		tmp = tmp->next;
	}
	return (perfect);
}
