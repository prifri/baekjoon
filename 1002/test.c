#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void)
{
	int cnt;

	scanf("%d", &cnt);

	while (cnt--)
	{
		int x1, y1, x2, y2, r1, r2;
		scanf("%d %d %d %d %d %d",
			  &x1, &y1, &r1, &x2, &y2, &r2);

		uint64_t x_diff_power = (x1 - x2) * (x1 - x2);
		uint64_t y_diff_power = (y1 - y2) * (y1 - y2);

		if (x_diff_power == 0 && y_diff_power == 0 && r1 == r2)
		{
			printf("-1\n");
			continue;
		}

		uint64_t distance_power = x_diff_power + y_diff_power;
		uint64_t r1_r2_add_power = (r1 + r2) * (r1 + r2);
		uint64_t r1_r2_sub_power = (r1 - r2) * (r1 - r2);

		if (distance_power == r1_r2_add_power || distance_power == r1_r2_sub_power)
		{
			printf("1\n");
			continue;
		}

		if (distance_power > r1_r2_add_power || distance_power < r1_r2_sub_power)
		{
			printf("0\n");
			continue;
		}

		printf("2\n");
	}

	return 0;
}
