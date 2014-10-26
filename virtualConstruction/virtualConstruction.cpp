#include <iostream>

class abc
{
	public:
	virtual void show()=0;
};
class A_abc:public abc
{
	virtual void show(){std::cout << "A_abc"<<std::endl;};
};
class B_abc:public abc
{
	public:
	B_abc (){
		if(!flag_on_heap) 
		{		throw "No on the heap";}
		flag_on_heap = false;
	};
	virtual void show(){std::cout << "B_abc"<<std::endl;};
	bool free_B(){if(delete this) return true;return false;};

	bool free_B()const{if(delete this) return true;return false;};
	
	void * operator new (size_t size)
	{
			flag_on_heap = true;
			return ::operator new(size);
	};


	protected:
	static bool flag_on_heap ;
	~B_abc(){};
};
bool B_abc::flag_on_heap= false;
int main()
{

	B_abc a;
	return 0;
}