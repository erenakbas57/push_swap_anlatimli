/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:13:28 by makbas            #+#    #+#             */
/*   Updated: 2023/02/27 00:04:57 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2-5 elemanlı listeyi sıralamak için if yapısı 
void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap(stack_a, 'a');
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b, 1);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

// 2 eleman varsa ve ilk eleman 2. elemandan büyükse swap işlemi yapar
void	sort_2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, 'a');
}

// 1- sort_2() yapıyoruz .Eğer ilk iki sayı yanlışsa yer değiştirecek
// 2- 1. sayı 3. sayıdan büyükse rra yapacak
// 3- tekrar sort_2() ile ilk iki sayıyı kontrol ediyoruz.
// 4- 2. sayı 3.sayıdan büyükse rra yapıyoruz bir alta iniyor ve sonra sa yapıyoruz.
void	sort_3(t_list **stack_a)
{
	sort_2(stack_a);
	if ((*stack_a)->value > ((*stack_a)->next->next->value))
		reverse_rotate(stack_a, 'a');
	sort_2(stack_a);
	if ((*stack_a)->next->value > ((*stack_a)->next->next->value))
	{
		reverse_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

// NOT : min değeri 4'lü sıralama için 1 indexi. Ama 5'li sıralamada
//       en küçük argümanı pb yaptığımıziçin min 2 olacak
// 1- minimum indexi buluyoruz.
// 2- hangi sıradaysa ona göre gereken işlemi yapıyoruz (ra, ra ra, rra)
// 3- en küçük sayı en üste geldiği için pb yapıyoruz
// 4- sort_3() ile 3 argümanı sıralıyoruz
// 5- pa yapıyoruz. 
void	sort_4(t_list **stack_a, t_list **stack_b, int min)
{
	int		min_order;
	t_list	*head;

	min_order = 0;
	head = *stack_a;
	while (head)
	{
		if (head->index == min)
			break ;
		min_order++;
		head = head->next;
	}
	if (min_order == 1)
		rotate(stack_a, 'a');
	else if (min_order == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (min_order == 3)
		reverse_rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	push(stack_b, stack_a, 'a');
}

// 1- indexi 1 olan sayının hangi sırada olduğunu buluyoruz. (min_order)
// 2- hangi sıradaysa gereken işlemi yapıyoruz. (ra, ra ra, rra rra, rra)
// 3- en küçük sayı en üste geldiği için pb yapıyoruz.
// 4- sort_4() yapıyoruz. en küçük index 2 kaldığı için 2 değerini yoluyoruz.
// 5- pa yapıyoruz. 
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int		min_value;

	min_value = min_order(stack_a);
	if (min_value == 1)
		rotate(stack_a, 'a');
	else if (min_value == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (min_value == 3)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (min_value == 4)
		reverse_rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b, 2);
	push(stack_b, stack_a, 'a');
}
