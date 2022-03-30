/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:51:00 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 13:51:01 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 1;
	new->next = NULL;
	new->prev = NULL;
	new->place = NULL;
	return (new);
}

void	clr_list(t_list **head)
{
	t_list	*temp;
	t_list	*temp2;

	if (head && *head)
	{
		temp = (*head)->next;
		while (temp && (temp != *head))
		{
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
		free(*head);
		*head = NULL;
	}
}

int	lst_size(t_list *head)
{
	t_list	*tmp;
	int		c;

	if (!head)
		return (0);
	c = 1;
	tmp = head;
	while (tmp != head->prev)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}
