#include <iostream>
#include <math.h>
int main()
{
	int i = 0, N;
	std::cin >> N;
	if (N - 1)
	{
		i = log2(N - 1);
		std::cout << (N - pow(2, i)) * 2;
	}
	else std::cout << 1;
}
