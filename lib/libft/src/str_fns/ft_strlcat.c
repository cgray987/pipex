/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:32:19 by cgray             #+#    #+#             */
/*   Updated: 2023/10/30 16:39:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*appends up to 'size' characters of string 'src' to the end of 'dest'
returns total length of created string tried to create,
(at most 'size' - 'length of dest' - 1)
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	offset;
	size_t	i;
	size_t	init_dest_len;

	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	offset = ft_strlen(dest);
	init_dest_len = offset;
	i = 0;
	if (init_dest_len < size - 1 && size > 0)
	{
		while (src[i] && size > offset + 1)
		{
			dest[offset] = src[i];
			offset++;
			i++;
		}
		dest[offset] = '\0';
	}
	return (init_dest_len + ft_strlen(src));
}
// #include <stdio.h>
// int main(void)
// {
// 	char	dst[] = "test";
// 	char	dst2[] = "test";
// 	char	source[] = "lorem ipsum dolor sit amet";
// 	size_t	sz = 15;
// 	size_t	len;
// 	printf(" dest:\t%s\n src:\t%s\n", dst, source);
// 	printf("FT_STRLCAT\n");
// 	len = ft_strlcat(dst, source, sz);
// 	printf(" dest:\t%s\n src:\t%s\n len:\t%li\n", dst, source, len);
// 	printf("STRLCAT MATCH\n");
// 	len = strlcat(dst2, source, sz);
// 	printf(" dest:\t%s\n src:\t%s\n len:\t%li\n", dst2, source, len);
// }
