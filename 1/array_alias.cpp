#include <iostream>
#include <string>
#include <new.h>
		//define
#define ptr 1
#define overnew 0
#define override 0	//运算符重载
#define L_val 0
#define Increament 0
#define tempconst 0

		//if
#if  L_val
 int * fun(int &b)
{
	return &b;
}
#endif
#if override
class X;
class Y{

	friend std:: ostream & operator <<(Y &y,std::ostream &os) ;	
	//friend void fun(X &x,Y &y){std::cout <<"This is fun "<<x.x<<" " <<y.y;};//非运算符重载的友元，前置声明了X类型还不能让x.x被知道
public:
	Y(int x){y=x;};
	int get(){return y;}
private:
	int y;
};
class X{		//运算符重载	——友元函数
	private:
	int x;
	public:
	X(int m){x=m;};
	X(X &y){x=y.get();};
	~X(){};
	int get(){return x;};
	void set(int y){x=y;};
	friend std::ostream & operator << (X &x1,std::ostream &os, X &x2){os<<"friend 1os: "<<x1.x << x2.x;return os;  };		//友元函数，不是类的成员函数
	 friend std::ostream & operator << (std::ostream &os,X &x1){os<<"friend 2os: "<<x1.x;return os;  }
	//std::ostream & operator << (Y &x1,std::ostream &os){os<<"friendYos"<<x1.get();return os;  };		//重载<<的一些尝试
	//std:: ostream & operator <<(std::ostream &os){os<<"no friend"<<x;return os;};
	//std:: ostream & operator <<(Y &y,std::ostream &os){os<<"no friend"<<y.y;return os;};	//友元成员函数访问友元私有数据	erro
	
	//friend void fun(X &x,Y &y);//非运算符重载的友元
};

X f1(X x){X y(x);return y;}
void g1(X &x){
	x.set(2);
		//std::cout << x<<std::endl;	
		//x.operator <<(std::cout);
		//std::cout<<std::endl;
		//x << std::cout;
		
}

#endif

#if Increament	//前缀++类的实现	++i; 后缀++   i++；
class X{		//运算符重载	——友元函数
	private:
	int x;
	public:
	X(int m){x=m;};
	X(X &y){x=y.get();};
	~X(){};
	int get(){return x;};
	void set(int y){x=y;};
	friend std:: ostream & operator <<(std::ostream &os,X &x){os<<"no friend "<<x.x;return os;};	//友元成员函数访问友元私有数据
	
	X & operator ++(){	++x; return *this;};		//前缀实现
	X  operator ++(int m){ X x1 = *this; x++; std::cout << "m:"<<m;return x1;};	//考虑这个m
};
#endif
#if overnew
class N
{
	public:
	N(int j):i(j){std::cout<<"This is N's constructor   "<<i<<std::endl;};
	~N(){std::cout<<"This is N's destructor"<<std::endl;};
	static void* operator new ( size_t size,new_handler p);		//第一个形参必须是size
	private:
	int i;
};
void* N::operator new( size_t size, new_handler p)	//重载new操作符，实现多个参数的重载
{
	std::cout<<"this is new operator"<<std::endl;
	p();
	return ::operator new(size);
}
 void no_more_memory()
 {
	std::cout << "There is no more memory"<<std::endl;
	//abort();
	//_exit(-1);
 }
 #endif

 #if tempconst	//临时的变量并非产生const 型的对象！！	这是早期的C++编译器！！！
 class Tempconst
 {
	public:
	Tempconst(int  &i):j(i){};
	Tempconst& operator= (std::string &i){i[0]='a';std::cout << i<<std::endl;return *this;};
	
	~Tempconst(){};
	private:
	int j;
 }; 	
 #endif 

#if ptr//类的指针 失效 析构与否？ 指针不会有影响，因为对于对象的实体并没有被destruct
class Ptr
{
public:
	
	~Ptr(){std::cout<< "This is ptr destruction";};
	template<typename T>
	operator T(){return i; };
private:
	int i;
};
#endif
 int main()
{
#if ptr
	Ptr *p = new Ptr;
	//Ptr p;
	delete p;
	Ptr pj;
	char pk = pj;
#endif 
{
 #if tempconst
	int i=1;
	Tempconst temp(i) ;
	temp = std::string("Hello world");		//临时的变量并非产生const 型的对象！！	这是早期的C++编译器！！！
 #endif 

#if overnew
	//set_new_handler(no_more_memory);
	//while(1)
	{
		N *n = new (no_more_memory)N(2) ;// new N;//= (N *)malloc(sizeof(N));		//new的可重载形式在哪里定义的？
	//n->N::N();
	//n->~N();

	}
//	delete[] n; 	
#endif
#if Increament	
	X x(1);
	std::cout <<"x: "<< x <<std::endl;
	X y=x++;
	std::cout << "X:++ " <<x<<std::endl;
	std::cout <<"Y: "<<y<<std::endl;
	X z=++y;
	std::cout << "Z: "<<z<<std::endl;
	x=X(1);
	std::cout << x << x++ << ++x<<std::endl;		//不同的编译器处理的方式不太一样，不要纠结这个！一条语句一个变量被赋值两次！
#endif
#if 0	//引用数组是非法的
	int a[4]={1,2,3,4};
	int &b[2] = {a[1],a[2]};		//引用数组是非法的
	for(int i =0;i<sizeof(a)/sizeof(int);i++)
	{
		std::cout<< a[i]<<std::endl;
	}
	std::cout<< "b " <<b;
#endif 

#if 0	//const

	 int a=1;
	 const int &b = a;
	 b=2;
	std::cout << b;
#endif	

#if L_val	//左值
	int c=2;
	int a =1;
	const int *b = fun(a);
	*fun(a)=c;		//*将&a变成左值	&a是右值
	std::cout << a;
#endif
#if 0	//a++ 后缀表达，效率较低，operator++(int)，内部保存并返回原始自加前的值		--2014/08/15
		//L-value中的L指的是Location，表示可寻址。The "l" in lvalue can be though of as location
		//R-value中的R指的是Read，表示可读。The "r" in rvalue can be thought of as "read" value.
	int a[2]={1,2};
	int d[2]={3,4};
	int *b=a;
	int *c=d;
	*c++=*b++;		//左值问题,c++=b++ 是错误的，但是*解除引用之后就成为了左值，所以正确？
	std::cout << *--c;
#endif	

#if override	//运算符重载
	X x(1);
	//g1(X(1));
	//Y y=Y(1);
	//x.operator<<(y,std::cout);	//重载<<的一些尝试
	std::cout<<x;
	x<<std::cout;
	//x<<(y,std::cout);
	//fun(x,y);
#endif
}
	return 0;
}