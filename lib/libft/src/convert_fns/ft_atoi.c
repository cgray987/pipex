/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:45:34 by cgray             #+#    #+#             */
/*   Updated: 2023/10/30 18:02:19 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* converts given string to int.
digits in string can be proceeded by spaces/linefeeds,
'-' or '+' changes sign of number.
stops after the first non-digit after string digits
*/
int	ft_atoi(const char *string)
{
	int	num;
	int	neg;

	num = 0;
	neg = 1;
	while (*string == ' ' || (*string >= 9 && *string <= 13))
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			neg = -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		num = num * 10 + *string - '0';
		string++;
	}
	return (num * neg);
}
