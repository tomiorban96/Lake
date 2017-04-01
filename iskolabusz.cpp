#include <iostream>
#include <cmath>
int main()
{
	int N; std::cin >> N;
	if (N - 1) std::cout << (N - pow(2, trunc(log2(N - 1)))) * 2;
	else std::cout << 1;
}