/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:06:29 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/23 13:26:48 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list *rra(t_list *stack_a)
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
    return stack_a;
}