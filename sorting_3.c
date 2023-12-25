/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:29:00 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/23 18:36:06 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list *sort_three_numbers(t_list *a)
{
    t_list *top = a;
    t_list *middle = a->next;
    t_list *bottom = a->next->next;

    if (top->data > middle->data && top->data < bottom->data
        && middle->data < bottom->data)
        a = sa(a);
    else if (top->data > bottom->data && top->data > middle->data &&
        middle->data > bottom->data)
    {
        a = sa(a);
        a = rra(a);
    }
    else if (top->data > bottom->data && top->data < middle->data)
        a = rra(a);
    else if (top->data < middle->data && top->data < bottom->data 
        && middle->data > bottom->data)
    {
        a = sa(a);
        a = ra(a);
    }
    else if (top->data > bottom->data && top->data > middle->data &&
        middle->data < bottom->data)
        a = ra(a);
    return a;
}
