/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:05 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/26 22:22:45 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


t_list *sort_two(t_list *a)
{
    if (a->data > a->next->data)
        a = sa(a);
    return a;
}


long find_closest_smaller(int data, t_list *b)
{
    long closest = LONG_MIN;
    while (b)
    {
        if (data > b->data && b->data > closest)
            closest = b->data;
        b = b->next;
    }
    
    return closest;
}
t_list *turn_closest(t_list *b, int closest, char c)
{
    int median = ft_lstsize(b) / 2 - 1;
    t_list *tmp = b;
    int flag = 0;
    int i = 0;
    while (i < median)
    {
        if (tmp->data == closest)
            flag = 1;
        i++;
        tmp = tmp->next;
    }
    if (flag == 1)
    {
        while (b->data != closest)
            b = ra(b, c);
    }
    else
        while (b->data != closest)
            b = rra(b, c);
    return b;
}
int find_max_in_list(t_list *b)
{
    t_list *tmp = b;
    int max = tmp->data;
    while (tmp)
    {
        if (tmp->data > max)
            max = tmp->data;
        tmp = tmp->next;        
    }
    return max;
}

t_list *sort_b_from_biggest_to_smallest(t_list *b)
{
    int median = ft_lstsize(b) / 2 - 1;
    t_list *tmp = b;
    int flag = 0;
    int max = find_max_in_list(b);
    
    int i = 0;
    while (i < median)
    {
        if (tmp->data == max)
            flag = 1;  
        i++;
        tmp = tmp->next;
    }
    if (flag == 1)
    {
        while (b->data != max)
            b = rra(b, 'b');
    }
    else
    {
        while (b->data != max)
            b = ra(b, 'b');
    }
    return b;
}
long find_closest_bigger(int data, t_list *a)
{
    long closest = LONG_MAX;
    while (a)
    {
        if (data < a->data && a->data < closest)
            closest = a->data;
        a = a->next;
    }
    
    return closest;    
}
int find_min_in_list(t_list *a)
{
    t_list *tmp = a;
    int min = tmp->data;
    while (tmp)
    {
        if (tmp->data < min)
            min = tmp->data;
        tmp = tmp->next;        
    }
    return min;  
}

t_list *push_all_the_nodes_to_a(t_list *a, t_list *b)
{
    long closest;
    t_list *tmp = b;
    while (tmp)
    {
        if (find_closest_bigger(tmp->data, a) ==  LONG_MAX)
            closest = find_min_in_list(a);
        else
            closest = find_closest_bigger(tmp->data, a);
        a = turn_closest(a, closest, 'a');
        tmp = tmp->next;
        pa(&a, &b);
    }
    return a;
}
t_list *sort_a_from_smallest_to_biggest(t_list *a)
{
    int median = ft_lstsize(a) / 2 - 1;
    t_list *tmp = a;
    int flag = 0;
    int min = find_min_in_list(a);
    
    int i = 0;
    while (i < median)
    {
        if (tmp->data == min)
            flag = 1;
        i++;
        tmp = tmp->next;
    }
    if (flag == 1)
    {
        while (a->data != min)
            a = rra(a, 'a');
    }
    else
    {
        while (a->data != min)
            a = ra(a, 'a');
    }
    return a;
}
t_list *sort_list(t_list *a, t_list *b)
{
    if (ft_lstsize(a) > 4)
        pb(&a, &b);
    pb(&a, &b);

    t_list *ptr = a;
    long closest;
    
    while (ptr && ft_lstsize(a) > 3)
    { 
        if (find_closest_smaller(ptr->data, b) == LONG_MIN) 
            closest = find_max_in_list(b);
        else
            closest = find_closest_smaller(ptr->data, b);
        b = turn_closest(b, closest, 'b');
        ptr = ptr->next;
        pb(&a, &b);
    }
    b = sort_b_from_biggest_to_smallest(b);
    a = sort_three_numbers(a);
    a = push_all_the_nodes_to_a(a, b);
    a = sort_a_from_smallest_to_biggest(a);

    return a;
}

void ft_sort(t_list **stack_a, t_list **stack_b)
{
    int len = ft_lstsize(*stack_a);
    (void)stack_b;
    if (len == 2)
        *stack_a = sort_two(*stack_a);
    else if (len == 3)
        *stack_a = sort_three_numbers(*stack_a);
    else if (len >= 4)
        *stack_a = sort_list(*stack_a, *stack_b);

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
int isorted(t_list *a)
{
    
    while (a->next)
    {
        if (a->data > a->next->data)
            return 1;
        a = a->next;
    }
    return 0;
}
int main(int ac, char *av[])
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
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
                ft_lstadd_back(&stack_a, lst);
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
                write(2, "Error\n", 6);
                exit(1);
            }
            num = ft_atoi(av[j]);
            t_list *lst = ft_lstnew(num);
            if (!lst)
                return 0;
            ft_lstadd_back(&stack_a, lst);
        }
        j++;
    }
    if (!isorted(stack_a))
        return 0;
    ft_sort(&stack_a, &stack_b);
    t_list *s = stack_a;
    while (s)
    {
        printf("%d\n", s->data);
        s = s->next;
    }
    return 0;
}
