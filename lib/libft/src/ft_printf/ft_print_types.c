/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:38:02 by cgray             #+#    #+#             */
/*   Updated: 2023/12/04 15:14:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Writes character 'c' to terminal, and returns 1 if success
*/
int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

/* Writes string to terminal, and returns length of printed chars if success
*/
int	ft_print_string(char *str)
{
	int	count;

	if (!str)
		return (ft_print_string("(null)"));
	count = 0;
	while (*str)
	{
		count += ft_print_char(*str++);
	}
	return (count);
}

/* Writes string to terminal, and returns length of printed chars if success
*/
int	ft_print_digit(long nbr, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (nbr < 0)
	{
		ft_print_char('-');
		return (ft_print_digit(-nbr, base) + 1);
	}
	else if (nbr < base)
		return (ft_print_char(symbols[nbr]));
	else
	{
		count = ft_print_digit(nbr / base, base);
		return (count + ft_print_digit(nbr % base, base));
	}
}

/* Writes string to terminal, and returns length of printed chars if success
has capital symbols used for 'X' format
*/
int	ft_print_upper_digit(long nbr, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (nbr < 0)
	{
		ft_print_char('-');
		return (ft_print_upper_digit(-nbr, base) + 1);
	}
	else if (nbr < base)
		return (ft_print_char(symbols[nbr]));
	else
	{
		count = ft_print_upper_digit(nbr / base, base);
		return (count + ft_print_upper_digit(nbr % base, base));
	}
}

/* Writes pointer address to terminal, and
returns length of printed chars if success
*/
int	ft_print_ptr(unsigned long long ptr)
{
	int		count;
	char	*symbols;

	if (ptr == 0)
		return (ft_print_string("(nil)"));
	symbols = "0123456789abcdef";
	count = 0;
	count = write(1, "0x", 2);
	if (ptr < 16)
		return (ft_print_char(symbols[ptr]) + 2);
	else
	{
		count += ft_print_digit(ptr / 16, 16);
		return (count + ft_print_digit(ptr % 16, 16));
	}
}
// /*Ended up not using these functions*/
// /*--------------------------------------*/
// /* Writes '%'' to terminal, and returns length of printed chars if success
// */
// int	ft_print_percent(void)
// {
// 	return (write(1, "%", 1));
// }
// /*------------------------------------*/
// /* Writes nbr to terminal in base10, returns length of printed chars
// */
// int	ft_print_nbr(int nbr)
// {
// 	int		len;
// 	char	*str;
// 	len = 0;
// 	str = ft_itoa(nbr);
// 	len = ft_print_string(str);
// 	free(str);
// 	return (len);
// }
