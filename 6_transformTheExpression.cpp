#include <bits/stdc++.h>

using namespace std;

bool aLetter(char theChar)
{
	if (theChar >= 97 && theChar <= 122)
		return true;

	return false;
}

string reversePolishNotation(string expression)
{
	string newExpression = "", operators = "";
	for (int i = 0; i < expression.length(); ++i)
	{
		if (aLetter(expression[i]))
			newExpression += expression[i];
		else if (expression[i] == '(')
			continue;
		else if (expression[i] == ')') {
			newExpression += operators[operators.length()-1];
			operators.pop_back();
		} else {
			operators += expression[i];
		}
	}
	return newExpression;
}

int main()
{
	ifstream readFromFile("data.in");

	int t;
	scanf("%d", &t);

	string expression;
	for (int i = 1; i <= t; ++i)
	{
		cin >> expression;
		printf("%s\n", reversePolishNotation(expression).c_str());
	}
}

