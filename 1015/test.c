#include <stdio.h>

struct info
{
	int value;
	int a_idx;
	int p_idx;
};

static int my_qsort_partition(struct info *data, int left, int right)
{
	struct info *pivot = &data[right];
	int i = left - 1;

	for (int j = left; j < right; j++)
	{
		struct info *in = &data[j];

		if (in->value != pivot->value)
		{
			if (in->value < pivot->value)
			{
				i++;

				struct info temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
			continue;
		}

		if (in->a_idx < pivot->a_idx)
		{
			i++;

			struct info temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	int pivot_pos = i + 1;
	struct info temp = data[pivot_pos];
	data[pivot_pos] = data[right];
	data[right] = temp;

	return pivot_pos;
}

static void my_qsort(struct info *data, int left, int right)
{
	if (left >= right)
		return;
	int pivot_new_idx = my_qsort_partition(data, left, right);
	my_qsort(data, left, pivot_new_idx - 1);
	my_qsort(data, pivot_new_idx + 1, right);
}

int main(void)
{
	int cnt;

	scanf("%d", &cnt);

	if (cnt == 0)
	{
		printf("0\n");
		return 0;
	}

	struct info arr[cnt];

	for (int i = 0; i < cnt; i ++)
	{
		struct info *in = &arr[i];
		scanf("%d", &in->value);;
		in->a_idx = i;
	}

	my_qsort(arr, 0, cnt - 1);

	for (int i = 0; i < cnt; i ++)
	{
		arr[i].p_idx = i;
	}

	int result[cnt];

	for (int i = 0; i < cnt; i++)
	{
		result[arr[i].a_idx] = arr[i].p_idx;
	}

	for (int i = 0; i < cnt; i ++)
	{
		printf("%d ", result[i]);
	}

	printf("\n");

	return 0;
}
