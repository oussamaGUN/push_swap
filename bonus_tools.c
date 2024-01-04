/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:31:24 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 15:21:07 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int	empty_stack(t_list *b)
{
	if (b == NULL)
		return (1);
	return (0);
}

void	conditions_bonus(t_list *stack_a, t_list *stack_b, char *s)
{
	if (!s)
	{
		if (!isorted(stack_a) && empty_stack(stack_b) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	free(s);
}
