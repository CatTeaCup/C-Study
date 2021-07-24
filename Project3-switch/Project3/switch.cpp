#include<iostream>
using namespace std;

int main() {

	int a;
	cout << "请输入电影分数：\n" << endl;
	cin >> a;
	cout << "您打的分数为：\n" << a << endl;
	switch (a) {
	case 10:
		cout << "您认为是经典电影" << endl;
		break;
	case 9:
		cout << "您认为是好电影" << endl;
		break;
	case 8:
		cout << "您认为这个电影不错" << endl;
		break;
	default:
		cout << "您认为这个电影是烂片" << endl;
		break;
	}

	int i = 0;
	while (i < 10) {
		cout << "输出0-9："<< i <<endl;
		i++;
	}

}