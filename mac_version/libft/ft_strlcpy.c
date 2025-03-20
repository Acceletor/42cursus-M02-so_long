/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:58 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 15:46:40 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

//#include <stdio.h>
//int main()
//{
//    char src[] = "hello-World!";
//    char dest[8];
//
//    // Copy src into dest with a buffer size of 8
//    size_t result = ft_strlcpy(dest, src, sizeof(dest));
//
//    // Print the destination buffer and the result
//    printf("Destination: %s\n", dest);
//    printf("Length of src: %zu\n", result);
//
//    return 0;
//}