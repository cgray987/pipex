/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:34 by cgray             #+#    #+#             */
/*   Updated: 2023/11/02 13:59:57 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns 'str' with 'value' set for each position for 'len' characters
set variable to str
iteratate thru add_v for input len
set variable add_v to value
increment variable
return modified string
*/
void	*ft_memset(void *str, int value, size_t len)
{
	unsigned char	*add_v;

	add_v = (unsigned char *)str;
	while (len-- > 0)
	{
		*add_v = (unsigned char)value;
		add_v++;
	}
	return (str);
}
