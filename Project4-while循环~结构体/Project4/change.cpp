#include"change.h"

void change(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << "���������1�ǣ�" << num1 << endl;
	cout << "���������2�ǣ�" << num2 << endl;
}