/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:05 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 17:21:06 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		j;

	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	while (++j < ac)
	{
		if (ft_check_space(av[j], stack_a) == 0)
			stack_a = check_error2_spaces_and_creat_list(av[j], stack_a);
		else
			stack_a = create_a_list(av[j], stack_a);
	}
	if (!isorted(stack_a))
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	ft_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
