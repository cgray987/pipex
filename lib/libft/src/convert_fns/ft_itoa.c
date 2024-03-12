/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:49:39 by cgray             #+#    #+#             */
/*   Updated: 2023/11/07 14:59:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*counts number of digits in base 10*/
static size_t	countdigits(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/*returns a string representing int 'n' in base 10
*/
char	*ft_itoa(int n)
{
	int		digit;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = countdigits(n);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	digit--;
	while (n != 0)
	{
		str[digit] = (n % 10) + '0';
		n /= 10;
		digit--;
	}
	return (str);
}
