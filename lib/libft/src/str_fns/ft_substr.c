/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:48:06 by cgray             #+#    #+#             */
/*   Updated: 2023/11/15 15:42:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*returns substring from 's' beginning from int 'start'.
max size len.
if len 's' is less than start, only return null terminator
if 's' + 'start' is less than 'len', len increased to
to fit substring
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	j;

	if (!s)
		return (ft_strdup(""));
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substring = (char *)malloc((len + 1));
	if (!substring)
		return (0);
	i = 0;
	j = start;
	while (s[j] && i < len)
		substring[i++] = s[j++];
	substring[i] = '\0';
	return (substring);
}
// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	// char	str[] = "lorem ipsum dolor sit amet";
// 	char	*strsub;
// 	strsub = ft_substr("tripouille", 100, 1);
// 	printf("ft_substr:\t%s\n", strsub);
// 	printf("strcmp:\t%d\n", strcmp(strsub, ""));
// 	free(strsub);
// 	return (0);
// }
