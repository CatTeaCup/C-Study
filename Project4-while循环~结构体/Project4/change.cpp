#include"change.h"

void change(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << "交换后的数1是：" << num1 << endl;
	cout << "交换后的数2是：" << num2 << endl;
}