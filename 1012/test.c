#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

static int offset[2][4] = {{0, 0, -1, 1}, {1, -1, 0, 0}};

static void clear_adf_baechu_dfs(uint8_t **map,
								 int map_x_max,
								 int map_y_max, int x, int y)
{
	map[y][x] = 0;

	for (uint32_t i = 0; i < sizeof(offset[0]); i++)
	{
		int next_x = offset[0][i] + x;
		int next_y = offset[1][i] + y;

		if (next_x < 0 || next_y < 0 || 
			next_x >= map_x_max ||
			next_y >= map_y_max ||
			map[next_y][next_x] == 0)
			continue;

		clear_adf_baechu_dfs(map, map_x_max, map_y_max, next_x, next_y);
	}
}

int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	while (cnt--)
	{
		int m, n, baechu_cnt;
		scanf("%d %d %d", &m, &n, &baechu_cnt);

		if (m <= 0 || n <= 0 || baechu_cnt == 0)
		{
			printf("0\n");
			continue;
		}

		uint8_t **map;
		map = malloc(sizeof(uint8_t *) * n);
		for (int i = 0; i < n ; i++)
		{
			map[i] = calloc(m * sizeof(uint8_t), 1);
		}
		
		for (int i = 0; i < baechu_cnt; i++)
		{
			int x, y;

			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}

		int worm_cnt = 0;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (map[y][x] == 0)
					continue;
				clear_adf_baechu_dfs(map, m, n, x, y);
				worm_cnt++;
			}
		}

		printf("%d\n", worm_cnt);
		for (int i = 0; i < n ; i++)
		{
			free(map[i]);
		}
		free(map);
	}
	return 0;
}
