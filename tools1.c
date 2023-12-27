/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:50:26 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 09:53:10 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

long find_closest_smaller(int data, t_list *b)
{
    long closest = LONG_MIN;
    while (b)
    {
        if (data > b->data && b->data > closest)
            closest = b->data;
        b = b->next;
    }
    
    return closest;
}

int find_max_in_list(t_list *b)
{
    t_list *tmp = b;
    int max = tmp->data;
    while (tmp)
    {
        if (tmp->data > max)
            max = tmp->data;
        tmp = tmp->next;        
    }
    return max;
}

t_list *turn_closest(t_list *b, int closest, char c)
{
    int median = ft_lstsize(b) / 2 - 1;
    t_list *tmp = b;
    int flag = 0;
    int i = 0;
    while (i < median)
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
    return b;
}

t_list *sort_b_from_biggest_to_smallest(t_list *b)
{
    int median = ft_lstsize(b) / 2 - 1;
    t_list *tmp = b;
    int flag = 0;
    int max = find_max_in_list(b);
    
    int i = 0;
    while (i < median)
    {
        if (tmp->data == max)
            flag = 1;  
        i++;
        tmp = tmp->next;
    }
    if (flag == 1)
    {
        while (b->data != max)
            b = rra(b, 'b');
    }
    else
    {
        while (b->data != max)
            b = ra(b, 'b');
    }
    return b;
}