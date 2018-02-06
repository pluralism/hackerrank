#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<long long int> z_alg(string s)
{
	long long int n = s.length();
	vector<long long int> z(n);

	for (long long int i = 1, left = 0, right = 0; i < n; i++)
	{
		if (i <= right)
			z[i] = min(right - i + 1, z[i - left]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > right)
		{
			left = i;
			right = i + z[i] - 1;
		}
	}
	return z;
}

int main(){
	int T;
	cin >> T;

	while (T--) 
	{
		string s;
		cin >> s;
		long long int sum = s.size();
		vector<long long int> buffer = z_alg(s);
		for (long long int i = 0; i < buffer.size(); i++)
			sum += buffer[i];
		cout << sum << endl;
	}
	return 0;
}