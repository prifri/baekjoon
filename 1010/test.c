#include <stdio.h>

int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	while (cnt--)
	{
		int left, right;
		scanf("%d %d", &left, &right);

		if (left == 0 || right == 0)
		{
			printf("0\n");
			continue;
		}

		unsigned long long int result = 1;

		int i;
		for (i = 1; i <= left; i++)
		{
			result = (result * (right - i + 1)) / i;
		}

		printf("%llu\n", result);
	}
	return 0;
}
