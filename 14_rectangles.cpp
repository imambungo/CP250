#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, count = 0;
	scanf("%d", &N);
	for (int i = 1; i*i <= N; ++i)
	{
		++count;
		count += (N - i*i) / i;
	}
	printf("%d\n", count);
}
