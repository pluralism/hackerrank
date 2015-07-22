#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
	int V, N, tmp;
	vector<int> vec;
	vector<int>::iterator it;

	cin >> V >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}

	it = find(vec.begin(), vec.end(), V);
	if (it != vec.end())
		cout << distance(vec.begin(), it) << endl;

	return 0;
}