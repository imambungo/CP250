#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a1, a2, a3;
	scanf("%d%d%d", &a1, &a2, &a3);
	while (a1 || a2 || a3)
	{
		if (a3-a2 == a2-a1) {
			int diff = a2 - a1;
			printf("AP %d\n", a3+diff);
		} else {
			int ratio = a2 / a1;
			printf("GP %d\n", a3*ratio);
		}
		scanf("%d%d%d", &a1, &a2, &a3);
	}
}
