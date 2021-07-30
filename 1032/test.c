#include <stdio.h>
#include <string.h>

int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	char file_name[51];
	int len;
	char result_file_name[51];

	scanf("%s", file_name);
	len = strlen(file_name);
	memcpy(result_file_name, file_name, len);
	result_file_name[len] = '\0';
	cnt--;
	while (cnt--)
	{
		scanf("%s", file_name);

		int i;
		for (i = 0; i < len; i++)
		{
			if (result_file_name[i] == '?')
				continue;
			if (result_file_name[i] != file_name[i])
				result_file_name[i] = '?';
		}
	}

	printf("%s\n", result_file_name);
	return 0;
}
