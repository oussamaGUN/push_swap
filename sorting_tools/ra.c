/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:32:43 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/23 13:21:13 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list *ra(t_list *stack_a)
{
    t_list *first = stack_a;
    stack_a = stack_a->next;
    first->next = NULL;
    
    t_list *tmp = stack_a;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = first;
    return stack_a;    
}