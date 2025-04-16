#include <iostream>

const int m = 3;
extern "C" int __stdcall FindSaddlePoints(int matrix[][m], int n, int m, int* results);

int main()
{
	int matrix[][m] = { {2, 2 },
						{0, 0},
						{0, 0}
	};

	int n = 2;
	int* results = new int[2*n];//{0, 0, 0, 0, 0, 0};//new int(2 * n);
	int res = 0;
	res = FindSaddlePoints(matrix, n, m, results);
	std::cout << res << "\n";
	for (size_t i = 0; i < res; i++)
	{
		std::cout << results[i] << " ";
	}

	return 0;
}