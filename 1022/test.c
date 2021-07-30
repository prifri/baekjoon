#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
	int r1, c1, r2, c2;

	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	int x_len = c2 - c1;
	int y_len = r2 - r1;

	if (x_len < 0)
		x_len = -x_len;

	x_len++;

	if (y_len < 0)
		y_len = -y_len;
	y_len++;

	uint32_t **map = (uint32_t **)malloc(sizeof(uint32_t *) * y_len);
	for (int i = 0; i < y_len; i++)
	{
		map[i] = (uint32_t *)malloc(sizeof(uint32_t) * x_len);
	}

	int x = 0;
	int y = 0;

	if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
	{
		map[y - r1][x - c1] = 1;
	}

	x++;
	if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
	{
		map[y - r1][x - c1] = 2;
	}

	y--;
	if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
	{
		map[y - r1][x - c1] = 3;
	}

	int num = 3;
	int add = 1;

	int remain = x_len * y_len;
	while (1)
	{
		add++;
		for (int i = 0; i < add; i++)
		{
			x--;
			++num;
			if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
			{
				map[y - r1][x - c1] = num;
				remain--;
			}
		}

		for (int i = 0; i < add; i++)
		{
			y++;
			++num;
			if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
			{
				map[y - r1][x - c1] = num;
				remain--;
			}
		}

		add++;
		for (int i = 0; i < add; i++)
		{
			x++;
			++num;
			if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
			{
				map[y - r1][x - c1] = num;
				remain--;
			}
		}

		for (int i = 0; i < add; i++)
		{
			y--;
			++num;
			if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
			{
				map[y - r1][x - c1] = num;
				remain--;
			}
		}
	
			if (remain == 0)
			{
				int max = 0;
				int check = map[r1][c1];
				if (max < check)
					max = check;

				check = map[r1][c2];
				if (max < check)
					max = check;

				check = map[r2][c1];
				if (max < check)
					max = check;

				check = map[r2][c2];
				if (max < check)
					max = check;

				int digit = 0;
				while (max != 0)
				{
					digit++;
					max /= 10;
				}

				for (int i = 0; i < y_len; i++)
				{
					for (int j = 0; j < x_len; j++)
					{
						printf("%*d ", digit, map[i][j]);
					}
					printf("\n");
				}

				return 0;
			}
#if 0
		printf("\n");
		for (int i = 4990; i < 5010; i++)
		{
			for (int j = 4990; j < 5010; j++)
			{
				printf("%3d ", map[i][j]);
			}
			printf("\n");
		}

		int c;
		scanf("%d", &c);
		printf("\n");
#endif
	}
	return 0;
}
