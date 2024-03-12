/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:33:55 by cgray             #+#    #+#             */
/*   Updated: 2023/12/05 17:37:39 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* locate substring 'little' in string 'big' searching 'len' characters
i is 'little' index
loop thru big, nested loop thru little
return string big starting from little inside
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*found;

	i = 0;
	found = (char *)big;
	if (*little == '\0')
		return (found);
	while (*found != '\0' && len > 0)
	{
		i = 0;
		while (little[i] == *(found + i) && i < len)
			i++;
		if (little[i] == '\0')
			return (found);
		found++;
		len--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char str[] = "aaabcabcd";

// 	printf("ft_strnstr:\t%s\n", ft_strnstr(str, "abcd", 9));
// 	printf("strnstr:\t%s\n", strnstr(str, "abcd", 9));
// }
