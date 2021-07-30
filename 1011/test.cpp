#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <iostream>
#include <stack>

using namespace std;

struct type{
	int pos;
	int move;
	int cnt;
};

static int move_dfs(uint32_t pos, uint32_t move, uint32_t dest)
{
	int next_move[3];

	struct type *t = (struct type *)malloc(sizeof(struct type));

	t->pos = pos;
	t->move = move;
	t->cnt = 0;

	stack<struct type *> s;

	s.push(t);
	int min_cnt = INT_MAX;

	while (s.empty() == false)
	{
		struct type *member = s.top();
		s.pop();

		next_move[0] = member->move - 1;
		next_move[1] = member->move;
		next_move[2] = member->move + 1;
		member->cnt++;

		for (uint32_t i = 0; i < (sizeof(next_move) / sizeof(next_move[0])); i++)
		{
			int next = next_move[i];
			if (next <= 0)
				continue;

			uint32_t next_dest = member->pos + next;

			if (next_dest > dest)
				continue;

			if (next_dest == dest)
			{
				if (next == 1) {
					if (min_cnt > member->cnt)
						min_cnt = member->cnt;
				}
				continue;
			}

			struct type *next_member = (struct type *)malloc(sizeof(struct tpye *));
			next_member->pos = next_dest;
			next_member->move = next;
			next_member->cnt = member->cnt;
			s.push(next_member);
		}

		free(member);
	}

	return min_cnt;
}

int main (void)
{
	int cnt;
	scanf("%d", &cnt);

	while (cnt--)
	{
		uint32_t x, y;
		scanf("%u %u", &x, &y);

		printf("%d\n", move_dfs(x, 0, y));
	}

	return 0;
}
