/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:02:07 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/20 16:02:35 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list *sb(t_list *stack_b)
{
    t_list *first = NULL;
    t_list *second = NULL;

    first = stack_b;
    stack_b = stack_b->next;
    second = stack_b->next;
    stack_b->next = first; 
    first->next = second;
    printf("sa\n");
    return stack_b;
}