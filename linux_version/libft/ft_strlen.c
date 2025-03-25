/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:35:22 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/03 14:44:24 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l] != 0)
	{
		l++;
	}
	return (l);
}

// int main() {
//     const char *str = "Hello, world!";
//     printf("Length of the string: %zu\n", ft_strlen(str)); //13
//     return 0;
// }