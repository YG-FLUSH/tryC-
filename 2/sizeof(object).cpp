#include <iostream>

class Obj	//����ṹ����ڴ����һ�£������ڴ���������
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