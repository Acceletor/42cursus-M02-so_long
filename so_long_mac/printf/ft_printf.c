/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:23:23 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/01/24 17:48:42 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_format(char *format, size_t *counter, va_list arg)
{
	if (*format == 'c')
		ft_putchar_pf(va_arg(arg, int), counter);
	else if (*format == 's')
		ft_putstr_pf(va_arg(arg, char *), counter);
	else if (*format == 'p')
		ft_putptr_pf(va_arg(arg, void *), counter);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_pf(va_arg(arg, int), counter);
	else if (*format == 'u')
		ft_putuint_pf(va_arg(arg, unsigned int), counter, "0123456789");
	else if (*format == 'x')
		ft_putuint_pf(va_arg(arg, unsigned int), counter, HEX_LOWER_BASE);
	else if (*format == 'X')
		ft_putuint_pf(va_arg(arg, unsigned int), counter, HEX_UPPER_BASE);
	else if (*format == '%')
		ft_putchar_pf(*format, counter);
	else
	{
		ft_putchar_pf('%', counter);
		ft_putchar_pf(*format, counter);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	counter;

	if (!format)
		return (0);
	counter = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			ft_handle_format((char *)format, &counter, arg);
		}
		else
			ft_putchar_pf(*format, &counter);
		format++;
	}
	va_end(arg);
	return (counter);
}
