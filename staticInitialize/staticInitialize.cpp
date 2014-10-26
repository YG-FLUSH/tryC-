#include<iostream>
using namespace std;
 int c=2;
int a=c;

int fun(int a)
{
   const static int b=a;
	int c=0;
	for(int i=0;i<100;i++,c++);
				  return c;
}
const int d=fun(2);
int main()
{
		 cout <<d;
        return 0;
}
