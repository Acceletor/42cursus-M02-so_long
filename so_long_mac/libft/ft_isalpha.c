/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:01 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/03 13:52:26 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int ch)
{
	if (((char)ch >= 'A' && (char)ch <= 'Z')
		|| ((char)ch >= 'a' && (char)ch <= 'z'))
	{
		return (1);
	}
	return (0);
}

// int main()
// {
// 	printf("%i", ft_isalpha('1'));
// }