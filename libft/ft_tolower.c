/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:15:56 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 16:16:33 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((char)c >= 'A' && (char)c <= 'Z')
		return (c + 32);
	return (c);
}

//int main() {
//
//    printf("%c\n", ft_tolower('9'));
//    printf("%c\n", ft_tolower('W'));
//
//    return 0;
//}