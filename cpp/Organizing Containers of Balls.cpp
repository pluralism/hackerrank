#include <iostream>
#include <vector>
#include <algorithm>

std::string organizingContainers(std::vector<std::vector<int>> container)
{
	const unsigned int container_size = container.size();
	std::vector<int> balls_by_container(container_size);
	std::vector<int> balls_count(container_size);

	for (size_t i = 0; i < container_size; i++)
	{
		for (size_t j = 0; j < container_size; j++)
		{
			balls_by_container[i] += container[i][j];
			balls_count[j] += container[i][j];
		}
	}

	std::sort(balls_by_container.begin(), balls_by_container.end());
	std::sort(balls_count.begin(), balls_count.end());

	for (size_t i = 0; i < container_size; i++)
	{
		if (balls_by_container[i] ^ balls_count[i])
		{
			return "Impossible";
		}
	}

	return "Possible";
}
