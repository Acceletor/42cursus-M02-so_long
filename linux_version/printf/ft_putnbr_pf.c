/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:23:13 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/01/10 15:04:57 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_pf(char c, size_t *counter);

static void	ft_putunsigned_recursive(unsigned int num, size_t *counter)
{
	if (num > 9)
		ft_putunsigned_recursive((num / 10), counter);
	ft_putchar_pf('0' + (num % 10), counter);
}

void	ft_putnbr_pf(int num, size_t *counter)
{
	unsigned int	n;

	if (num < 0)
	{
		n = (unsigned int)(-num);
		ft_putchar_pf('-', counter);
	}
	else
		n = (unsigned int)num;
	ft_putunsigned_recursive(n, counter);
}
