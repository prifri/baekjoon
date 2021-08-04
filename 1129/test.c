#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

static int get_diff(int *arr, int a, int b)
{
	int diff = arr[a] - arr[b];
	if (diff < 0)
		return -diff;
	return diff;
}

static int get_max(int *arr, int arr_size)
{
	int max = 0;
	for (int i = 1 ; i < arr_size; i++)
	{
		int diff = get_diff(arr, i, i - 1);
		if (max < diff)
			max = diff;
	}

	int diff = get_diff(arr, 0, arr_size - 1);
	if (max < diff)
		max = diff;
	return max;
}

static int is_target_max(int *arr, int arr_size, int find_max)
{
	int max = 0;
	for (int i = 1 ; i < arr_size; i++)
	{
		int diff = get_diff(arr, i, i - 1);
		if (diff > find_max)
			return -1;

		if (max < diff)
			max = diff;
	}

	int diff = get_diff(arr, 0, arr_size - 1);
	if (max < diff)
		max = diff;

	if (max != find_max) {
		return -1;
	}
	return 0;
}

static int retry_sort_recursive(int *arr,
								int start,
								int end,
								int num_cnt,
								int max)
{
	if (start >= end)
		return -1;

	int start_next = start + 1;
	uint32_t copy_size = sizeof(int) * (end - start);

	int tmp = arr[end];
	memmove(&arr[start_next], &arr[start], copy_size);
	arr[start] = tmp;

	if (is_target_max(arr, num_cnt, max) == 0)
		return 0;

	if (retry_sort_recursive(arr, start_next, end, num_cnt, max) == 0)
		return 0;

	tmp = arr[start];
	memmove(&arr[start], &arr[start_next], copy_size);
	arr[end] = tmp;
	return -1;
}

//https://www.geeksforgeeks.org/minimize-the-maximum-absolute-difference-of-adjacent-elements-in-a-circular-array/
static void sort_minimun_max_diff(int *arr, int num_cnt)
{
	for (int i = 1; i <= (num_cnt / 2); i++)
	{
		int n = arr[i];
		int diff_idx = num_cnt - i;;
		memmove(&arr[i], &arr[i + 1], (diff_idx - 1) * sizeof(int));
		memmove(&arr[diff_idx + 1], &arr[diff_idx], (i - 1) * sizeof(int));
		arr[diff_idx] = n;
	}

}

static int *t1(int *num, int num_cnt)
{
	my_qsort(num, 0, num_cnt - 1);

	int result[num_cnt];

	for (int i = 0; i < num_cnt; i++)
	{
		result[i] = num[i];
	}

	sort_minimun_max_diff(result, num_cnt);

	int max = get_max(result, num_cnt);

	for (int i = 0; i < num_cnt; i++)
	{
		int min_idx = i;

		for (int j = i + 1; j < num_cnt; j++)
		{
			if (result[min_idx] <= result[j])
				continue;

			retry_sort_recursive(result, min_idx, j, num_cnt, max);
		}

	}

	int *ret = (int *)malloc(num_cnt * sizeof(int));
	for (int i = 0; i < num_cnt; i++)
	{
		ret[i] = result[i];
	}
	return ret;
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

	int *result = t1(num, num_cnt);

	for (int i = 0; i < num_cnt; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	free(result);
	return 0;
}
