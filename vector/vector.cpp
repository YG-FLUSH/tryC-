#include <vector>
#include <iostream>
using namespace std;
int main()
{
	vector<int > *arrayElement = new vector<int> [5];
	int k=1;

	arrayElement[4].push_back(k);
		arrayElement[4][0]=2;		//vectorģ���operator[]������������ڴ����䣡
	cout << arrayElement[4][0];
}
