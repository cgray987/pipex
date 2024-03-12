/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:00:14 by cgray             #+#    #+#             */
/*   Updated: 2023/10/30 16:47:45 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Returns pointer to last character 'search' in string,
NULL if not found
*/
char	*ft_strrchr(const char *string, int search)
{
	char	*found;

	found = NULL;
	while (*string != '\0')
	{
		if (*(char *)string == (char)search)
			found = (char *)string;
		string++;
	}
	if (*string == (char)search)
		return ((char *)string);
	else
		return ((char *)found);
}
/*iterate thru string, if search is found, add to pointer 'found'
if indexed 'string' equals search, return last pos 'search' in 'string'
else, search is not in 'string and return 'found' (NULL)
note, cannot just return NULL bc then the variable would not be used*/
