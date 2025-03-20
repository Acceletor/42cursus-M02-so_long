/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:46:09 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 15:39:58 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

// int main() {
//     char buffer[50]; // Create a buffer to test memset
//     size_t i;
//
//     // Initialize the buffer with some known values
//     for (i = 0; i < sizeof(buffer); i++) {
//         buffer[i] = '.';
//     }
//     buffer[sizeof(buffer) - 1] = '\0';
//
//     printf("Before memset: %s\n", buffer);
//
//     // Call memset to fill the first 10 bytes with '*'
//     ft_memset(buffer, '*', 10);
//
//     printf("After memset:  %s\n", buffer);
//
//     // Call memset to fill the buffer with 'X', excluding the null terminator
//     ft_memset(buffer, 'X', sizeof(buffer) - 1);
//
//     printf("Final memset:  %s\n", buffer);
//
//     return 0;
// }