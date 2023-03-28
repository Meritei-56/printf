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
			switch (*(format + 1))
			{	
			case 'c':
			{
				int c = va_arg(parameters, int);
				putchar(c);
				printed_characters++;
				break;
			}
			case 's':
			{
				char *s = va_arg(parameters, char *);
				while (*s)
				{
				putchar(*s);

				s++;

				printed_characters++;
				}
				break;

			}	
			case '%':
			{
			putchar('%');
			printed_characters++;
			break;
			}
		}
		format += 2;
		}
		else
		{

		putchar(*format);
		format++;
		printed_characters++;
		}
	}
	va_end(parameters);

	return (printed_characters);
}
