/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:44:46 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 09:45:24 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list *create_a_list(char *s, t_list *stack_a)
{
    int num;
    conditions(s, stack_a);
    num = ft_atoi(s);
    t_list *lst = ft_lstnew(num);
    if (!lst)
        return 0;
    ft_lstadd_back(&stack_a, lst);
    return stack_a;
}
t_list *check_error2_spaces_and_creat_list(char *s, t_list *stack_a)
{
    int     i;
    char    **str_arr;
    t_list  *lst;
    int     h;
    int num;

    if (ft_check_space(s) == 0)
    {
        str_arr = ft_split(s, ' ');
        i = -1;
        while (str_arr[++i])
        {
            conditions(str_arr[i], stack_a);
            num = ft_atoi(str_arr[i]);
            lst = ft_lstnew(num);
            if (!lst)
                return 0;
            ft_lstadd_back(&stack_a, lst);
        }
        h = 0;
        while (str_arr[h])
            free(str_arr[h++]);
        free(str_arr);
    }
    return stack_a;
}