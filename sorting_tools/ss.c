/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:23:33 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 11:12:32 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ss(t_list **a, t_list **b, char c)
{
	*a = sa(*a, 's');
	*b = sa(*b, 's');
	if (c == 'a')
		write(1, "ss\n", 3);
}
