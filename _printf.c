#include "main.h"
#include <stdarg.h>

int _puts(char *str);

/**
 * _printf - function
 * Description: produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list parameters;
	int format_ptn, printed_characters;

	va_start(parameters, format);

	format_ptn = 0;
	printed_characters = 0;

	while (format[format_ptn])
	{
		if (format[format_ptn] == '%')
		{
			if (format[format_ptn + 1] == 'c')
			{
				_putchar(va_arg(parameters, int));
				printed_characters++;
				format_ptn += 2;
			}
			else if (format[format_ptn + 1] == 's')
			{
				printed_characters = _puts(va_arg(parameters, char *));
				format_ptn += 2;
			}
			else
			{
				_putchar(format[format_ptn]);
				printed_characters++;
				format_ptn++;
			}
		}
		else
		{
			_putchar(format[format_ptn]);
			printed_characters++;
			format_ptn++;
		}
	}
	va_end(parameters);

	return (printed_characters);
}
/**
 * _puts - function
 * Description: determines string length
 * @str: string
 *
 * Return: string length
 */
int _puts(char *str)
{
	int str_ptn;

	for (str_ptn = 0; str[str_ptn] != '\0'; str_ptn++)
	{
	_putchar(str[str_ptn]);
	}

	return (str_ptn);
}

