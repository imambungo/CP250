#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number)
{
	if (number <= 1)
		return false;

	for (int i = 2; i*i <= number; ++i)
		if (number%i == 0)
			return false;

	return true;
}

int main()
{
	int t;
	scanf("%d", &t);

	int m, n;
	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d", &m, &n);
		while (m <= n)
		{
			if (isPrime(m))
				printf("%d\n", m);

			++m;
		}

		printf("\n");
	}
}
