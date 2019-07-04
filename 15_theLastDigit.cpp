#include <bits/stdc++.h>

using namespace std;

int lastDigit(int a, int b)
{
	if (b == 0) // a and b both are not zero, but separatedly can be zero
		return 1;
	if (a == 0)
		return 0;

	a %= 10;
	b %= 4;

	if (a == 0)
		a = 10;

	if (b == 0)
		b = 4;

	return (int)pow(a, b) % 10;
}

int main()
{
	int t, a, b;
	scanf("%d", &t);

	for (int i = 1; i <= t; ++i)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", lastDigit(a, b));
	}

	/*
	int pangkat = 30;
	int base = 20;

	for (int b = 1; b <= pangkat; ++b) {
		for (int a = 1; a <= base; ++a)
			printf("%d\t", lastDigit(a, b));
		printf("^%d\n", b);
	}
	*/
}
