#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
		if (max < diff)
			max = diff;
		if (max > find_max)
			return -1;
	}

	int diff = get_diff(arr, 0, arr_size - 1);
	if (max < diff)
		max = diff;

	if (max != find_max)
		return -1;
	return 0;
}

static void show_arr(int *arr, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//https://www.geeksforgeeks.org/minimize-the-maximum-absolute-difference-of-adjacent-elements-in-a-circular-array/
int *t1(int *num, int num_cnt)
{
	my_qsort(num, 0, num_cnt - 1);

	//int max = 0;
	int result[num_cnt];
	int fl = 1, k = 0;

	for (int i = 0; i < num_cnt; i++)
	{
		result[i] = num[i];
	}

#if 0
	int start = 0;
	for (int i = 0; i < num_cnt - 1; i++)
	{
		if (result[i] == result[i + 1])
			start = i;
		else
			break;
	}
#else
	int start = 0;
#endif
	for (int i = start; i <= (start + num_cnt / 2); i++)
	{

		if (fl == 0 || ((i & 1) != 0 && fl != 0))
		{
			int n = result[i];
			memmove(&result[i], &result[i + 1], (num_cnt - i - 1) * sizeof(int));
			//show_arr(result, num_cnt);
			int add_idx = num_cnt - 1 - k;
			memmove(&result[add_idx + 1], &result[add_idx],
					(num_cnt - add_idx- 1) * sizeof(int));
			//show_arr(result, num_cnt);
			result[add_idx] = n;
			k++;
			fl = 0;
		}
	}

#if 0
	int max = get_max(result, num_cnt);
	int cnt = num_cnt;
	while (cnt--)
	{
		if (result[1] == result[num_cnt - 1] &&
				is_target_max(result, num_cnt - 1, max) == 0)
		{
			memmove(&result[2], &result[1], (num_cnt - 2) * sizeof(int));
			continue;
		}
		break;
	}
#endif

	int *ret = (int *)malloc(num_cnt * sizeof(int));
	for (int i = 0; i < num_cnt; i++)
	{
		ret[i] = result[i];
	}
	return ret;
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
			}
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

static int permutation_search(int *arr, int arr_size, int depth, int *result, int target_max)
{
	if (arr_size == depth)
	{
		if (is_target_max(arr, arr_size, target_max) < 0)
			return -1;

		for (int i = 0; i < arr_size; i++)
		{
			result[i] = arr[i];
		}
		return 0;
	}

	int next_depth = depth + 1;
	for (int i = depth; i < arr_size; i++)
	{
		int temp = arr[i];
		arr[i] = arr[depth];
		arr[depth] = temp;

		if (permutation_search(arr, arr_size, next_depth, result, target_max) == 0)
			return 0;

		temp = arr[i];
		arr[i] = arr[depth];
		arr[depth] = temp;
	}
	return -1;
}

static void permutation_0(int *arr, int arr_size, int *result, int *max)
{
	permutation(arr, arr_size, 2, result, max);
}

int *t2(int *num, int num_cnt)
{
	if (num_cnt == 1)
	{
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

#if 0
	for (int i = 0; i < num_cnt; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
#endif
	int *ret = (int *)malloc(num_cnt * sizeof(int));
	for (int i = 0; i < num_cnt; i++)
	{
		ret[i] = result[i];
	}
	return ret;
}

void t2_target(int *num, int num_cnt, int* result, int target_max)
{

	permutation_search(num, num_cnt, 2, result, target_max);
}

int main(void)
{
#if 1
	int num_cnt;
	scanf("%d", &num_cnt);

	int num[num_cnt];
	for (int i= 0; i < num_cnt; i++)
	{
		scanf("%d", &num[i]);
	}

	int *result = t1(num, num_cnt);

#if 0
	int max = get_max(result, num_cnt);
	t2_target(num, num_cnt, result, max);
#endif
	for (int i = 0; i < num_cnt; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	free(result);
#else

	int test_cnt = 1000000;
	srand(time(NULL));
	while (test_cnt--)
	{
		int num_cnt = (uint32_t)(rand() % 10) + 2;
		int num[num_cnt];
		for (int i = 0; i < num_cnt; i++)
		{
			num[i] = (uint32_t)(rand() % 10);
		}
		int *r1 = t1(num, num_cnt);
		int *r2 = t2(num, num_cnt);

		for (int i = 0; i < num_cnt ;i++)
		{
			if (r1[i] == r2[i])
				continue;
			printf("fail\n");

			printf("test %d : ", num_cnt);
			for (int j = 0; j < num_cnt; j++)
			{
				printf("%d ", num[j]);
			}
			printf("\n");

			printf("t1 : ");
			for (int j = 0; j < num_cnt; j++)
			{
				printf("%d ", r1[j]);
			}
			printf("\n");
			printf("t2 : ");
			for (int j = 0; j < num_cnt; j++)
			{
				printf("%d ", r2[j]);
			}
			printf("\n");
			return 0;
		}
		free(r1);
		free(r2);
	}
#endif
	return 0;
}
