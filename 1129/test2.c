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

static void permutation(int *arr, int arr_size, int depth, int *result, int *max)
{
	if (arr_size == depth)
	{
		int curr_max = get_max(arr, arr_size);
		if (curr_max < *max)
		{
			for (int i = 0; i < arr_size; i++)
			{
				result[i] = arr[i];
				printf("%d ", arr[i]);
			}
			printf(" : %d\n", *max);
			*max = curr_max;
		}
		return;
	}

	int next_depth = depth + 1;
	for (int i = depth; i < arr_size; i++)
	{
		int temp = arr[i];
		arr[i] = arr[depth];
		arr[depth] = temp;

		permutation(arr, arr_size, next_depth, result, max);

		temp = arr[i];
		arr[i] = arr[depth];
		arr[depth] = temp;
	}
}

static void permutation_0(int *arr, int arr_size, int *result, int *max)
{
	permutation(arr, arr_size, 2, result, max);
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

	int max = 0;
	int result[num_cnt];
	result[0] = num[0];
	for (int i = 1 ; i < num_cnt; i++)
	{
		result[i] = num[i];
		int diff = get_diff(result, i, i - 1);
		if (max < diff)
			max = diff;
	}

	int diff = get_diff(result, 0, num_cnt - 1);
	if (max < diff)
		max = diff;

	permutation_0(num, num_cnt, result, &max);

	for (int i = 0; i < num_cnt; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
