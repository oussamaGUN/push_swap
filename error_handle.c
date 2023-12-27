/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:37:04 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 09:40:36 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
void handle_error()
{
    write(2, "Error\n", 6);
    exit(1);
}
void conditions(char *s, t_list *stack_a)
{
    if (!ft_isdigit(s) || !ft_check_max_min(s)
        || !ft_check_duplicate(s, stack_a))
        handle_error();
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