#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int T;
	scanf("%lld", &T);

	long long int N;
	for (long long int i = 1; i <= T; ++i)
	{
		scanf("%lld", &N);
		long long int sum = 0, x;
		for (long long int j = 1; j <= N; ++j)
		{
			scanf("%lld", &x);
			sum += x;
			sum %= N;
		}

		if (sum == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
