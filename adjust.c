/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:01:36 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/02 15:37:16 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_median(t_list *b, int data, int len)
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
void adjust(t_list **a, t_list **b, t_list *perfect)
{
    int len = ft_lstsize(*a);
    int len_b = ft_lstsize(*b);
    int closest = set_target(perfect->data, *b);
    // printf("perfect = %d closest = %d\n", perfect->data,  closest);
    if (ft_median(*a, perfect->data, len) == 0 && ft_median(*b, closest, len_b) == 0)
    {
        while ((*a)->data != perfect->data && (*b)->data != closest)
        {
            *a = ra(*a, 's');
            *b = ra(*b, 's');
            write(1, "rr\n", 3);
        }
        while ((*a)->data != perfect->data)
            *a = ra(*a, 'a');
        while ((*b)->data != closest)
            *b = ra(*b, 'b');
    }
    else if (ft_median(*a, perfect->data, len) == 1 && ft_median(*b, closest, len_b) == 1)
    {
        while ((*a)->data != perfect->data && (*b)->data != closest)
        {
            *a = rra(*a, 's');
            *b = rra(*b, 's');
            write(1, "rrr\n", 4);
        }
        while ((*a)->data != perfect->data)
            *a = rra(*a, 'a');
        while ((*b)->data != closest)
            *b = rra(*b, 'b'); 
    }
    else if (ft_median(*a, perfect->data, len) == 1 && ft_median(*b, closest, len_b) == 0)
    {
        while ((*a)->data != perfect->data)
            *a = rra(*a, 'a');
        while ((*b)->data != closest)
            *b = ra(*b, 'b');   
    }
    else if (ft_median(*a, perfect->data, len) == 0 && ft_median(*b, closest, len_b) == 1)
    {
        while ((*a)->data != perfect->data)
            *a = ra(*a, 'a');
        while ((*b)->data != closest)
            *b = rra(*b, 'b');   
    }
    
}
