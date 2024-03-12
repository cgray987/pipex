/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:47:52 by cgray             #+#    #+#             */
/*   Updated: 2023/10/23 16:17:27 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* removes leading and trailing 'set' characters of string
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		leading;
	int		trailing;
	char	*trim;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	leading = 0;
	trailing = ft_strlen(s1) - 1;
	while (s1[leading] && ft_strchr(set, s1[leading]))
		leading++;
	while (trailing > leading && ft_strchr(set, s1[trailing]))
		trailing --;
	trim = (char *)malloc(sizeof(char) * (trailing - leading + 2));
	if (!trim)
		return (NULL);
	i = 0;
	while (leading <= trailing)
		trim[i++] = s1[leading++];
	trim[i] = '\0';
	return (trim);
}
