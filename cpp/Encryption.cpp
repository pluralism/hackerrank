#include <string>
#include <cmath>
#include <algorithm>

std::string encryption(std::string s)
{
	std::string striped;
	std::copy_if(s.begin(), s.end(), std::back_inserter(striped), [](auto ch) { return ch != 32; });

	const auto len_sqrt = std::sqrt(striped.length());
	const auto rows = std::round(len_sqrt);
	const auto columns = rows >= len_sqrt ? rows : std::ceil(len_sqrt);

	std::string result = "";

	for (size_t i = 0; i < columns; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			const auto index = i + j * columns;
			if (index < striped.length())
			{
				result += striped[index];
			}
			else 
			{
				break;
			}
		}
		result += ' ';
	}

	return result;
}
