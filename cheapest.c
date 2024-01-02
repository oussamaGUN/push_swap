/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:21:50 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/02 11:08:34 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"



int set_target(int data, t_list *b)
{	
    long closest = 0;

	if (find_closest_smaller(data, b) == LONG_MIN)
		closest = find_max_in_list(b);
	else
		closest = find_closest_smaller(data, b);
	return closest;
}
int ft_mid(t_list *b, int data, int len)
{
	int i = 0;
	while (i <= len / 2)
	{
		if (b->data == data)
			return 0;
		b = b->next;
		i++;
	}

	return 1;
}
int push_cost(int data, int len, t_list *a)
{
    int count_ra = 0;
    int count_rra = 0;

    
    t_list *stack_a = a;
	if (ft_mid(a, data, len) == 0)
	{
		while (stack_a && stack_a->data != data)
		{
			stack_a = stack_a->next;
			count_ra++;
		}
		return count_ra;
	}
    else
    {
        // Node is in the lower half, move it to the top
        while (stack_a && stack_a->data != data)
        {
            stack_a = stack_a->next;
            count_rra++;
        }
		return ft_lstsize(a) - count_rra;
    }


    // Choose the direction with the minimum count
 	return 0;
}
int push_cost_b(int closest, t_list *b)
{
	int count_rb = 0;
    int count_rrb = 0; 
    t_list *stack_b = b;
	int len = ft_lstsize(b);
	if (ft_mid(b, closest, len) == 0)
	{
		while (stack_b && stack_b->data != closest)
		{
			stack_b = stack_b->next;
			count_rb++;
		}
		return count_rb;
	}
    else
    {
        // Node is in the lower half, move it to the top
        while (stack_b && stack_b->data != closest)
        {
            stack_b = stack_b->next;
            count_rrb++;
        }
		return ft_lstsize(b) - count_rrb;
    }
	return 0;
}
int push_cost_stacks(t_list *a, t_list *b, int closest, int data)
{
    int len_a = ft_lstsize(a);
	int len_b = ft_lstsize(b);
    int count_rr = 0;
    int count_rrr = 0;
	int count_rrrb = 0;
	int count_rrra = 0;
	
    t_list *stack_b = b;
    t_list *stack_a = a;
	// printf("%d %d %d %d\n", closest, ft_mid(b, closest, len_b), data, ft_mid(a, data, len_a));

	if (ft_mid(b, closest, len_b) == 0 && ft_mid(a, data, len_a) == 0)
	{
		while (stack_b && stack_b->data != closest && stack_a && stack_a->data != data)
		{
			stack_b = stack_b->next;
			stack_a = stack_a->next;
			count_rr++;
		}
		while (stack_b && stack_b->data != closest)
		{
			stack_b = stack_b->next;
			count_rr++;
		}
		while (stack_a && stack_a->data != data)
		{
			stack_a = stack_a->next;
			count_rr++;
		}
		return count_rr;
	}
    else if (ft_mid(b, closest, len_b) == 1 && ft_mid(a, data, len_a) == 1)
    {
        while (stack_b && stack_b->data != closest && stack_a && stack_a->data != data)
        {
            stack_b = stack_b->next;
            stack_a = stack_a->next;
            count_rrr++;
        }
		while (stack_b && stack_b->data != closest)
		{
			stack_b = stack_b->next;
			count_rrrb++;
		}
		// count_rrr = ft_lstsize(b) - count_rrr;
		while (stack_a && stack_a->data != data)
		{
			stack_a = stack_a->next;
			count_rrra++;
		}
		if (count_rrra > count_rrrb)
			count_rrr =  count_rrra - count_rrrb;
		else
			count_rrr = count_rrrb - count_rrra;
		return count_rrr;
    }
	return 0;
}
t_list *find_cheapest(t_list *a, t_list *b)
{
	int count_moves = 0;
	int count_both = 0;
	int moves = INT_MAX;
	int len;
	t_list *tmp = a;
	t_list *ptr = b;
	t_list *perfect = NULL;
	len = ft_lstsize(a);
	while (tmp)
	{
		count_moves = push_cost(tmp->data, len, a) + push_cost_b(set_target(tmp->data, b), b);
		count_both = push_cost_stacks(a, b, set_target(tmp->data, b), tmp->data);
		// printf("--(%d) %d %d--\n",tmp->data, count_moves, count_both);
		if (count_both < count_moves && count_both)
			count_moves = count_both;
		// printf(" %d\n", count_moves);
		if (count_moves < moves)
		{
			moves = count_moves;
			perfect = tmp;
		}
		tmp = tmp->next;

	}
	// printf("%d\n", perfect->data);
	return perfect;
}