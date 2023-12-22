/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:05 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/22 10:29:46 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void ft_sort(t_list **stack_a)
{
    int len = ft_lstsize(*stack_a);
    if (len == 3)
    {
        if ((*stack_a)->data > (*stack_a)->next->data)
            *stack_a = sa(*stack_a);
    }
}
int ft_check_space(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == ' ')
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char *av[])
{
    t_list *stack_a = NULL;
    char **str_arr;
    // ft_sort(&stack_a);
    if (ac < 1)
        return 0;
    int j = 1;
    int i = 0;
    int num = 0;
    while (j < ac)
    {
        if (ft_check_space(av[j]) == 0)
        {
            str_arr = ft_split(av[j], ' ');
            i = 0;
            while (str_arr[i])
            {
                if (!ft_isdigit(str_arr[i]))
                {
                    write(2, "Erorr\n", 6);
                    exit(1);
                }
                num = ft_atoi(str_arr[i]);
                t_list *lst = ft_lstnew(num);
                if (!lst)
                    return 0;
                ft_lstadd_front(&stack_a, lst);
                i++;
            }
            int h = 0;
            while (str_arr[h])
                free(str_arr[h++]);
            free(str_arr);
        }
        else
        {
            if (!ft_isdigit(av[j]))
            {
                write(2, "Erorr\n", 6);
                exit(1);
            }
            num = ft_atoi(av[j]);
            t_list *lst = ft_lstnew(num);
            if (!lst)
                return 0;
            ft_lstadd_front(&stack_a, lst);
        }
        j++;
    }
    t_list *tmp = stack_a;
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    return 0;
}
