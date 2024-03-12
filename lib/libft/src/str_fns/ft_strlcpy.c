/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:49:48 by cgray             #+#    #+#             */
/*   Updated: 2023/10/30 16:20:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* copies up to 'size - 1' characters from src to dest.
returns length of string it tried to create.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char	dst[] = "test";
// 	char	dst2[] = "test";
// 	char	source[] = "lorem ipsum dolor sit amet";
// 	size_t	sz = 0;
// 	size_t	len;

// 	printf(" dest:\t%s\n src:\t%s\n", dst, source);
// 	printf("FT_STRLCPY\n");
// 	len = ft_strlcpy(dst, source, sz);
// 	printf(" dest:\t%s\n src:\t%s\n len:\t%li\n", dst, source, len);
// 	printf("STRLCPY MATCH\n");
// 	len = strlcpy(dst2, source, sz);
// 	printf(" dest:\t%s\n src:\t%s\n len:\t%li\n", dst2, source, len);
// }
