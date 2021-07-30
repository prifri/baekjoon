#include <stdio.h>

int main(void)
{
	int n, f;
	scanf("%d", &n);
	scanf("%d", &f);

	int n_min = n - (n % 100);

	while (1)
	{
		if ((n_min % f) == 0)
		{
			printf("%02d\n", n_min % 100);
			break;
		}
		n_min++;
	}
	return 0;
}
