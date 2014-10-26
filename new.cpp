#include <iostream>

class a{
public:
virtual ~a(){
};
private:
void operator delete(void *p)
{
	std::cout << "~A";
}
};

int main()
{
a _1;
}