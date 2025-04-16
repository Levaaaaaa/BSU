#include "Fun.h"

std::vector<std::vector<int>> init(int row, int column)
{
	std::vector<std::vector<int>> result(row);
	for (size_t i = 0; i < row; i++)
	{
		std::vector<std::vector<int>> r(column);
		result = r;
		for (size_t j = 0; j < column; j++)
		{
			result[i][j] = rand() % (15+10) - 10;
		}
	}

	return result;
}