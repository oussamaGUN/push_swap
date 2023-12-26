/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:29:00 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/26 17:53:26 by ousabbar         ###   ########.fr       */
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
        a = rra(a, 'a');
    }
    else if (top->data > bottom->data && top->data < middle->data)
        a = rra(a, 'a');
    else if (top->data < middle->data && top->data < bottom->data 
        && middle->data > bottom->data)
    {
        a = sa(a);
        a = ra(a, 'a');
    }
    else if (top->data > bottom->data && top->data > middle->data &&
        middle->data < bottom->data)
        a = ra(a, 'a');
    return a;
}
