/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:05 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/22 17:40:48 by ousabbar         ###   ########.fr       */
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

int ft_check_max_min(char *s)
{
    int		i;
	int		sign;
	long int		res;

	i = 0;
	sign = 1;
	res = 0;

	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
    res *= sign;
    if (res < INT_MIN || res > INT_MAX)
        return 0;
    return 1;
}
int ft_check_duplicate(char *s, t_list *lst)
{
    int num = ft_atoi(s);
    while (lst)
    {
        if (lst->data == num)
            return 0;
        lst = lst->next;
    }
    return 1;
}
int empty(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] != ' ')
            return 1;
        i++;
    }
    return 0;
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
        if (!empty(av[j]))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        if (ft_check_space(av[j]) == 0)
        {
            str_arr = ft_split(av[j], ' ');
            i = 0;
            while (str_arr[i])
            {
                if (!ft_isdigit(str_arr[i]) || !ft_check_max_min(str_arr[i])
                    || !ft_check_duplicate(str_arr[i], stack_a))
                {
                    write(2, "Error\n", 6);
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
            if (!ft_isdigit(av[j]) || !ft_check_max_min(av[j]) || !ft_check_duplicate(av[j], stack_a))
            {
                write(1, "Error\n", 6);
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
