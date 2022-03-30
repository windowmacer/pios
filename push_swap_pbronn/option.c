/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:51:32 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 16:00:09 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *head, char *str)
{
	int	swap;

	if (lst_size(head) < 1)
		return ;
	swap = head->data;
	head->data = head->next->data;
	head->next->data = swap;
	if (str)
		ft_putstr(str);
}

void	index_push(t_list **from)
{
	t_list	*tmp;

	tmp = *from;
	tmp->i = 0;
	tmp = tmp->next;
	while (tmp != *from)
	{
		tmp->i = tmp->prev->i + 1;
		tmp = tmp->next ;
	}
}

void	push_stack(t_list **from, t_list **to, char *str)
{
	t_list	*tmp;
	t_list	*last;

	if (lst_size(*from) == 0)
		return ;
	tmp = (*from)->next;
	last = (*from)->prev;
	add_front(new_node((*from)->data), to);
	if (lst_size(*from) == 1)
	{
		free(*from);
		*from = NULL;
	}
	else
	{
		tmp->prev = last;
		last->next = tmp;
		free(*from);
		*from = tmp;
		index_push(from);
	}
	if (str)
		ft_putstr(str);
}

void	rotate_stack(t_list **head, char *str)
{
	t_list	*tmp;

	if (lst_size(*head) < 2)
		return ;
	*head = (*head)->next;
	tmp = *head;
	while (tmp != (*head)->prev)
	{
		tmp->i -= 1;
		tmp = tmp->next;
	}
	tmp->i = tmp->prev->i + 1;
	if (str)
		ft_putstr(str);
}

void	reverse_rotate_stack(t_list **head, char *str)
{
	t_list	*tmp;

	if (lst_size(*head) < 2)
		return ;
	*head = (*head)->prev;
	tmp = *head;
	tmp->i = 0;
	tmp = tmp->next;
	while (tmp != *head)
	{
		tmp->i = tmp->prev->i + 1;
		tmp = tmp->next ;
	}
	if (str)
		ft_putstr(str);
}
