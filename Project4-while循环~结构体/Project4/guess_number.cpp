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

	//���������whileѭ��
	//int i = rand() % 100;
	//int i_guess;
	//while (1) {
	//	cout << "���������һ������" << endl;
	//	cin >> i_guess;
	//	if (i_guess > i) {
	//		cout << "��´���" << endl;
	//	}
	//	else if (i_guess < i) {
	//		cout << "���С��" << endl;
	//	}
	//	else {
	//		cout << "��¶���" << endl;
	//		break;
	//	}
	//	
	//}


	//ˮ�ɻ��� do whileѭ��
	//int n = 99;
	//do 
	//{
	//	n ++;
	//	int a = (n / 100);
	//	int b = (n / 10 % 10);
	//	int c = (n % 10);
	//	if (n == ( a*a*a +  b*b*b +  c*c*c)) 
	//	{
	//		cout << "ˮ�ɻ���:" << n << endl;
	//	}
	//} while (n < 999);


	//�����ӣ�forѭ��
	/*int q;
	for (q = 1;q<101;q++) 
	{
		if ((q % 10 == 7) || (q / 10 == 7) || (q % 7 == 0))
		{
			cout << "������\n"<<endl;
		}
		else 
		{
			cout << q<<"\n"<<endl;
		}
	}*/


	// 99�˷���Ƕ��ѭ��
	/*int q, w;
	for(q = 1; q < 10; q++)
	{
		for (w = 1; w <= q; w++) 
		{
			cout << q << "��" << w << "=" << w * q << " ";
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

	//����
	/*int arr[] = {1,2,3};
	cout << arr << endl;
	cout << arr[2] << endl;
	cout << sizeof(arr) << endl;
	cout << sizeof(arr[2]) << endl;*/

	//һά����
	/*int arr3[] = { 400,500,100,200,300 };
	int max_value = 0;
	for (int i = 0;i<(sizeof(arr3)/sizeof(arr3[0]));i++) 
	{
		if (arr3[i]>max_value) 
		{
			max_value = arr3[i];
		}
	}
	cout << "���ص�Ϊ��" << max_value << endl;*/

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
	cout << "����������Ϊ��" <<endl;
	int i;
	for(i = 0;i< sizeof(arr2) / sizeof(arr2[0]);i++){
		cout << arr2[i]<<endl;
	}
	*/

	//ð������
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
	cout << "ð�ݺ������Ϊ��";
	for (i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
		cout << arr2[i] << endl;
	}*/

	//��ά����
	/*int arr3[][3] = { {1,2,3},{4,5,6} };
	cout << "��ά������ռ�ռ�Ϊ��"<<sizeof(arr3)<<endl;
	cout << "��ά����һ��ռ�ÿռ�Ϊ��" << sizeof(arr3[0]) << endl;
	cout << "��ά����һ��Ԫ��ռ�ÿռ�Ϊ��" << sizeof(arr3[0][0]) << endl;

	cout << "��ά����������" << sizeof(arr3)/sizeof(arr3[0]) << endl;
	cout << "��ά����������" << sizeof(arr3[0])/sizeof(arr3[0][0]) << endl;
	cout << "��ά�����׵�ַ��" << (int)arr3 << endl;
	cout << "��ά����ڶ����׵�ַ��" << (int)arr3[1] << endl;
	cout << "��ά�����һ��Ԫ���׵�ַ��" << (int)&arr3[0][0] << endl;*/

	////�ɼ�ͳ��
	//int score[][3] = { {100,100,100},{90,50,100},{60,70,80} };
	//int score_add[] = {0,0,0};
	//int i, j;
	//for (i = 0; i < (sizeof(score) / sizeof(score[0])); i++) {
	//	for (j = 0; j < (sizeof(score[0]) / sizeof(score[0][0])); j++) {
	//		score_add[i] = score_add[i] + score[i][j];
	//	}
	//}
	//cout << "�����˵��ܳɼ��ֱ�Ϊ��"<<endl;
	//for (i = 0; i < 3; i++) {
	//	cout << score_add[i] << endl;
	//}

	//����
	/*int a = 10, b = 20, num_add;
	num_add = add(a, b);
	cout << num_add << endl;*/

	//����������
	//int max_number(int num1, int num2);
	//int a = 10;
	//int b = 20;
	//int c = max_number(a, b);
	//cout << "�������и����ֵΪ��" << c << endl;

	//�������ļ���д
	/*int a = 10;
	int b = 20;
	change(a, b);*/

	//ָ��
	/*int a = 10;
	int *p;
	p = &a;
	cout << "a�ĵ�ַ&aΪ��"<< &a <<endl;
	cout << "pΪ��" << p << endl;
	*p = 1000;
	cout << "aΪ��"<< a <<endl;
	cout << "*pΪ��"<<*p<<endl;*/

	//ָ����ռ�ռ�
	//���ء��ֽڣ�8bit=1byte�����ֽڡ�λ��8byte=64λ����Ϊ8byte=64bit������λ���Ǳ��أ�ָռ�Ŀ�ȣ���Χ��0~~2^8��
	/*int* p;
	cout << "p��ռ�ֽڣ�"<<sizeof(p)<<endl;
	cout << "int��ָ����ռ�ֽڣ�" << sizeof(int*) << endl;
	cout << "float��ָ����ռ�ֽڣ�" << sizeof(float*) << endl;
	cout << "char��ָ����ռ�ֽڣ�" << sizeof(char*) << endl;
	cout << "double��ָ����ռ�ֽڣ�" << sizeof(double*) << endl;*/

	//��ָ����Ұָ��
	//int * p = NULL;
	//*p = 100; //0~255��ַ��ϵͳռ�õģ���ֵ�ᱨ���޷����ʡ���ָ��ռ����0
	//int* p = (int*)0x1100; //����һ��ָ�룬ֱ��ָ��һ��δ������ĵ�ַ�����ǲ�������ģ�Ұָ��
	//cout << "Ұָ�룺"<<*p<<endl;
	
	//const����ָ��
	//int a = 10;
	//int b = 10;
	//const int* p = &a; //����ָ�� const�޶�*�����Բ��ܽ���ȡֵ����
	////*p = b; ����
	//p = &b;
	//int* const p2 = &a; //ָ�볣�� const�޶�p��ָ�룩�����Բ��ܽ��л�ָ���ַ����
	//*p2 = b;
	////p2 = &b; ����
	//const int * const p3 = &a; //const������ָ�������γ���
	////*p3 = b; ����
	////p3 = &b; ����

	//ָ��������
	/*int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr;
	int i;
	for (i = 0; i < 10; i++) {
		cout<<*p<<endl;
		p++;
	}*/

	//ָ���뺯��
	//1.ֵ����
	/*void swap01(int a, int b);
	int a = 10;
	int b = 20;
	swap01(a, b);
	cout << "a��ֵ��" << a << endl;
	cout << "b��ֵ��" << b << endl;*/

	//2.��ַ����
	//void swap02(int* p, int* p1);
	//int a = 10;
	//int b = 20;
	//swap02(&a, &b); //�����Ϊ��ַ
	//cout << "a��ֵ��" << a << endl;
	//cout << "b��ֵ��" << b << endl;


	//ָ�롢���顢����;ð������
	//void bubblesort(int* pp, int len);
	//void printAccury(int* ppp, int len);
	//int arr[] = {0,45,8,9,7,65,2,56,49,78,152,6,5};
	//int len = sizeof(arr) / sizeof(arr[0]);
	//bubblesort(arr, len);  // ���������׵�ַ���ɴ�����������
	//printAccury(arr, len);

	//�ṹ��
	/*struct Student s1;
	s1.age = 18;
	s1.name = "����";
	s1.score = 95;
	cout << "������" << s1.name << "���䣺" << s1.age << "������" << s1.score << endl;

	struct Student s2 = { "����", 18, 99 };
	cout << "������" << s2.name << "���䣺" << s2.age << "������" << s2.score << endl;

	s3.name = "����";
	s3.age = 19;
	s3.score = 90;
	cout << "������" << s3.name << "���䣺" << s3.age << "������" << s3.score << endl;*/

	//�ṹ������
	/*struct Student stuarray[3] = {
		{"����",18,99},
		{"����",16,95},
		{"����",23,69}
	};
	stuarray[2] = { "����",21,87 };
	for (int i = 0; i < 3; i++) {
	cout << "������" << stuarray[i].name << "���䣺" << stuarray[i].age << "������" << stuarray[i].score << endl;
	}*/

	//�ṹ��ָ��
	/*struct Student s = { "����",18,99 };
	struct Student* p = &s;
	cout << "������" << p->name << "���䣺" << p->age << "������" << p->score << endl;*/

	//�ṹ��Ƕ�׽ṹ��
	/*struct Teacher t;
	t.id = 10000;
	t.name = "����";
	t.age = 46;
	t.stu.name = "С��";
	t.stu.age = 18;
	t.stu.score = 60;
	cout << "��ʦ������" << t.name << "���䣺" << t.age << "ID��" << t.id << "ѧ��������" << t.stu.name << "���䣺" << t.stu.age << "������" << t.stu.score << endl;*/
	
	//�ṹ������������
	//void printStudent(struct Student s);
	//void printStudent2(struct Student* p);
	//struct Student s4;
	//s4.name = "����";
	//s4.age = 18;
	//s4.score = 98;
	////ֵ����
	//printStudent(s4);
	////��ַ����
	//printStudent2(&s4);

	//const��ṹ��
	void printStudent3(const Student* p);
	struct Student s5;
	s5.name = "����";
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
	cout << "swap01��a��ֵ��" << a << endl;
	cout << "swap01��b��ֵ��" << b << endl;
}

void swap02(int *p, int *p1) {  //�����Ϊָ��
	int temp = *p;
	*p = *p1;
	*p1 = temp;
	cout << "swap01��a��ֵ��" << *p << endl;
	cout << "swap01��b��ֵ��" << *p1 << endl;
}

void bubblesort(int * pp, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (pp[j] > pp[j + 1]) {  //����arr�����׵�ַ��ָ��pҲ�����ַ������arr[0]��ʾȡֵ��ָ��*p��ʾȡֵ����p[0]��������Ҳ����ȡֵ
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
	cout << "������" << s.name << "���䣺" << s.age << "������" << s.score << endl;
}

void printStudent2(struct Student* p) {
	cout << "������" << p->name << "���䣺" << p->age << "������" << p->score << endl;
}

void printStudent3(const Student* p) {
	//p->age = 19;  //�������޸ĸ�ֵ
	cout << "������" << p->name << "���䣺" << p->age << "������" << p->score << endl;
}