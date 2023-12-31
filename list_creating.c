/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:44:46 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 15:06:05 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list	*create_a_list(char *s, t_list *stack_a)
{
	int		num;
	t_list	*lst;

	if (conditions(s, stack_a) == 0)
	{
		ft_lstclear(&stack_a);
		exit(1);
	}
	num = ft_atoi(s);
	lst = ft_lstnew(num);
	if (!lst)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	ft_lstadd_back(&stack_a, lst);
	return (stack_a);
}

void	ft_free(char **s)
{
	int	h;

	h = 0;
	while (s[h])
		free(s[h++]);
	free(s);
}

int	check_array(char *s, t_list *stack_a)
{
	if (conditions(s, stack_a) == 0)
		return (0);
	return (1);
}

t_list	*check_error2_spaces_and_creat_list(char *s, t_list *stack_a)
{
	int			i;
	char		**str_arr;
	t_list		*lst;
	int			num;

	str_arr = ft_split(s, ' ');
	i = -1;
	while (str_arr[++i])
	{
		num = ft_atoi(str_arr[i]);
		lst = ft_lstnew(num);
		if (!lst || check_array(str_arr[i], stack_a) == 0)
		{
			ft_lstclear(&stack_a);
			ft_free(str_arr);
			exit(1);
		}
		ft_lstadd_back(&stack_a, lst);
	}
	ft_free(str_arr);
	return (stack_a);
}
