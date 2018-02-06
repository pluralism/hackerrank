#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
	cout << endl;
}


void insertionSort(vector<int> vec)
{
	int V = vec[vec.size() - 1];
	bool done = false;
	for (int i = vec.size() - 2; i >= 0; i--)
	{
		if (vec[i] > V)
		{
			vec[i + 1] = vec[i];
			printVector(vec);
		}
		else 
		{
			vec[i + 1] = V;
			done = true;
			break;
		}
	}

	if (!done)
		vec[0] = V;
	printVector(vec);
}


int main(int argc, char *argv[]) {
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