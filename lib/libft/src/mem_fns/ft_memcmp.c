/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:23:13 by cgray             #+#    #+#             */
/*   Updated: 2023/10/20 12:36:45 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* returns s1-s2 for the first n characters
obv, if they're equal, return 0.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (len-- > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		else
		{
			p1++;
			p2++;
		}
	}
	return (0);
}
