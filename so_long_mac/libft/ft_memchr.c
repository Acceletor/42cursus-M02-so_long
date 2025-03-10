/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:04:27 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 15:05:52 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

//int main() {
//    char buffer[] = {1, 2, 3, 4, 5};
//
//    // Search for the byte value 3 in the buffer
//    char *result = ft_memchr(buffer, 3, sizeof(buffer));
//
//    if (result != NULL) {
//        printf("Found byte 3 at position: %ld\n", result - buffer);
//    } else {
//        printf("Byte 3 not found.\n");
//    }
//
//    return 0;
//}