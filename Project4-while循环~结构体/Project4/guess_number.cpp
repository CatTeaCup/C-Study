#include<iostream>
using namespace std;
#include"change.h"
#include<string>

int add(int num1, int num2) {
	int num_add = num1 + num2;
	return num_add;
}

struct Student {
	string name;
	int age;
	int score;
}s3;

struct Teacher {
	int id;
	string name;
	int age;
	struct Student stu;
};

int main() {

	//猜随机数，while循环
	//int i = rand() % 100;
	//int i_guess;
	//while (1) {
	//	cout << "请随机输入一个数：" << endl;
	//	cin >> i_guess;
	//	if (i_guess > i) {
	//		cout << "你猜大了" << endl;
	//	}
	//	else if (i_guess < i) {
	//		cout << "你猜小了" << endl;
	//	}
	//	else {
	//		cout << "你猜对了" << endl;
	//		break;
	//	}
	//	
	//}


	//水仙花数 do while循环
	//int n = 99;
	//do 
	//{
	//	n ++;
	//	int a = (n / 100);
	//	int b = (n / 10 % 10);
	//	int c = (n % 10);
	//	if (n == ( a*a*a +  b*b*b +  c*c*c)) 
	//	{
	//		cout << "水仙花数:" << n << endl;
	//	}
	//} while (n < 999);


	//敲桌子，for循环
	/*int q;
	for (q = 1;q<101;q++) 
	{
		if ((q % 10 == 7) || (q / 10 == 7) || (q % 7 == 0))
		{
			cout << "敲桌子\n"<<endl;
		}
		else 
		{
			cout << q<<"\n"<<endl;
		}
	}*/


	// 99乘法表：嵌套循环
	/*int q, w;
	for(q = 1; q < 10; q++)
	{
		for (w = 1; w <= q; w++) 
		{
			cout << q << "×" << w << "=" << w * q << " ";
		}
		cout << endl;
	}
	system("pause");*/

	//goto
	/*cout << "1.*****" << endl;
	goto FLAG;
	cout << "2.*****" << endl;

	cout << "3.*****" << endl;

	cout << "4.*****" << endl;
	FLAG:
	cout << "5.*****" << endl;*/

	//数组
	/*int arr[] = {1,2,3};
	cout << arr << endl;
	cout << arr[2] << endl;
	cout << sizeof(arr) << endl;
	cout << sizeof(arr[2]) << endl;*/

	//一维数组
	/*int arr3[] = { 400,500,100,200,300 };
	int max_value = 0;
	for (int i = 0;i<(sizeof(arr3)/sizeof(arr3[0]));i++) 
	{
		if (arr3[i]>max_value) 
		{
			max_value = arr3[i];
		}
	}
	cout << "最重的为：" << max_value << endl;*/

	/*int arr2[] = { 400,500,100,200,300 };
	int middle_value;
	int start = 0;
	int end = sizeof(arr2) / sizeof(arr2[0]);
	for (start = 0; start < end - 1; start++, end--) 
	{
		middle_value = arr2[start];
		arr2[start] = arr2[end - 1];
		arr2[end - 1] = middle_value;
	}
	cout << "倒叙后的数组为：" <<endl;
	int i;
	for(i = 0;i< sizeof(arr2) / sizeof(arr2[0]);i++){
		cout << arr2[i]<<endl;
	}
	*/

	//冒泡排序
	/*int i,j;
	int middle_m = 0;	
	int arr2[] = { 4,5,6,8,2,1,3,9,7 };
	for (i = 0; i < sizeof(arr2) / sizeof(arr2[1]) - 1; i++) {
		for (j = 0; j < sizeof(arr2) / sizeof(arr2[1]) - i - 1; j++) {
			if (arr2[j]>arr2[j+1]) {
				middle_m = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = middle_m;
			}
		}
	}
	cout << "冒泡后的数组为：";
	for (i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
		cout << arr2[i] << endl;
	}*/

	//二维数组
	/*int arr3[][3] = { {1,2,3},{4,5,6} };
	cout << "二维数组所占空间为："<<sizeof(arr3)<<endl;
	cout << "二维数组一行占用空间为：" << sizeof(arr3[0]) << endl;
	cout << "二维数组一个元素占用空间为：" << sizeof(arr3[0][0]) << endl;

	cout << "二维数组行数：" << sizeof(arr3)/sizeof(arr3[0]) << endl;
	cout << "二维数组列数：" << sizeof(arr3[0])/sizeof(arr3[0][0]) << endl;
	cout << "二维数组首地址：" << (int)arr3 << endl;
	cout << "二维数组第二行首地址：" << (int)arr3[1] << endl;
	cout << "二维数组第一个元素首地址：" << (int)&arr3[0][0] << endl;*/

	////成绩统计
	//int score[][3] = { {100,100,100},{90,50,100},{60,70,80} };
	//int score_add[] = {0,0,0};
	//int i, j;
	//for (i = 0; i < (sizeof(score) / sizeof(score[0])); i++) {
	//	for (j = 0; j < (sizeof(score[0]) / sizeof(score[0][0])); j++) {
	//		score_add[i] = score_add[i] + score[i][j];
	//	}
	//}
	//cout << "三个人的总成绩分别为："<<endl;
	//for (i = 0; i < 3; i++) {
	//	cout << score_add[i] << endl;
	//}

	//函数
	/*int a = 10, b = 20, num_add;
	num_add = add(a, b);
	cout << num_add << endl;*/

	//函数的声明
	//int max_number(int num1, int num2);
	//int a = 10;
	//int b = 20;
	//int c = max_number(a, b);
	//cout << "两个数中更大的值为：" << c << endl;

	//函数分文件编写
	/*int a = 10;
	int b = 20;
	change(a, b);*/

	//指针
	/*int a = 10;
	int *p;
	p = &a;
	cout << "a的地址&a为："<< &a <<endl;
	cout << "p为：" << p << endl;
	*p = 1000;
	cout << "a为："<< a <<endl;
	cout << "*p为："<<*p<<endl;*/

	//指针所占空间
	//比特→字节（8bit=1byte），字节→位（8byte=64位，因为8byte=64bit，所以位又是比特，指占的宽度，范围是0~~2^8）
	/*int* p;
	cout << "p所占字节："<<sizeof(p)<<endl;
	cout << "int型指针所占字节：" << sizeof(int*) << endl;
	cout << "float型指针所占字节：" << sizeof(float*) << endl;
	cout << "char型指针所占字节：" << sizeof(char*) << endl;
	cout << "double型指针所占字节：" << sizeof(double*) << endl;*/

	//空指针与野指针
	//int * p = NULL;
	//*p = 100; //0~255地址是系统占用的，赋值会报错，无法访问。空指针占的是0
	//int* p = (int*)0x1100; //定义一个指针，直接指向一块未被申请的地址，这是不被允许的，野指针
	//cout << "野指针："<<*p<<endl;
	
	//const修饰指针
	//int a = 10;
	//int b = 10;
	//const int* p = &a; //常量指针 const限定*，所以不能进行取值操作
	////*p = b; 错误
	//p = &b;
	//int* const p2 = &a; //指针常量 const限定p（指针），所以不能进行换指向地址操作
	//*p2 = b;
	////p2 = &b; 错误
	//const int * const p3 = &a; //const即修饰指针又修饰常量
	////*p3 = b; 错误
	////p3 = &b; 错误

	//指针与数组
	/*int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr;
	int i;
	for (i = 0; i < 10; i++) {
		cout<<*p<<endl;
		p++;
	}*/

	//指针与函数
	//1.值传递
	/*void swap01(int a, int b);
	int a = 10;
	int b = 20;
	swap01(a, b);
	cout << "a的值：" << a << endl;
	cout << "b的值：" << b << endl;*/

	//2.地址传递
	//void swap02(int* p, int* p1);
	//int a = 10;
	//int b = 20;
	//swap02(&a, &b); //传入的为地址
	//cout << "a的值：" << a << endl;
	//cout << "b的值：" << b << endl;


	//指针、数组、函数;冒泡排序
	//void bubblesort(int* pp, int len);
	//void printAccury(int* ppp, int len);
	//int arr[] = {0,45,8,9,7,65,2,56,49,78,152,6,5};
	//int len = sizeof(arr) / sizeof(arr[0]);
	//bubblesort(arr, len);  // 传入数组首地址即可传入整个数组
	//printAccury(arr, len);

	//结构体
	/*struct Student s1;
	s1.age = 18;
	s1.name = "张三";
	s1.score = 95;
	cout << "姓名：" << s1.name << "年龄：" << s1.age << "分数：" << s1.score << endl;

	struct Student s2 = { "李四", 18, 99 };
	cout << "姓名：" << s2.name << "年龄：" << s2.age << "分数：" << s2.score << endl;

	s3.name = "王五";
	s3.age = 19;
	s3.score = 90;
	cout << "姓名：" << s3.name << "年龄：" << s3.age << "分数：" << s3.score << endl;*/

	//结构体数组
	/*struct Student stuarray[3] = {
		{"张三",18,99},
		{"李四",16,95},
		{"王五",23,69}
	};
	stuarray[2] = { "赵六",21,87 };
	for (int i = 0; i < 3; i++) {
	cout << "姓名：" << stuarray[i].name << "年龄：" << stuarray[i].age << "分数：" << stuarray[i].score << endl;
	}*/

	//结构体指针
	/*struct Student s = { "张三",18,99 };
	struct Student* p = &s;
	cout << "姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;*/

	//结构体嵌套结构体
	/*struct Teacher t;
	t.id = 10000;
	t.name = "老王";
	t.age = 46;
	t.stu.name = "小王";
	t.stu.age = 18;
	t.stu.score = 60;
	cout << "教师姓名：" << t.name << "年龄：" << t.age << "ID：" << t.id << "学生姓名：" << t.stu.name << "年龄：" << t.stu.age << "分数：" << t.stu.score << endl;*/
	
	//结构体做函数参数
	//void printStudent(struct Student s);
	//void printStudent2(struct Student* p);
	//struct Student s4;
	//s4.name = "张三";
	//s4.age = 18;
	//s4.score = 98;
	////值传递
	//printStudent(s4);
	////地址传递
	//printStudent2(&s4);

	//const与结构体
	void printStudent3(const Student* p);
	struct Student s5;
	s5.name = "张三";
	s5.age = 18;
	s5.score = 96;
	printStudent3(&s5);
}

int max_number(int num1,int num2) {
	return num1 > num2 ? num1 : num2;
}

void swap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01中a的值：" << a << endl;
	cout << "swap01中b的值：" << b << endl;
}

void swap02(int *p, int *p1) {  //定义的为指针
	int temp = *p;
	*p = *p1;
	*p1 = temp;
	cout << "swap01中a的值：" << *p << endl;
	cout << "swap01中b的值：" << *p1 << endl;
}

void bubblesort(int * pp, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (pp[j] > pp[j + 1]) {  //数组arr代表首地址，指针p也代表地址，数组arr[0]表示取值，指针*p表示取值，但p[0]在数组中也代表取值
				int temp = pp[j];
				pp[j] = pp[j + 1];
				pp[j + 1] = temp;
			}
		}
	}
}

void printAccury(int* ppp, int len) {
	for (int i = 0; i < len; i++) {
		cout << ppp[i] << endl;
	}
}

void printStudent(struct Student s) {
	cout << "姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;
}

void printStudent2(struct Student* p) {
	cout << "姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;
}

void printStudent3(const Student* p) {
	//p->age = 19;  //不能再修改该值
	cout << "姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;
}