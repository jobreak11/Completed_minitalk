/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:13:35 by gyeepach          #+#    #+#             */
/*   Updated: 2024/04/24 17:22:20 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		count += ft_putaddress((va_arg(ap, void *)));
	else if (type == 'x')
		count += ft_puthexa((va_arg(ap, unsigned int)), 0);
	else if (type == 'X')
		count += ft_puthexa((va_arg(ap, unsigned int)), 1);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr((va_arg(ap, int)));
	else if (type == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	else
		count += write(1, &type, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*format == '%')
				count += ft_print_format(*(++format), ap);
			else if (*format != '\0')
				count += write(1, format, 1);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
// 	int a = 42;
// 	int *p = &a;
// 	int **pp = &p;
// 	char *s = 0;

// 	int ret1, ret2;

// 	ret1 = ft_printf("%p\n", NULL);
// 	ret2 = printf("%p\n", NULL);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

// 	ret1 = ft_printf("%p\n", &printf);
//     ret2 = printf("%p\n", &printf);
//     printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

//     ret1 = ft_printf("%p\n", pp);
//     ret2 = printf("%p\n", pp);
//     printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

//     ret1 = ft_printf("%p\n", p);
//     ret2 = printf("%p\n", p);
//     printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

// 	ret1 = ft_printf("%p\n", s);
// 	ret2 = printf("%p\n", s);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

// 	ret1 = ft_printf("%s\n", s);
// 	ret2 = printf("%s\n", s);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

//     return 0;
// }