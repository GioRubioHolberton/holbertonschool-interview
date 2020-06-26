#include "sandpiles.h"

/**
 * sandpiles_sum - sum
 * @grid1: sand 1
 * @grid2: sand 2
 * Return:
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int a, b;

	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			grid1[a][b] = grid1[a][b] + grid2[a][b];
		}
	}
	revise(grid1);
}

/**
 * print - show sandpile
 * @grid: grid sandpile
 * Return:
*/
void print(int grid[3][3])
{
	int a, b;

	printf("=\n");

	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			if (b != 0)
				printf(" ");
			printf("%d", grid[a][b]);
		}
		printf("\n");
	}
}

/**
 * distribution - check position sandpile
 * @grid: grid
 * Return:
 */

void distribution(int grid[3][3])
{
	int mygrid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int a, b, aux;

	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			aux = grid[a][b];
			if (aux > 3)
			{
				grid[a][b] = aux - 4;
				if (a + 1 < 3)
					mygrid[a + 1][b]++;
				if (a - 1 >= 0)
					mygrid[a - 1][b]++;
				if (b + 1 < 3)
					mygrid[a][b + 1]++;
				if (b - 1 >= 0)
					mygrid[a][b - 1]++;
			}
		}
	}
	sandpiles_sum(grid, mygrid);
}

/**
 * revise - grid is stable or not
 * @grid: grid
 * Return:
 */
void revise(int grid[3][3])
{
	int a, b, aux, flag = 0;

	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			aux = grid[a][b];
			if (aux > 3)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)
	{
		print(grid);
		distribution(grid);
	}
}
