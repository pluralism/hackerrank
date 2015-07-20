#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int findLCS(string s1, string s2)
{
	vector<vector<int> > lcsArray(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	for (unsigned int i = 1; i < s1.size() + 1; i++)
		for (unsigned int j = 1; j < s2.size() + 1; j++)
			if (s1[i - 1] == s2[j - 1])
				lcsArray[i][j] = lcsArray[i - 1][j - 1] + 1;
			else
				lcsArray[i][j] = max(lcsArray[i][j - 1], lcsArray[i - 1][j]);
	return lcsArray[s1.size()][s2.size()];
}


int main(int argc, char *argv[]) {
	string s1, s2;
	cin >> s1 >> s2;
	cout << findLCS(s1, s2) << endl;
	return 0;
}