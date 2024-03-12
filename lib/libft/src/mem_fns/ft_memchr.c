/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:05:58 by cgray             #+#    #+#             */
/*   Updated: 2023/11/02 13:57:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Searches for character 'little' in 'big'
returns pointer to first found 'little' in 'big'
does not stop after a \0 value
*/
void	*ft_memchr(const void *big, int little, size_t len)
{
	char	*found;

	found = (char *)big;
	while (len-- > 0)
	{
		if (*found != (char)little)
			found++;
		else
			return (found);
	}
	return (0);
}
