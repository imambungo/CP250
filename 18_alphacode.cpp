#include <bits/stdc++.h>

using namespace std;

// max of long long int: 9223372036854775807
const int memoizationSize = 91;// https://www.dcode.fr/fibonacci-numbers
bool alreadyCalculated[memoizationSize + 1];
long long int fibonacciResult[memoizationSize + 1];

/*
pattern of possibilities of chained decoding (or whatever you call it)
1 = 1
2 = 2    ex: 25
3 = 3    ex: 114
4 = 5
5 = 8
6 = 13
7 = 21
8 = 34
9 = 55
10 = 89  ex: 1111111111
*/

long long int fibonacci(int n)
{
	if (alreadyCalculated[n])
		return fibonacciResult[n];
	else {
		fibonacciResult[n] = fibonacci(n-1) + fibonacci(n-2);
		alreadyCalculated[n] = true;
		return fibonacciResult[n];
	}
}

bool behindZero(string input, int i)
{
	if (i < input.length()-1 && input[i+1] == '0')
		return true;

	return false;
}

bool theLastOfChain(string input, int i)
{
	if (input[i] == '0') // the char before '0' must be the last of a chain
		return false;

	if (i == input.length()-1) // if the last char
		return true;

	if (input[i+1] == '0') // if the next char is '0'
		return true;

	// if input[i] is 5 and input[i+1] is 8
	// then 58 can't be decoded into an alphabet
	if ((input[i]-48)*10 + (input[i+1]-48) > 26)//'0' is the 48th char of ASCII
		return true;

	return false;
}

int main()
{
	fibonacciResult[0] = 1;// fibonacci seeds
	fibonacciResult[1] = 1;
	alreadyCalculated[0] = true;
	alreadyCalculated[1] = true;

	while (true)
	{
		string input;
		cin >> input;

		if (input == "0") // input terminator
			break;

		long long int possibleDecoding = 1;
		int           chainLength      = 0;
		for (int i = 0; i < input.length(); ++i)
		{
			if (input[i] != '0')
				++chainLength;

			if (theLastOfChain(input, i)) // if the last of chain
			{
				if (behindZero(input, i) && chainLength > 1)
					--chainLength;

				possibleDecoding *= fibonacci(chainLength);
				chainLength = 0;
			}
		}

		printf("%lld\n", possibleDecoding);
	}
}
