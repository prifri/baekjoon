#include <stdio.h>
#include <string.h>
#include <stdint.h>

static void fibonacci(int n, int *record_0, int *record_1) {
	if (record_0[n] >= 0)
		return;

	int n_1 = n - 1;
	int n_2 = n - 2;

	fibonacci(n_1, record_0, record_1);
	fibonacci(n_2, record_0, record_1);

	record_0[n] = record_0[n_1] + record_0[n_2];
	record_1[n] = record_1[n_1] + record_1[n_2];
}

int main(void)
{
	int cnt;

	scanf("%d", &cnt);
	int record_0[41];
	int record_1[41];

	memset(record_0, -1, sizeof(record_0));
	record_0[0] = 1;
	record_1[0] = 0;
	record_0[1] = 0;
	record_1[1] = 1;

	while (cnt--)
	{
		int n;
		scanf("%u", &n);

		fibonacci(n, record_0, record_1);
		printf("%d %d\n", record_0[n], record_1[n]);
	}
	return 0;
}
