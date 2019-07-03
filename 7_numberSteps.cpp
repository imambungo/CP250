#include <bits/stdc++.h>

using namespace std;

int whatNumberAtPoint(int x, int y)
{
	if (x%2 == 0)
		return x + y;
	else
		return x + y - 1;
}

int main()
{
	int N;
	scanf("%d", &N);

	int x, y;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d%d", &x, &y);
		if (x == y || y == x-2)
			printf("%d\n", whatNumberAtPoint(x, y));
		else
			printf("No Number\n");
	}
}
