#include <iostream>
#include <string>

int main()
{
	std::string s1 = "Hello";
	char *p = &s1[1];
	std::string s2 = s1;
	*p = 'A';
	std::cout << "s1 " <<s1<<std::endl
				<<"s2 " <<s2 <<std::endl;	
}