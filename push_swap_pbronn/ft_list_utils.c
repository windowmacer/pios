/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:50:58 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 16:47:15 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_list *a)
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

t_list	*add_back(t_list *new, t_list **head)
{
	t_list	*tail;

	if (!(*head))
	{
		new->next = new;
		new->prev = new;
		*head = new;
		(*head)->i = 0;
		return (NULL);
	}
	tail = (*head)->prev;
	new->next = *head;
	new->prev = tail;
	(*head)->prev = new;
	tail->next = new;
	tail = new;
	new->i = new->prev->i + 1;
	return (*head);
}

t_list	*add_front(t_list *new, t_list **head)
{
	if (!(*head))
	{
		new->next = new;
		new->prev = new;
		*head = new;
		*head = new;
		(*head)->i = 0;
		return (NULL);
	}
	add_front_utils(new, head);
	return (*head);
}

void	add_front_utils(t_list *new, t_list **head)
{
	t_list	*tail;

	tail = (*head)->prev;
	new->next = *head;
	new->prev = tail;
	(*head)->prev = new;
	tail->next = new;
	tail = new;
	*head = new;
	new->i = -1;
	while (new != (*head)->prev)
	{
		new->i += 1;
		new = new->next;
	}
	new->i += 1;
}
