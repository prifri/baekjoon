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
	int num_cnt;
	scanf("%d", &num_cnt);

	int num[num_cnt];
	for (int i= 0; i < num_cnt; i++)
	{
		scanf("%d", &num[i]);
	}

	if (num_cnt == 1)
	{
		printf("%d\n", num[0]);
		return 0;
	}

	my_qsort(num, 0, num_cnt - 1);

	int diff[num_cnt][num_cnt];

	for (int i = 0; i < num_cnt; i++)
	{
		for (int j =0; j < num_cnt; j++)
		{
			diff[i][j] = num[i] - num[j];
			if (diff[i][j] < 0)
				diff[i][j] = -diff[i][j];
		}
	}

	int min = 99999;
	int min_idx = -1;
	for (int i = 1; i < num_cnt; i++)
	{
		if (min > diff[0][i])
		{
			min = diff[0][i];
			min_idx = i;
		}
	}

	int result[num_cnt];

	result[0] = 0;
	result[1] = min_idx;

	for (int i = 0; i < num_cnt; i++)
	{
		diff[i][min_idx] = -1;
		diff[min_idx][i] = -1;
	}

	if (num_cnt == 2)
	{
		printf("%d %d\n", num[result[0]], num[result[1]]);
		return 0;
	}

	min = 99999;
	min_idx = -1;
	for (int i = 1; i < num_cnt; i++)
	{
		if (diff[0][i] < 0)
			continue;

		if (min > diff[0][i])
		{
			min = diff[0][i];
			min_idx = i;
		}
	}

	result[num_cnt - 1] = min_idx;
	diff[0][min_idx] = -1;

	for (int i = 0; i < num_cnt; i++)
	{
		diff[i][min_idx] = -1;
		diff[min_idx][i] = -1;
	}

	if (num_cnt == 3)
	{
		printf("%d %d %d\n", num[result[0]], num[result[1]], num[result[2]]);
		return 0;
	}

	for (int i = 1; i < num_cnt - 1; i++)
	{
		int j;
		min = 99999;
		min_idx = -1;
		for (j = 0; j < num_cnt; j++)
		{
			if (diff[result[i]][j] < 0)
				continue;
		}
	}
#if 0

	result[0] = num[0];
	int result_idx = 1;

	for (int i = 1 ; i < num_cnt; i += 2)
	{
		result[result_idx++] = num[i];
	}

	result_idx = 1;
	for (int i = 2 ; i < num_cnt; i += 2)
	{
		result[num_cnt - result_idx] = num[i];
		result_idx++;
	}

	for (int i = 0; i < num_cnt; i++)
	{
		int j = i + 1;
		for (; j < num_cnt; j++)
		{
			if (result[i] == result[j])
				break;
		}

		if (j == num_cnt)
			continue;

		if (result[i + 1] <= result[j - 1])
			continue;

		int swap_i = i + 1;
		int swap_j = j - 1;

		while (swap_i < swap_j)
		{
			int tmp = result[swap_i];
			result[swap_i] = result[swap_j];
			result[swap_j] = tmp;
			swap_i++;
			swap_j--;
		}
	}
	for (int i = 0; i < num_cnt; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
#endif
	return 0;
}
