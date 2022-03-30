/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:52:12 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 15:57:57 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		check_in(ac, av, &a);
		if (lst_size(a) == 1)
		{
			clr_list(&a);
			return (1);
		}
		sort(&a, &b);
		clr_list(&a);
	}
	return (0);
}
