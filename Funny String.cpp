#include <iostream>
#include <string>
using namespace std;


string reverseString(string s)
{
	string res = "";
	for (int i = s.size() - 1; i >= 0; i--)
		res += s[i];
	return res;
}


int checkString(string s)
{
	string reversed = reverseString(s);
	for (int i = 1; i < s.size(); i++)
		if (abs(s[i] - s[i - 1]) != abs(reversed[i] - reversed[i - 1]))
			return 0;
	return 1;
}


int main(int argc, char *argv[])
{
	int T;

	cin >> T;
	while (T--)
	{
		string original;
		cin >> original;

		if (checkString(original))
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
	}
	return 0;
}