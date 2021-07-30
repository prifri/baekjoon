#include <stdio.h>

int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	int buf[10];

	while (cnt--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		int div_cnt = 0;

		int a1 = a % 10;
		int cal = a1;
		while (1)
		{
			buf[++div_cnt] = cal;
			cal *= a1;
			cal %= 10;
			if (cal == a1)
			{
				buf[0] = buf[div_cnt];
				break;
			}
		}

		int result;
		if (div_cnt == 0)
		{
			result = a1;
		} else
		{
			result = buf[b % div_cnt];
		}
		if (result == 0)
			printf("10\n");
		else
			printf("%d\n", result);
	}
	return 0;
}
