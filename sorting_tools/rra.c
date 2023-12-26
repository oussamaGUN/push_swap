/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:06:29 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/26 17:54:24 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list *rra(t_list *stack_a,char c)
{
    t_list *last;
    t_list *tmp = stack_a;
    while (tmp->next)
        tmp = tmp->next;
    last = tmp;
    t_list *ptr = stack_a;
    while (ptr->next)
    {
        if (ptr->next == last)
        {
            ptr->next = NULL;
            break;
        }
        ptr = ptr->next;
    }
    last->next = stack_a;
    stack_a = last;
    if (c == 'a')
        write(1, "rra\n", 4);
    else if (c == 'b')
        write(1, "rrb\n", 4);
    return stack_a;
}