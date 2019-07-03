#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	while (true)
	{
		scanf("%d", &N);
		if (N == -1)
			break;

		int packets[N], totalCandy = 0;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &packets[i]);	
			totalCandy += packets[i];
		}

		if (totalCandy/N*N != totalCandy) {
			printf("-1\n");
		} else {
			int step = 0, candyOnEachPacket = totalCandy/N;
			for (int i = 0; i < N; ++i)
				if (candyOnEachPacket > packets[i])
					step += (candyOnEachPacket - packets[i]);

			printf("%d\n", step);
		}
	}
}

