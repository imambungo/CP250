#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, N;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		scanf("%d", &N);
		int menHotness[N], hotness;
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &hotness);
			menHotness[j] = hotness;
		}

		int womenHotness[N];
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &hotness);
			womenHotness[j] = hotness;
		}

		sort(  menHotness,   menHotness+N, greater<int>());
		sort(womenHotness, womenHotness+N, greater<int>());

		int totalHotness = 0;
		for (int j = 0; j < N; ++j)
			totalHotness += menHotness[j]*womenHotness[j];

		printf("%d\n", totalHotness);
	}
}
