#include<iostream>
using namespace std;

int main() {

	int a;
	cout << "�������Ӱ������\n" << endl;
	cin >> a;
	cout << "����ķ���Ϊ��\n" << a << endl;
	switch (a) {
	case 10:
		cout << "����Ϊ�Ǿ����Ӱ" << endl;
		break;
	case 9:
		cout << "����Ϊ�Ǻõ�Ӱ" << endl;
		break;
	case 8:
		cout << "����Ϊ�����Ӱ����" << endl;
		break;
	default:
		cout << "����Ϊ�����Ӱ����Ƭ" << endl;
		break;
	}

	int i = 0;
	while (i < 10) {
		cout << "���0-9��"<< i <<endl;
		i++;
	}

}