/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:35:53 by cgray             #+#    #+#             */
/*   Updated: 2023/10/20 12:31:46 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*copies len characters from src to dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	while (len-- > 0)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
