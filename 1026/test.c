#include <stdio.h>

static int my_qsort_partition(int *A, int left, int right)
{
	int pivot = A[right];
	int i = left - 1;

	for (int j = left; j < right; j++)
	{
		if (A[j] < pivot)
		{
			i++;

			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	int pivot_pos = i + 1;
	int temp = A[pivot_pos];
	A[pivot_pos] = A[right];
	A[right] = temp;

	return pivot_pos;
}

static void my_qsort(int *A, int left, int right)
{
	if (left >= right)
		return;
	int pivot_new_idx = my_qsort_partition(A, left, right);
	my_qsort(A, left, pivot_new_idx - 1);
	my_qsort(A, pivot_new_idx + 1, right);
}

int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	int A[cnt];
	int B[cnt];
	
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &B[i]);
	}

	my_qsort(A, 0, cnt - 1);

	int result[cnt];
	for (int i = 0; i < cnt; i++)
	{
		result[i] = -1;
	}

	for (int i = 0; i < cnt; i++)
	{
		int max = -1;
		int max_B_index = -1;
		for (int j = 0; j < cnt; j++)
		{
			if (result[j] >= 0)
				continue;
			if (max >= B[j])
				continue;
			max = B[j];
			max_B_index = j;
		}
		result[max_B_index] = A[i];
	}

	int min_total = 0;
	for (int i = 0; i < cnt; i++)
	{
		min_total += (result[i] * B[i]);
	}
	printf("%d\n", min_total);
	return 0;
}
