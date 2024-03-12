/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:05:29 by cgray             #+#    #+#             */
/*   Updated: 2024/02/12 15:56:35 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* returns concat string of s1 + s2
Must free return value later.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		join[i] = s2[i - len1];
		i++;
	}
	join[len1 + len2] = '\0';
	return (join);
}
