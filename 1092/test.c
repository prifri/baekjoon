#include <stdio.h>

static int my_qsort_partition(int *A, int left, int right)
{
	int pivot = A[right];
	int i = left - 1;

	for (int j = left; j < right; j++)
	{
		if (A[j] > pivot)
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
	int crane_cnt;
	scanf("%d", &crane_cnt);

	int crane_limit[crane_cnt];

	for (int i = 0; i < crane_cnt; i++)
	{
		scanf("%d", &crane_limit[i]);
	}

	my_qsort(crane_limit, 0, crane_cnt - 1);

	int box_cnt;
	scanf("%d", &box_cnt);

	int box_weight[box_cnt];
	int impossible = 0;
	for (int i = 0; i < box_cnt; i++)
	{
		scanf("%d", &box_weight[i]);
		if (box_weight[i] > crane_limit[0])
			impossible = 1;
	}

	if (impossible)
	{
		printf("-1\n");
		return 0;
	}
	my_qsort(box_weight, 0, box_cnt - 1);

	int roop_cnt = 0;
	int start_idx = 0;
	while (1)
	{
		roop_cnt++;

		for (int crane_idx = 0 ; crane_idx < crane_cnt; crane_idx++)
		{
			const int curr_crane = crane_limit[crane_idx];

			int box_idx;
			int is_remain = 0;

			for (box_idx = start_idx; box_idx < box_cnt; box_idx++)
			{
				if (box_weight[box_idx] < 0) {
					continue;
				}

				if (box_weight[box_idx] <= curr_crane)
				{
					box_weight[box_idx] = -1;
					is_remain = 0;
					break;
				}
				is_remain = 1;
			}
		}

		int new_start_idx = start_idx;
		for (int i = start_idx; i < box_cnt; i++)
		{
			if (box_weight[i] >= 0)
				break;
			new_start_idx = i;
		}
		start_idx = new_start_idx + 1;
		if (start_idx == box_cnt)
		{
			printf("%d\n", roop_cnt);
			return 0;
		}
	}
	return 0;
}
