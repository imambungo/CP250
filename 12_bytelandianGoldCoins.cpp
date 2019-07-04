#include <bits/stdc++.h>

using namespace std;

const int memoizationSize = 125000000;// will error if not a const
bool alreadyGetMaxAt[memoizationSize + 1];
int maxAt[memoizationSize + 1];

unsigned long long int maxDollar(int n)
{
	if (n <= memoizationSize && alreadyGetMaxAt[n])
		return maxAt[n];
	else {
		unsigned long long int result = maxDollar(n/2) + maxDollar(n/3)
		                                               + maxDollar(n/4);
		if (n > result)
			result = n;

		if (n <= memoizationSize)
		{
			maxAt[n] = result;
			alreadyGetMaxAt[n] = true;
		}
		return result;
	}
}

int main()
{
	alreadyGetMaxAt[0] = true;

	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%llu\n", maxDollar(n));
	}
}
