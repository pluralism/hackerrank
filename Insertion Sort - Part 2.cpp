#include <iostream>
#include <vector>
using namespace std;


void insertionSort(vector<int> vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int j = i - 1;
		int tmp = vec[i];
		while (j >= 0 && vec[j] > tmp)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = tmp;

		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
		cout << endl;
	}
}


int main(int argc, char *argv[]) 
{
	int V, tmp;
	vector<int> vec;

	cin >> V;
	for (int i = 0; i < V; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	insertionSort(vec);
	return 0;
}