#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class blankrm
{
public:

	bool operator() (char c)
	{
		if(c==' ')
		return true;
		else return false;
	}
};

int main()
{

	//去掉字符串头尾空格
	string s("a");
	int i = s.find_first_not_of(' ');
	int j = s.find_last_not_of(' ');
	cout << i<<","<<j<<endl;
	return 0;
}