#include <vector>
#include <iostream>
using namespace std;
int main()
{
	vector<int > *arrayElement = new vector<int> [5];
	int k=1;

	arrayElement[4].push_back(k);
		arrayElement[4][0]=2;		//vector模板的operator[]函数不会进行内存扩充！
	cout << arrayElement[4][0];
}
