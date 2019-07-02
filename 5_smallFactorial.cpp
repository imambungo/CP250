#include <bits/stdc++.h>

using namespace std;

string factorialResult[101];
bool factorialFound[101];

void fillZero(int selisih, string &theNumber)
{
	for (int i = 1; i <= selisih; ++i)
		theNumber = "0" + theNumber;
}

class BigNumber
{
	public:
		string value = "0";

		void add(string toAdd)
		{
			int maxLength = max(value.length(), toAdd.length());
			if (value.length() < maxLength)
				fillZero(maxLength - value.length(), value);
			else if (toAdd.length() < maxLength)
				fillZero(maxLength - toAdd.length(), toAdd);

			int sumOfChar = 0;
			int i;
			for (i = maxLength-1; i >= 0; --i)
			{
				sumOfChar += stoi(value.substr(i,1)) + stoi(toAdd.substr(i,1));
				value[i] = to_string(sumOfChar%10)[0];
				if (to_string(sumOfChar).length() == 2)
				{
					sumOfChar = stoi(to_string(sumOfChar).substr(0,1));
					if (i == 0)
						value = to_string(sumOfChar) + value;
				} else {
					sumOfChar = 0;
				}
			}
		}

		void multiply(int N)
		{
			string before = value;
			for (int i = 2; i <= N; ++i)
				add(before);
		}

		void print()
		{
			printf("%s\n", value.c_str());
		}
};

void printFactorial(int N)
{
	if (factorialFound[N])
	{
		printf("%s\n", factorialResult[N].c_str());
		return;
	}

	BigNumber result;
	result.value = "1";
	for (int i = 2; i <= N; ++i)
	{
		if (factorialFound[i])
		{
			result.value = factorialResult[i];
		}
		else
		{
			result.multiply(i);
			factorialFound[i] = true;
			factorialResult[i] = result.value;
		}
	}

	result.print();
}

int main()
{
	int T;
	scanf("%d", &T);

	int N;
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d", &N);
		printFactorial(N);
	}
}
