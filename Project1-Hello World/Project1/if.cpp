#include<iostream>
using namespace std;

int main() {

	float score = 0;
	cout << "���������:" << endl;
	cin >> score;
	if (600 < score) 
		cout << "ţ�ƣ�" << endl;
	else if (600 > score > 400)
		cout << "����" << endl;
	else
		cout<<"��Ŭ����"<<endl;

	int a;
	int b;
	int c;
	cout << "���������a��" << endl;
	cin >> a;
	cout << "���������b��" << endl;
	cin >> b;
	c = a > b ? a : b;
	cout << "c��ֵΪ��" << c << endl;

}