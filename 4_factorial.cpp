#include <bits/stdc++.h>

using namespace std;

int trailingZerosOfFactorial(int N)
{
	int totalLeadingZero = 0;
	for (int i = 5; i <= N; i *= 5)
		totalLeadingZero += N/i;

	return totalLeadingZero;
}

int main()
{
	int T;
	scanf("%d", &T);

	int N;
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d", &N);
		printf("%d\n", trailingZerosOfFactorial(N));
	}
}
