#include<iostream>
#include<string>
using namespace std;

#define c 12
int main()
{
	cout << "Hello World" << endl;
	int a = 22;
	const int b = 2;
	cout <<"a:"<<a<<endl ;
	cout << "b:" << b << endl;
	cout << "c:"<<c<<endl;

	short aa = 10;
	int bb = 10;
	long cc = 10;
	long long dd = 10;
	cout << "aa:"<<sizeof(aa)<<endl;
	cout << "bb:" << sizeof(bb) << endl;
	cout << "cc:" << sizeof(cc) << endl;
	cout << "dd:" << sizeof(dd) << endl;

	char str = 'a';
	string str2 = "abcd";
	char str3[] = "abcd";
	cout << str << '\n';
	cout << str2 << '\\';
	cout << str3 << '\n';

	string str_input = "asdf";
	cout << "请为str_input进行赋值：" << endl;
	cin >> str_input;
	cout << "str_input更改为：" << str_input <<'\n';

	system("pause");
	return 0;
}