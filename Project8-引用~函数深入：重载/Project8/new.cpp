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

 int& test04() //为引用类型的函数
 {
	 static int a = 20;  //静态变量，存在全局区里
	 return a;  //引用类型函数返回值为值类型
 }

 void test05(const int & a) 
 {
	 //a = 1000;//在函数定义时中加入const，使得引用变为一个常量，所以不能在函数中改变引用的值，在开发时有用，使得实验函数时不能修改主函数中的值
	 cout << a << endl;
 }

int main() 
{
	/*test01();
	test02();*/

	//引用
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;

	b = 100;
	cout << a << endl;
	cout << b << endl;

	//引用的注意事项 1 .引用必须初始化 2 .一旦引用后就不能更改了

	//引用做函数参数
	//int a = 10;
	//int b = 20;
	////myswap01(a, b); //值传递
	////myswap02(&a, &b);  //指针传递
	//myswap03(a, b);  //引用传递
	//cout << a << endl;
	//cout << b << endl;

	//引用做函数返回值
	//int& ref = test04();  //应用引用来接收
	//cout << "ref=" << ref << endl;
	//test04() = 1000;  //引用函数可作为左值进行传递
	//cout << "ref=" << ref << endl;
	//就记住，引用定义时一定带&，传参一定是a、b这种，没有&。指针定义是*，传参是a这种（a为指针）或者&b这种（b为变量）

	////引用的本质就是一个指针常量。指针常量，顾名思义，指针的常量，所以指针指向不能更改；或者指针（no）常量（yes），指向不能改值可以改
	////常量指针同理，常量的指针，所以指针指向的值不能更改；或者常量（no）指针（yes），值不能更改指向可以更改

	////常量引用
	////int& ref = 10;//不合法，引用必须引一块内存空间
	//const int& a = 10; //合法，const帮助建立一个内存空间，相当于一个常指针常量
	//test05(a);

	//函数深入：默认值
	//函数设定默认值后，从该默认值向右的数都需默认值
	//函数声明有默认值，那么函数实现就不能有默认值了

	//函数深入：占位值
	//声明函数或者定义函数时，只定义变量类型不定义变量就是占位参数int func（int a，int）
	//占位参数也可以有默认值，int = 10即可

	//函数深入：函数重载
	//1.作用域相同 2.函数名相同 3.函数参数类型不同、或个数不同、或者顺序不同

	//函数深入：1.函数重载+引用  2.函数重载+默认值
	//1.
	//int a = 10;
	//void func(int& a);
	//void func(const int& a);
	//func(a);  //相当于int &a = a
	//func(10);  //相当于const int &a = 10，所以调用const int&那个函数而不能调用int&。因为引用不能直接赋值，而需指向一段内存：不能int &a = 10，但const可以
	//2.
	//（当定义的两个函数，一个一个变量，一个两个变量第二个为默认参数）
	//void func_m(int a); //不能正常重载
	//void func_m(int a, int b);  //可以正常重载
	//（当定义的两个函数，一个一个变量，一个两个变量第二个为默认参数）
	//void func_m(int a);  //不能正常重载
	//void func_m(int a, int b = 10);  //传入两个值可以重载，传入一个值不能重载，一个值会和上面的二义性



	system("pause");
	return 0;
}

void func(int& a) 
{
	cout << "void func(int& a)调用" << endl;
}
void func(const int& a)
{
	cout << "void func(const int& a)调用" << endl;
}