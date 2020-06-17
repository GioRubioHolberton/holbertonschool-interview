#include "palindrome.h"

/**
 * is_palindrome - is or not palindrome
 * @n: num
 * Return: 1 or 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long num = n, rever = 0, aux;

	while (num > 0)
	{
		aux = num % 10;
		rever = aux + rever * 10;
		num = num / 10;
	}
	if (rever != n)
		return (0);
	else
		return (1);
}
