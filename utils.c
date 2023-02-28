/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:14:08 by makbas            #+#    #+#             */
/*   Updated: 2023/02/26 23:14:10 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Aynı sayıların olup olmadığı kontrolünü yapıyoruz.
// i değerini 1 arttırarak başlıyoruz.
// nb değeri ile nb+1'den başlayıp argv dizisindeki 
// tüm değerlerle karşılaştırma yapar. Eğer hata varsa
// 1 değerini geri döndürecek
int	is_duplicate(int nb, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

// NOT : atoi kontrolü yaptığımız için başında '+' işareti olduğunu kontrol etmiyoruz.
// Eğer numaralardan başka bir karakter içeriyorsa bize '1' değerini geri döndürecek.
int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

// hata mesajını yazıp exit() ile uygulamayı sonlandırır.
void	error(void)
{
	write(1, "Error\n", 7);
	exit(0);
}

// listenin sıralıp olup olmadığını kontrol ediyoruz. 
// 1- mevcut değer ile sonraki değeri kontrol ediyor döngüyle.
//    Eğer mevcut ve sonraki değerlerin tümü sıralıysa 1 değerini dönecek
int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

//struct yapısının içindeki tüm değerleri free'ler
void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
