#include <iostream>
int abs(int x)
{
	return ~x+1;
}

int main()
{
	typedef int a[4];
	a b={-2,1,3,4};
	int c = abs(b[0]);
	std::cout << c;
}
