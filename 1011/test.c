#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	while (cnt--)
	{
		uint32_t x, y;
		scanf("%u %u", &x, &y);

		uint32_t distance = y - x;

		if (distance == 1)
		{
			printf("1\n");
			continue;

		}

		uint32_t sqrt_value = sqrt(distance);
		uint32_t sqrt_value_power = sqrt_value * sqrt_value;

		if (sqrt_value_power == distance)
		{
			printf("%d\n", 2* sqrt_value - 1);
			continue;
		} 

		if (distance <= (sqrt_value_power + sqrt_value))
		{
			printf("%d\n", 2 * sqrt_value);
			continue;
		}

		printf("%d\n", 2 * sqrt_value + 1);
	}
	return 0;
}
