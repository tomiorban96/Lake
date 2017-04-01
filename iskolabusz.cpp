#include <iostream>
#include <cmath>
int main()
{
	int i, N;
	std::cin >> N;
	if (N - 1)
	{
		i = log2(N - 1);
		std::cout << (N - pow(2, i)) * 2;
	}
	else std::cout << 1;
}
