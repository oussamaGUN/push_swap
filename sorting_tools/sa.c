/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:59:54 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/23 11:05:51 by ousabbar         ###   ########.fr       */
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
    printf("sa\n");
    return stack_a;
}