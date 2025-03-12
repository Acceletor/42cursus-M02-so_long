/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:23:09 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/01/10 16:28:22 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	if (!ptr)
	{
		ft_putstr_pf("(nil)", counter);
		return ;
	}
	ft_putstr_pf("0x", counter);
	str = ft_convert_pf(ptr_address, HEX_LOWER_BASE);
	ft_putstr_pf(str, counter);
	free (str);
}
