#include<iostream>
#include<string>
using namespace std;

int * func() 
{
	int* p = new int(10);
	return p;
}

void test01() 
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	delete p;
	//cout << *p << endl;
}

void test02() 
{
	int * arr = new int[10];
	for (int i = 0; i < 10; i++) 
	{
		arr[i] = 100 + i;
	}
	for (int i = 0; i < 10; i++) 
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
}

 void myswap01(int a,int b) 
 {
	 int temp;
	 temp = a;
	 a = b;
	 b = temp;
 }

 void myswap02(int* a, int* b) 
 {
	 int temp;
	 temp = *a;
	 *a = *b;
	 *b = temp;
 }

 void myswap03(int& a, int& b) 
 {
	 int temp;
	 temp = a;
	 a = b;
	 b = temp;
 }

 int& test04() //Ϊ�������͵ĺ���
 {
	 static int a = 20;  //��̬����������ȫ������
	 return a;  //�������ͺ�������ֵΪֵ����
 }

 void test05(const int & a) 
 {
	 //a = 1000;//�ں�������ʱ�м���const��ʹ�����ñ�Ϊһ�����������Բ����ں����иı����õ�ֵ���ڿ���ʱ���ã�ʹ��ʵ�麯��ʱ�����޸��������е�ֵ
	 cout << a << endl;
 }

int main() 
{
	/*test01();
	test02();*/

	//����
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;

	b = 100;
	cout << a << endl;
	cout << b << endl;

	//���õ�ע������ 1 .���ñ����ʼ�� 2 .һ�����ú�Ͳ��ܸ�����

	//��������������
	//int a = 10;
	//int b = 20;
	////myswap01(a, b); //ֵ����
	////myswap02(&a, &b);  //ָ�봫��
	//myswap03(a, b);  //���ô���
	//cout << a << endl;
	//cout << b << endl;

	//��������������ֵ
	//int& ref = test04();  //Ӧ������������
	//cout << "ref=" << ref << endl;
	//test04() = 1000;  //���ú�������Ϊ��ֵ���д���
	//cout << "ref=" << ref << endl;
	//�ͼ�ס�����ö���ʱһ����&������һ����a��b���֣�û��&��ָ�붨����*��������a���֣�aΪָ�룩����&b���֣�bΪ������

	////���õı��ʾ���һ��ָ�볣����ָ�볣��������˼�壬ָ��ĳ���������ָ��ָ���ܸ��ģ�����ָ�루no��������yes����ָ���ܸ�ֵ���Ը�
	////����ָ��ͬ��������ָ�룬����ָ��ָ���ֵ���ܸ��ģ����߳�����no��ָ�루yes����ֵ���ܸ���ָ����Ը���

	////��������
	////int& ref = 10;//���Ϸ������ñ�����һ���ڴ�ռ�
	//const int& a = 10; //�Ϸ���const��������һ���ڴ�ռ䣬�൱��һ����ָ�볣��
	//test05(a);

	//�������룺Ĭ��ֵ
	//�����趨Ĭ��ֵ�󣬴Ӹ�Ĭ��ֵ���ҵ�������Ĭ��ֵ
	//����������Ĭ��ֵ����ô����ʵ�־Ͳ�����Ĭ��ֵ��

	//�������룺ռλֵ
	//�����������߶��庯��ʱ��ֻ����������Ͳ������������ռλ����int func��int a��int��
	//ռλ����Ҳ������Ĭ��ֵ��int = 10����

	//�������룺��������
	//1.��������ͬ 2.��������ͬ 3.�����������Ͳ�ͬ���������ͬ������˳��ͬ

	//�������룺1.��������+����  2.��������+Ĭ��ֵ
	//1.
	//int a = 10;
	//void func(int& a);
	//void func(const int& a);
	//func(a);  //�൱��int &a = a
	//func(10);  //�൱��const int &a = 10�����Ե���const int&�Ǹ����������ܵ���int&����Ϊ���ò���ֱ�Ӹ�ֵ������ָ��һ���ڴ棺����int &a = 10����const����
	//2.
	//�������������������һ��һ��������һ�����������ڶ���ΪĬ�ϲ�����
	//void func_m(int a); //������������
	//void func_m(int a, int b);  //������������
	//�������������������һ��һ��������һ�����������ڶ���ΪĬ�ϲ�����
	//void func_m(int a);  //������������
	//void func_m(int a, int b = 10);  //��������ֵ�������أ�����һ��ֵ�������أ�һ��ֵ�������Ķ�����



	system("pause");
	return 0;
}

void func(int& a) 
{
	cout << "void func(int& a)����" << endl;
}
void func(const int& a)
{
	cout << "void func(const int& a)����" << endl;
}