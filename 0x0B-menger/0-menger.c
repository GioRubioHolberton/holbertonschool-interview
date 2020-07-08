#include "menger.h"

/**
 * menger - draw menger
 * @level: level
 */

void menger(int level)
{
	int rest, i, j, x, y, prt;
	rest = pow(3, level);

	for (i = 0; i < rest; i++)
	{
		for (j = 0; j < rest; j++)
		{
			prt = '#';
			x = i;
			y = j;
			while (x > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					prt = ' ';
				x = x / 3;
				y = y / 3;
			}
			printf("%c", prt);
		}
		printf("\n");
	}
}
