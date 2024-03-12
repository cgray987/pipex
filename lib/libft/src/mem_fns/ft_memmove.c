/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:14:27 by cgray             #+#    #+#             */
/*   Updated: 2023/11/02 13:59:29 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* similar to memcpy; but has protection for overlapping
if src < dest (src inside dest); copy from the
end of src into dest to avoid overlap
else, treated like memcpy, and copy from
beginning of src into dest
*/
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
	{
		d += len;
		s += len;
		while (len-- > 0)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		while (len-- > 0)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
