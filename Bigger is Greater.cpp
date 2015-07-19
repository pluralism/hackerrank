#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string evaluate(string s)
{
	bool valid = false;
	for (int i = s.size() - 1; i > 0; i--)
		if (s[i] > s[i - 1])
		{
			next_permutation(s.begin(), s.end());
			return s;
		}
	return "no answer";
}


int main(int argc, char *argv[])
{
	int T;

	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		cout << evaluate(s) << endl;
	}
	return 0;
}