#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <unordered_set>

std::vector<std::string> split_string(std::string input_string) {
	std::string::iterator new_end = std::unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	std::vector<std::string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != std::string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, std::min(pos, input_string.length()) - i + 1));

	return splits;
}

std::vector<int> bfs(int n, int m, std::unordered_map<int, std::unordered_set<int>> edges, int s)
{
	std::vector<int> result(n, -1);
	result[s - 1] = 0;

	std::unordered_set<int> visited{ s };
	std::queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		const auto it = edges.find(temp);
		if (it != edges.end())
		{
			for (const int& e : it->second)
			{
				if (visited.find(e) == visited.end())
				{
					result[e - 1] = result[temp - 1] + 6;
					visited.insert(e);
					q.push(e);
				}
			}
		}
	}

	return result;
}

int main()
{
	std::ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	std::cin >> q;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (size_t i = 0; i < q; i++)
	{
		std::string temp;
		std::getline(std::cin, temp);

		std::vector<std::string> nm = split_string(temp);

		int n = stoi(nm[0]);
		int m = stoi(nm[1]);

		std::unordered_map<int, std::unordered_set<int>> edges_map{};

		for (size_t j = 0; j < m; j++)
		{
			int u, v;
			std::cin >> u >> v;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			edges_map.insert(std::make_pair(u, std::unordered_set<int>{}));
			edges_map.insert(std::make_pair(v, std::unordered_set<int>{}));

			edges_map[u].insert(v);
			edges_map[v].insert(u);
		}

		int s;
		std::cin >> s;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::vector<int> result = bfs(n, m, edges_map, s);

		for (size_t j = 0; j < result.size(); j++)
		{
			if (j != s - 1)
			{
				fout << result[j];

				if (j != result.size() - 1)
				{
					fout << " ";
				}
			}
		}

		fout << '\n';
	}

	fout.close();
	return 0;
}
