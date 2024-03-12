/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:15:14 by cgray             #+#    #+#             */
/*   Updated: 2023/12/04 15:14:43 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

/* matches format type (character, formating, pointer, decimal/int,
unsigned int, hexadecimal, or '%' to corresponding function.
function will be called after finding '%' flag in printf 'format' string.
returns length of printed characters
*/
int	ft_formats(va_list args, char flag)
{
	int	print_len;

	print_len = 0;
	if (flag == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (flag == 's')
		print_len += ft_print_string(va_arg(args, char *));
	else if (flag == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (flag == 'd' || flag == 'i')
		print_len += ft_print_digit(va_arg(args, int), 10);
	else if (flag == 'u')
		print_len += ft_print_digit(va_arg(args, unsigned int), 10);
	else if (flag == 'x')
		print_len += ft_print_digit(va_arg(args, unsigned int), 16);
	else if (flag == 'X')
		print_len += ft_print_upper_digit(va_arg(args, unsigned int), 16);
	else if (flag == '%')
		print_len += ft_print_char('%');
	else
		print_len += write(1, &flag, 1);
	return (print_len);
}

/* Prints string with arguments defined by various format flags,
* signaled by '%', accepts %c, %s, %p, %d/%i, %u, %x, %X, %%
* as flags for different formats.
* Outputs number of characters printed to terminal.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_len;

	print_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			print_len += ft_formats(args, *++format);
		else
			print_len += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (print_len);
}
// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	char *ptr = -1;
// 	char *ptr2 = -1;
// 	int ptest = 0;
// 	int ptest2 = 0;
// 	printf("-FT_PRINTF-\t\t-PRINTF-\n\n");
// 	ft_printf("char test: %c\t\t", 'a');
// 	printf("char test: %c\n", 'a');
// 	ft_printf("str test: %s\t", NULL);
// 	printf("str test: %s\n", NULL);
// 	ft_printf("int test: %d\t\t", -1);
// 	printf("int test: %d\n", -1);
// 	ft_printf("uint test: %u\t", -42);
// 	printf("uint test: %u\n", -42);
// 	ft_printf("hex test: %X\t", -1);
// 	printf("hex test: %X\n", -1);
// 	ft_printf("percent test: %%\t\t");
// 	printf("percent test: %%\n");
// 	ptest = ft_printf("ptr test: %p\t\t", ptr);
// 	ptest2 = printf("ptr test: %p\n", ptr);
// 	ft_printf("ptest chars: %d\t\tptest2 chars: %d\n", ptest, ptest2);
// }
