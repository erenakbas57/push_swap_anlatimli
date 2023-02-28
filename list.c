/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:13:35 by makbas            #+#    #+#             */
/*   Updated: 2023/02/26 23:13:38 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
	{
		return (NULL);
	}
	lst->value = value;
	lst->index = -1;
	lst->next = 0;
	return (lst);
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

t_list	*ft_lstlast(t_list *head)
{
	if (!head)
		return (0);
	while (head->next != 0)
		head = head->next;
	return (head);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	ft_lstlast(*stack)->next = new;
	ft_lstlast(*stack)->next = NULL;
}

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
