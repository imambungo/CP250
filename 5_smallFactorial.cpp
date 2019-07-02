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
			//cout << "\t\tadd(\"" << toAdd << "\")" << endl;
			//cout << "\t\tvalue + toAdd = " << value << " + " << toAdd << endl;
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
				//cout << value[i] << " " << toAdd[i] << endl;
				//value[i] = to_string(sumOfChar)[0];
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
			//cout << "\tmultiply(" << N << ")\n";
			string before = value;
			for (int i = 2; i <= N; ++i)
			{
				//cout << "\tvalue = " << value << endl;
				add(before);
			}

			//cout << "\tvalue = " << value << endl;
		}

		void print()
		{
			printf("%s\n", value.c_str());
		}
};

void printFactorial(int N)
{
	//cout << "Print faktorial " << N << endl;
	BigNumber result;
	result.value = "1";
	for (int i = 2; i <= N; ++i)
	{
		//cout << "result.print() -> ";
		//result.print();
		result.multiply(i);
	}

	//cout << "result.print() -> ";
	result.print();
}

int main()
{
	//ifstream readFromFile("data.in");

	int T;
	scanf("%d", &T);
	//readFromFile >> T;

	int N;
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d", &N);
		//readFromFile >> N;
		printFactorial(N);
	}
}
