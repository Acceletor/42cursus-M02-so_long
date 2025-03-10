/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:25:31 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/12 17:01:16 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_digit(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*res;
	int				num_digit;

	num_digit = get_num_digit(n);
	res = malloc((num_digit + 1) * sizeof(char));
	if (!res)
		return (0);
	res[num_digit] = 0;
	if (n < 0)
		num = (unsigned int)-n;
	else
		num = (unsigned int)n;
	while (num_digit-- > 0)
	{
		res[num_digit] = (num % 10) + '0';
		num /= 10;
		if (num_digit == 0 && n < 0)
		{
			res[0] = '-';
			break ;
		}
	}
	return (res);
}
