#include <stdio.h>
#include <string.h>

int main (void)
{
	int cnt;
	scanf("%d", &cnt);
	char input[201];
#define PATTERN_10		"10"
#define PATTERN_01		"01"
#define PATTERN_10_LEN 2
#define PATTERN_01_LEN	2

	while (cnt--)
	{
		scanf("%s", input);
		int input_len = strlen(input);
		char *pos = input;
		const char *last = pos + input_len;

		while (1)
		{
			const int remain_len = last - pos;

			if (remain_len >= PATTERN_10_LEN &&
				memcmp(pos, PATTERN_10, PATTERN_10_LEN) == 0)
			{
				pos += PATTERN_10_LEN;

				if (pos == last)
				{
					printf("NO\n");
					break;
				}

				if (*pos == '0')
				{
					do {
						pos++;
						if (pos == last)
							break;
					} while (*pos == '0');

					if (pos == last)
					{
						printf("NO\n");
						break;
					}
				} else
				{
					printf("NO\n");
					break;
				}

				int one_cnt = 0;
				do {
					pos++;
					one_cnt++;
					if (pos == last)
						break;
				} while (*pos == '1');

				if (pos == last)
				{
					printf("YES\n");
					break;
				}
				
				if ((pos + 1) == last)
				{
					printf("NO\n");
					break;
				}

				if (*(pos + 1) == '1')
				{
					pos += 2;
					if (pos == last)
					{
						printf("YES\n");
						break;
					}
					continue;
				}
				if (one_cnt > 1)
					pos--;
			} else if (remain_len >= PATTERN_01_LEN &&
					   memcmp(pos, PATTERN_01, PATTERN_01_LEN) == 0)
			{
				pos += PATTERN_01_LEN;
				if (pos == last)
				{
					printf("YES\n");
					break;
				}
			} else
			{
				printf("NO\n");
				break;
			}
		}

	}
	return 0;
}
