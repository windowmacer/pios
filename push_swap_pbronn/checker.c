/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:50:37 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 17:04:07 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rest(char *msg, t_list **a, t_list **b)
{
	if (!ft_strncmp(msg, "rr"))
	{
		rotate_stack(a, NULL);
		rotate_stack(b, NULL);
	}
	else if (!ft_strncmp(msg, "rrr"))
	{
		reverse_rotate_stack(a, NULL);
		reverse_rotate_stack(b, NULL);
	}
	else if (!ft_strncmp(msg, "ss"))
	{
		swap_stack(*b, NULL);
		swap_stack(*a, NULL);
	}
	else
		ft_exit(0);
}

void	check_function(char *msg, t_list **a, t_list **b)
{
	if (!ft_strncmp(msg, "ra"))
		rotate_stack(a, NULL);
	else if (!ft_strncmp(msg, "rb"))
		rotate_stack(b, NULL);
	else if (!ft_strncmp(msg, "sa"))
		swap_stack(*a, NULL);
	else if (!ft_strncmp(msg, "sb"))
		swap_stack(*b, NULL);
	else if (!ft_strncmp(msg, "rra"))
		reverse_rotate_stack(a, NULL);
	else if (!ft_strncmp(msg, "rrb"))
		reverse_rotate_stack(b, NULL);
	else if (!ft_strncmp(msg, "pa"))
		push_stack(b, a, NULL);
	else if (!ft_strncmp(msg, "pb"))
		push_stack(a, b, NULL);
	else
		check_rest(msg, a, b);
}

int	sorted(t_list *a)
{
	t_list	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp != a->prev)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_read_action(t_list **a, t_list **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		check_function(line, a, b);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		exit(1);
	check_in(ac, av, &a);
	ft_read_action(&a, &b);
	if (sorted(a) && !(lst_size(b)))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	clr_list(&a);
	clr_list(&b);
}
