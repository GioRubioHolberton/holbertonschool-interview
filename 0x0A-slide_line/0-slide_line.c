#include "slide_line.h"

/**
 * slide_line - 2048 game
 * @line: items
 * @size: size
 * @direction: left, right
 * Return: 1, 0
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t in = 0, sw = 1, mov = 0;
	int aux, change, count = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		sw = size - 2;
		in = size - 1; 
	}
	while (mov < size)
	{
		aux = sw;
		change = 0;
		mov = count + 1;
		while (mov < size)
		{
			if (line[sw] == line[in] && line[in] != 0)
			{
				line[in] = line[in] * 2;
				line[sw] = 0;
				break;
			}
			if (line[sw] != 0 && line[in] == 0)
			{
				line[in] = line[sw];
				line[sw] = 0;
				change = 1;
				sw = aux;
				count--;
				break;
			}
			if (line[sw] != 0)
				break;

			if (SLIDE_RIGHT)
				direction = sw--;
			else
				direction = sw++;
			mov++;
		}
		if (line[in] == 0)
			break;
		if (change == 0 && direction == SLIDE_LEFT)
		{
			in++;
			sw = in + 1;
		}
		if (change == 0 && direction == SLIDE_RIGHT)
		{
			in--;
			sw = in - 1;
		}

		count++;
	}
	return (1);
}
