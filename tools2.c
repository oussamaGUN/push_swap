/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:53:34 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 09:55:00 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list *push_all_the_nodes_to_a(t_list *a, t_list *b)
{
    long closest;
    t_list *tmp = b;
    while (tmp)
    {
        if (find_closest_bigger(tmp->data, a) ==  LONG_MAX)
            closest = find_min_in_list(a);
        else
            closest = find_closest_bigger(tmp->data, a);
        a = turn_closest(a, closest, 'a');
        tmp = tmp->next;
        pa(&a, &b);
    }
    return a;
}
t_list *sort_a_from_smallest_to_biggest(t_list *a)
{
    int median = ft_lstsize(a) / 2 - 1;
    t_list *tmp = a;
    int flag = 0;
    int min = find_min_in_list(a);
    
    int i = 0;
    while (i < median)
    {
        if (tmp->data == min)
            flag = 1;
        i++;
        tmp = tmp->next;
    }
    if (flag == 1)
    {
        while (a->data != min)
            a = ra(a, 'a');
    }
    else
    {
        while (a->data != min)
            a = rra(a, 'a');
    }
    return a;
}
long find_closest_bigger(int data, t_list *a)
{
    long closest = LONG_MAX;
    while (a)
    {
        if (data < a->data && a->data < closest)
            closest = a->data;
        a = a->next;
    }
    
    return closest;    
}
int find_min_in_list(t_list *a)
{
    t_list *tmp = a;
    int min = tmp->data;
    while (tmp)
    {
        if (tmp->data < min)
            min = tmp->data;
        tmp = tmp->next;        
    }
    return min;  
}