#include <bits/stdc++.h>

using namespace std;

int numberOfDifferentSquares(int N)
{
	int result = 1;
	for (int i = 2; i <= N; ++i)
		result += i*i;

	return result;
}

int main()
{
	int N;
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)
			break;

		printf("%d\n", numberOfDifferentSquares(N));
	}
}
