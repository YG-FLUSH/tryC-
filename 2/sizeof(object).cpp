#include <iostream>

class Obj	//类与结构体的内存分配一致！还有内存对齐的问题
{
	public:
	bool show(){std::cout << i;};
	
	private:
	char z;

	int i;
	char j[2];
};

int main()
{
	Obj *o = new Obj;
	std::cout << sizeof(*o);
	
	void * nul =o;
	
	//std:: cout << sizeof (*nul);	
	return 0;
}