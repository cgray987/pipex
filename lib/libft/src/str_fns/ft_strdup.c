/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:07:15 by cgray             #+#    #+#             */
/*   Updated: 2023/11/02 14:03:11 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*duplicate string into pointer
use malloc to determine if mem is available,
otherwise return null. also return null if 's'
is empty
*/
char	*ft_strdup(const char *s)
{
	char	*p;
	int		len;
	int		i;

	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p || !s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
