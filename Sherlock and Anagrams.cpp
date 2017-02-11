#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int main(int argc, char **argv)
{
	int T, c;
	string s, tmp;
	map<string, int> m;
	cin >> T;

	while (T--)
	{
		m.clear();
		c = 0;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			m[string(1, s[i])]++;
			for (int j = i - 1; j >= 0; j--)
			{
				tmp = s.substr(j, i - j + 1);
				sort(tmp.begin(), tmp.end());
				m[tmp]++;
			}
		}

		for(auto& k: m) c += (k.second * (k.second - 1)) / 2;
		cout << c << endl;
	}
    return 0;
}

