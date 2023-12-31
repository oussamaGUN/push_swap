/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:34:16 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/03 15:59:40 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	rrr(t_list **a, t_list **b, char c)
{
	*a = rra(*a, 'h');
	*b = rra(*b, 'h');
	if (c == 'r')
		write(1, "rrr\n", 4);
}

void	rr(t_list **a, t_list **b, char c)
{
	*a = ra(*a, 'h');
	*b = ra(*b, 'h');
	if (c == 'r')
		write(1, "rr\n", 3);
}
