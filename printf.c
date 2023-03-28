#include "main.h"
#include <stdarg.h>

/**
 * _printf - function
 * Description: prints number of characters
 * @format: string
 *
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list parameters;
	int printed_characters = 0;

	va_start(parameters, format);

	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'c')
			{
				int c = va_arg(parameters, int);
				putchar(c);
				printed_characters++;
				break;
			}
			else if (*(format + 1) == 's')
			{
				char *s = va_arg(parameters, char *);
				
				s++;

				printed_characters++;
			}
			break;

		}
		else
		{
			putchar('%');
			printed_characters++;
			break;
		}
		format += 2;

		putchar(*format);
		format++;
		printed_characters++;
	}
	
	va_end(parameters);

	return (printed_characters);
}
