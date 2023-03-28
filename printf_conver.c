#include "main.h"

/**
 * print_int - function
 * Description: handles conversion specifies
 * @args: number of arguments
 * @count: characters printed
 *
 * Return: printed characters
 */

int print_int(va_list args, int count)
{
int dgts = 0;
int numbers = va_arg(args, int);
int m = numbers;
int dgt;
int p10 = 1;
int j;

if (numbers < 0)
{
count += _putchar('-');
numbers = -numbers;

m = numbers;
}

do {
dgts++;
m /= 10;
} while (m != 0);

while (dgts > 0)
{

for (j = 1; j < dgts; j++)
{
p10 *= 10;
}

dgt = numbers / p10;
count += _putchar(dgt + '0');
numbers -= dgt * p10;
dgts--;
}
return (count);
}
