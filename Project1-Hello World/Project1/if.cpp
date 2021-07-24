#include<iostream>
using namespace std;

int main() {

	float score = 0;
	cout << "请输入分数:" << endl;
	cin >> score;
	if (600 < score) 
		cout << "牛逼！" << endl;
	else if (600 > score > 400)
		cout << "还行" << endl;
	else
		cout<<"该努力了"<<endl;

	int a;
	int b;
	int c;
	cout << "请输入变量a：" << endl;
	cin >> a;
	cout << "请输入变量b：" << endl;
	cin >> b;
	c = a > b ? a : b;
	cout << "c的值为：" << c << endl;

}