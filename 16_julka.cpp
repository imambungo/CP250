/*
 * K + N = 10
 * K - N = 2
 */
#include <bits/stdc++.h>

using namespace std;

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

		void sub(string toSub)// only if toSub < value and both are positive
		{
			int maxLength = max(value.length(), toSub.length());
			if (value.length() < maxLength)
				fillZero(maxLength - value.length(), value);
			else if (toSub.length() < maxLength)
				fillZero(maxLength - toSub.length(), toSub);

			int pos;
			for (int i = maxLength-1; i >= 0; --i)
			{
				if (value[i] == 47)
				{
					value[i] = '9';
					--value[i-1];
				}

				if (value[i] > toSub[i])
					value[i] -= ((int)toSub[i] - 48);
				else if (value[i] == toSub[i])
					value[i] = '0';
				else
				{
					value[i] += 58 - toSub[i];
					--value[i-1];
				}

				if (value[i] != '0')
					pos = i;
			}
			value = value.substr(pos);
		}

		void div(int divisor)
		{
			int divident = 0;
			string result = "";
			for (int i = 0; i < value.length(); ++i)
			{
				divident *= 10;
				divident += value[i]-48;
				if (divident/divisor >= 1)
				{
					result += to_string(divident/divisor);
					divident %= divisor;
				}
				else
					if (result.length() != 0)
						result += "0";
			}
			value = result;
		}

		void print()
		{
			printf("%s\n", value.c_str());
		}
};


int main()
{
	BigNumber klaudia, natalia;
	string KplusN, KminN;
	for (int i = 1; i <= 10; ++i)
	{
		cin >> KplusN >> KminN;

		klaudia.value = KplusN;
		natalia.value = KplusN;

		klaudia.add(KminN);
		klaudia.div(2);

		natalia.sub(klaudia.value);

		klaudia.print();
		natalia.print();
	}
}
