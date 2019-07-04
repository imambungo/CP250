#include <bits/stdc++.h>

using namespace std;

int main()
{
	int column;
	while (true)
	{
		scanf("%d", &column);
		if (!column)
			break;

		string encrypted;
		cin >> encrypted;
		
		string decrypted;

		int stepA, stepB,
			totalStep = 2*column;
		for (int i = 0; i < column; ++i)
		{
			stepA = totalStep - (i*2+1);
			stepB = totalStep - stepA;
			int j = i;
			while (j < encrypted.length())
			{
				if (j < encrypted.length()) {
					decrypted += encrypted[j];
					j += stepA;
				}
				if (j < encrypted.length()) {
					decrypted += encrypted[j];
					j += stepB;
				}
			}
		}

		printf("%s\n", decrypted.c_str());
	}
}
