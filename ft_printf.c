#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap; //a list that point to each arg "..." in the list
	char	*p;
	int		i;

	va_start(ap, format); //make ap point to first unnamed arg "..."

	p = (char *)format;
	i = -1;
	while (p[++i] != '\0')
	{
		if (p[i] == '%')
		{
			if (p[i + 1] == 'd')
			{
				printf("%d", va_arg(ap, int));
				i += 2;
			}
			if (p[i + 1] == 'i')
			{
				printf("%i", va_arg(ap, int));
				i += 2;
			}
			if (p[i + 1] == 'c')
			{
				printf("%c", va_arg(ap, int));
				i += 2;
			}
			if (p[i + 1] == 's')
			{
				printf("%s", va_arg(ap, char *));
				i += 2;
			}
		}
		putchar(p[i]);
	}
	va_end(ap); // clean up the list when done
	return (strlen(format));
}
