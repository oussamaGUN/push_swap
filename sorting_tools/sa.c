/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:59:54 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/23 18:28:15 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list *sa(t_list *stack_a)
{
    t_list *first = NULL;
    t_list *second = NULL;

    first = stack_a;
    stack_a = stack_a->next;
    second = stack_a->next;
    stack_a->next = first; 
    first->next = second;
    write(1, "sa\n", 3);
    return stack_a;
}