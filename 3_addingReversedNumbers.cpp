// NOTE: don't submit using g++ 4.3.2 as it will give compile error,
// gcc 6.3 works

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int intOne, intTwo;
	string stringOne, stringTwo;
	for (int i = 1; i <= N; ++i)
	{
		//scanf("%s%s", &stringOne, &stringTwo);// can't use this
		cin >> stringOne >> stringTwo;
		reverse(stringOne.begin(), stringOne.end());
		reverse(stringTwo.begin(), stringTwo.end());
		intOne = stoi(stringOne);
		intTwo = stoi(stringTwo);

		intOne += intTwo; // the sum
		stringOne = to_string(intOne); // for reverse
		reverse(stringOne.begin(), stringOne.end());
		intOne = stoi(stringOne);
		printf("%d\n", intOne);
	}
}
