/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:55:02 by cgray             #+#    #+#             */
/*   Updated: 2024/01/16 15:17:59 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_in_base(char c, int base)
{
	char	*low;
	char	*upper;
	int		i;

	low = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == low[i] || c == upper[i])
			return (i);
		i++;
	}
	return (-1);
}

/* converts given string/base to int in base specified.
digits in string can be proceeded by spaces/linefeeds,
'-' or '+' changes sign of number.
stops after the first non-digit after string digits
 */
int	ft_atoi_base(char *str, int base)
{
	int	num;
	int	neg;

	num = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (num_in_base(*str, base) != -1)
	{
		num = num * base + num_in_base(*str, base);
		str++;
	}
	return (neg * num);
}
// int	main(void)
// {
// 	char *num = "16F";
// 	printf("%d\n", ft_atoi_base(num, 16));
// }
