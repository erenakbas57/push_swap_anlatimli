/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:13:19 by makbas            #+#    #+#             */
/*   Updated: 2023/02/27 00:04:41 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack, char c)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	head = *stack;
	next = head->next;
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
	else if (c == 's')
		ft_putendl_fd("ss", 1);
	return (0);
}

int	push(t_list **stack, t_list **push, char c)
{
	t_list	*iter;

	iter = *stack;
	*stack = (*stack)->next;
	iter->next = *push;
	*push = iter;
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
	return (0);
}

int	rotate(t_list **stack, char c)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("ra", 1);
	else if (c == 'r')
		ft_putendl_fd("rr", 1);
	return (0);
}

int	reverse_rotate(t_list **stack, char c)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
	else if (c == 'r')
		ft_putendl_fd("rrr", 1);
	return (0);
}

// minimum index = 1
// index 1 olan sayı hangi sırada onu bulmaya çalışıyoruz.
int	min_order(t_list **stack_a)
{
	t_list	*new;
	int		min_order;

	new = *stack_a;
	min_order = 0;
	while (new != 0)
	{
		if (new->index == 1)
			break ;
		min_order++;
		new = new->next;
	}
	return (min_order);
}
