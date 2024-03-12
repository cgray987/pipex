/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:21:40 by cgray             #+#    #+#             */
/*   Updated: 2023/10/30 17:03:23 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* find character in string, returns pointer to first
'search' in string, NULL if not found
*/
char	*ft_strchr(const char *string, int search)
{
	while (*(char *)string != '\0')
	{
		if (*(char *)string == (char)search)
			return ((char *)string);
		string++;
	}
	if (search == '\0')
		return ((char *)string);
	return (NULL);
}
// int	main(void)
// {
// 	char	str[] = "hello";
// 	char	search = '\0';
// 	char	*find;
// 	printf(" str:\t%s\n search:\t%c\n", str, search);
// 	printf("FT_STRCHR\n");
// 	find = ft_strchr(str, search);
// 	printf(" find:\t%s\n", find);
// 	printf("STRCHR MATCH\n");
// 	find = strchr(str, search);
// 	printf(" find:\t%s\n", find);
// }
