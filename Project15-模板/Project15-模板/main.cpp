#include<iostream>
#include<string>
#include"classmode.hpp"
#include"MyArray.hpp"
using namespace std;

//����ģ��
void swapint(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
}
void swapfloat(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

template<typename T> //����һ��ģ�壬��������е�T��Ҫ����T��һ��ͨ���������͡�T�������������ͣ�������int��float��double�ȵ�
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//����ģ���ע������
template<class T>
void swapswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void func() 
{
	cout << "func" << endl;
}

//����ģ�尸��-��������
template<class T>
void myswapp(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void mysort(T * arr, int len)  //ѡ������
{
	for (int i = 0; i < len; i++) 
	{
		int max = i;
		for (int j = i + 1; j < len; j++) 
		{
			if (arr[j] > arr[max]) 
			{
				max = j;
			}
		}
		if (max != i) 
		{
			myswapp(arr[max], arr[i]);
		}
	}
}

template<class T>
void printarr(T * a, int len) 
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << "  " ;
	}
	cout << endl;
}

void test01() 
{
	char arr[] = "ahgys";
	int len = sizeof(arr) / sizeof(arr[0]);
	mysort(arr, len);
	printarr(arr, len);

	int arr2[] = {1,2,3,4,5};
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	mysort(arr2, len2);
	printarr(arr2, len2);
}

//����ģ������ͨ����������
int add(int a,int b) 
{
	return a + b;
}

template<class T>
T add2(T a, T b) 
{
	return a + b;
}

void test02() 
{
	int a = 10;
	char c = 'c';
	int d = add(a, c);  //��ʽ����ת��
	cout << d << endl;

	//int e = add2(a, c); //������ʽ����ת��
	int f = add2<int>(a, c);  //������ʽ����ת��
	cout << f << endl;
}

//��ͨ�����뺯��ģ��ĵ��ù���
void myfunc(int a, int b) 
{
	cout << "������ͨ����" << endl;
}

template<class T>
void myfunc(T a, T b) 
{
	cout << "���ú���ģ��" << endl;
}

template<class T>
void myfunc(T a, T b, T c)
{
	cout << "���ú���ģ��-����" << endl;
}

void test03() 
{
	int a = 10;
	int b = 20;
	myfunc(a, b); //1.Ĭ�ϵ�����ͨ����
	myfunc<>(a, b);  //2.ͨ����ģ��ǿ�Ƶ��ú���ģ��
	int c = 30;
	myfunc(a, b, c);  //3.����ģ������
	char aa = 'c';
	char bb = 'd';
	myfunc(aa, bb);  //4.����ģ����������Ļ������ȵ��ú���ģ�壬������ͨ����
}

//ģ��ľ�����
class Person 
{
public:
	string m_name;
	int m_age;
	Person(string a, int b) 
	{
		this->m_name = a;
		this->m_age = b;
	}
};

template<class T>
void compare(T &p1, T &p2)   //������ֵ���ݣ����������һ��Ҳ�����ã����������Ψһ��һ�������� 1.template<> 2.Person������T
{
	if (p1 == p2) 
	{
		cout << "���" << endl;
	}
	else 
	{
		cout << "�����" << endl;
	}
}
template<> void compare(Person& p1, Person& p2)   //����������ĺ���ģ�����ʹ���ض����ͺ���ģ�塣���ң�������ʹ�õ������ã���ô��һ�κ���ģ�����Ҳ�����ã�������ֵ����
{
	if ((p1.m_age == p2.m_age) && (p1.m_name == p2.m_name)) 
	{
		cout << "��Ҳ���" << endl;
	}
	else 
	{
		cout << "�಻���" << endl;
	}
}

void test04() 
{
	int a = 10;
	int b = 20;
	compare(a, b);

	Person p1("Tom", 10);
	Person p2("Tom", 10);
	compare(p1, p2); //������ʱ��Ҫ�����ض����ͺ���ģ��
}

//��ģ��
template<class NameType,class AgeType>
class Person2 
{
public:
	Person2(NameType name, AgeType age) 
	{
		this->m_age = age;
		this->m_name = name;
	}
	NameType m_name;
	AgeType m_age;
};

void test05() 
{
	Person2<string,int> p1("�ϻ�",12);  //����ʱҪ����ģ������ʹ���ȥ��string=NameType��int=AgeType
	cout << "name:" << p1.m_name << "  age:" << p1.m_age << endl;
}

//��ģ���뺯��ģ�������
template<class NameType,class AgeType>
class Person3 
{
public:
	NameType m_name;
	AgeType m_age;
	Person3(NameType name, AgeType age) 
	{
		this->m_name = name;
		this->m_age = age;
	}
};

template<class NameType, class AgeType = int>  //2.��ģ���Ĭ������
class Person4
{
public:
	NameType m_name;
	AgeType m_age;
	Person4(NameType name, AgeType age)
	{
		this->m_name = name;
		this->m_age = age;
	}
};

void test06() 
{
	//Person3 p3("��˽�", 18);  //1.�Զ������Ƶ�����ģ�岻����
	Person3<string, int>p3("��˽�", 18);
	cout << p3.m_name << "  " << p3.m_age << endl;
	Person4<string>p4("��˽�", 18);  //2.��ģ��Ĭ�����͵�ʱ��ֻ��Ҫ����һ������
	cout << p4.m_name << "  " << p4.m_age << endl;
}

//��ģ���г�Ա�����Ĵ���ʱ��
class Person11 
{
public:
	void showPerson11() 
	{
		cout << "Person11" << endl;
	}
};

class Person12
{
public:
	void showPerson12()
	{
		cout << "Person12" << endl;
	}
};

template<class T>
class myPerson 
{
public:
	T obj;
	void func1() 
	{
		obj.showPerson11(); //showPerson11Ϊ��Person11�е�һ����Ա��������ʱobj��֪����ʲô���;Ϳ�����ôд������Ϊ��ģ���еĳ�Ա�������ڵ���ʱ�Ŵ�����
	}
	void func2() 
	{
		obj.showPerson12();
	}
};

void test07() 
{
	myPerson<Person11>mp11;
	mp11.func1();  //����ʱ�Ż�����func1
	myPerson<Person12>mp12;
	mp12.func2();  //����ʱ�Ż�����func2
}

//��ģ������������
template<class T1, class T2>
class myPerson2 
{
public:
	string m_name;
	int m_age;
	myPerson2(string name, int age) 
	{
		m_name = name;
		m_age = age;
	}
	void show() 
	{
		cout << m_name << "  " << m_age << endl;
	}
};

void show1(myPerson2 <string, int> &mp) //1.ָ���������ͣ���ã�
{
	mp.show();
}

template<class T1, class T2 > //
void show2(myPerson2<T1, T2>& mp) //2.����ģ�廯
{
	mp.show();
	cout << "T1���������ͣ�" << typeid(T1).name() << endl;  //��ģ�����������
	cout << "T2���������ͣ�" << typeid(T2).name() << endl;
}

template<class T> //
void show3(T& t)  //3.������ģ�廯
{
	t.show();
	cout << "T���������ͣ�" << typeid(T).name() << endl;
}

void test08() 
{
	myPerson2 <string,int> mp("Tom", 18);
	show1(mp);
	show2(mp);
	show3(mp);
}

//��ģ����̳�
template<class T>
class BASE 
{
public:
	T m_t;
};

class Child:public BASE<int>  //��ģ��̳У���ָ������T������
{
};

template<class T1, class T2>  //��ģ��̳У�����������
class Child2 :public BASE<T1>  //��
{
public:
	T2 m_t2;
	Child2() 
	{
		cout << "T1������Ϊ:" << typeid(T1).name() << endl;
		cout << "T2������Ϊ:" << typeid(T2).name() << endl;
	}
};

void test09() 
{
	Child2<int, char>c2;  //��ģ�岻���Զ������Ƶ���ֻ�ܸ����͡�int����T1,����BASE�ഫ�������Ǹ�int�ͣ�char����T2������Child2�Ǹ�char����
}

//��ģ�������ʵ��
template<class T1, class T2>
class Base 
{
public:
	string m_name;
	int m_age;
	Base(T1 name, T2 age); //���캯��
	/*{
		this->m_name = name;
		this->m_age = age;
	}*/
	void show(); //��ͨ����
};
template<class T1,class T2> //����ʵ�֣���template
Base<T1, T2>::Base(T1 name, T2 age) //����ʵ�֣���Base����<T1, T2>
{
	this->m_name = name;
	this->m_age = age;
}

template<class T1, class T2>
void Base<T1, T2>::show() 
{
	cout << "name:" << this->m_name << endl;
	cout << "age:" << this->m_age << endl;
}

void test10() 
{
	Base<string, int> b("Wei", 18);
	b.show();
}

//��ģ��ķ��ļ���д
//template<class T1, class T2>
//class Ppp
//{
//public:
//	T1 m_age;
//	T2 m_name;
//	Ppp(T1 name, T2 age);
//	void show();
//};
//template<class T1, class T2>
//Ppp<T1, T2>::Ppp(T1 name, T2 age)
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//template<class T1, class T2>
//void Ppp<T1, T2>::show() 
//{
//	cout << "name:" << this->m_name << endl;
//	cout << "age:" << this->m_age << endl;
//}

void test11() 
{
	Ppp<int, string> p(19, "Jerry");
	p.show();
}

//��ģ������Ԫ
template<class T1, class T2>
class Personn;
template<class T1, class T2> //ȫ�ֺ���������ʵ�֡���һ������ģ�壬����������ģ���private
void showperson2(Personn<T1, T2> p)   //��Personn����Ҫ��������Personn�Ĵ���
{
	cout << "�����ǣ�" << p.name << "   �����ǣ�" << p.age << endl;
}

template<class T1, class T2>
class Personn 
{
public:
	friend void showperson(Personn<T1,T2> p)//ȫ�ֺ���������ʵ��-��Ԫ
	{
		cout << "�����ǣ�" << p.name << "   �����ǣ�" << p.age << endl;
	}

	//ȫ�ֺ���������ʵ��-��Ԫ
	//friend void showperson2(Personn<T1, T2> p);  //�����һ����ͨ�������������������������ʵ�ֶ������һ������ģ�壬������Ҫ�ñ�����֪������һ������ģ�������
	friend void showperson2<>(Personn<T1, T2> p);  //�ӿղ����б���������һ������ģ��

	Personn(T1 name, T2 age) 
	{
		this->name = name;
		this->age = age;
	}
private:
	T1 name;
	T2 age;
};
void test12() 
{
	Personn<string,int> p("Tom",20);
	showperson(p);  //ȫ�ֺ���������ʵ��-��Ԫ�����Է���һ�����˽�г�Ա��
	Personn<string, int>p2("Jerry", 20);
	showperson2(p2);  //ȫ�ֺ���������ʵ��-��Ԫ
}

//�������װ
void printArr(MyArray <int>& arr) 
{
	for (int i = 0; i < arr.returnSize(); i++) 
	{
		cout << arr[i] << endl;  //�����±�
	}
}

void test13() 
{
	MyArray<int>arr1(5); //�вι���
	//MyArray<int>arr2(arr1);  //��������
	//MyArray<int>arr3(100);
	//arr3 = arr1;  //operator=

	for (int i = 0; i < arr1.returnCapacity(); i++)  //β�巨����Ԫ��
	{
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��  " << endl;
	printArr(arr1);  //���±���������е�Ԫ��

	arr1.Pop_Back();  //βɾ��
	cout << "arr1�Ĵ�ӡ���Ϊ��  " << endl;
	printArr(arr1);
	cout << "arr1��capacityΪ��" << arr1.returnCapacity() << endl;
	cout << "arr1��sizeΪ��" << arr1.returnSize() << endl;
}


int main() 
{
	//C++��߲��ִ��ڣ����ͱ����STL��ģ��������ʵ�ַ��ͱ�̵�
	//ģ����ǽ���ͨ�õ�ģ�ߣ������߸�����

	//ģ���ֿ��Է�Ϊ����ģ������ģ��
	//����ģ�壺�����Ͳ�������int��float�ȣ�
	int a = 10;
	int b = 20;
	swapint(a, b);
	cout << a << "   " << b << endl;
	float aa = 10;
	float bb = 20;
	swapfloat(aa, bb);
	cout << aa << "   " << bb << endl;

	int a1 = 10;
	int b1 = 20;
	myswap(a1, b1);  //���ַ�ʽʹ�ú���ģ�壺1.�Զ������Ƶ�
	cout << a1 << "   " << b1 << endl;
	myswap<int>(a1, b1);  //2.��ʾָ�����ͣ�myswap��������<int>��ʾָ����T��������int��(a,b)��ʾ���뺯������������Ϊa��b
	cout << a1 << "   " << b1 << endl;

	//����ģ��ע�����  1.�Զ������Ƶ���T����Ϊһ�µ���������  2.ģ�����ȷ������������T������ʹ��
	int a2 = 10;
	int b2 = 20;
	char c2 = 'a';
	swapswap(a2, b2);
	//swapswap(a2, c2);  // ����ȷ������T����һ��
	//func(); //��ʱ�Ͳ������Զ������Ƶ��ˣ���Ϊû�д����κ�T�����Ա������޷��ƶϳ�T������
	func<int>(); //ֻ����ô��

	//����ģ�尸��-��������
	test01();

	//����ģ������ͨ������������ͨ�������Է�����ʽ����ת��������ģ����Զ������Ƶ����ܷ�����ʽ����ת��������ģ�����ʾָ�����Ϳ��Է�����ʽ����ת��
	test02();

	//��ͨ�����뺯��ģ��ĵ��ù���
	//1.�����Ե��ã����ȵ�����ͨ����
	//2.ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
	//3.����ģ����Է�������
	//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	test03();

	//ģ��ľ�����
	//ģ�崦��Ĭ�ϵ����������ǿ�������ʹ�õģ�����int��float��char�ȣ����ǵ����顢�ṹ�塢��ȾͲ���Ĭ��ʹ���ˡ������Ҫ�ṩ�ض���ĺ���ģ��
	test04();
	//����ѧģ�岻��Ϊ�˶���ģ�壬����Ϊ����STL��ѧ��ʹ��ģ�塣STLʵ���Ͼ��Ǳ��˶������ģ�壬�������ã�����unordered<char int>need����vector<int>arr��

	//��ģ��
	test05();
	//STL�е�vector<int>index��unordered<char, int>needʵ���Ͼ��Ǹ���ģ�壿

	//��ģ���뺯��ģ�������
	//1.��ģ�岻��ʹ���Զ������Ƶ� 2.��ģ������ڲ����б��ﶨ��Ĭ��ֵ
	test06();

	//��ģ���г�Ա�����Ĵ���ʱ��
	//��ģ���г�Ա�����Ĵ�����������һ��һ��ʼ�ʹ����ģ����ǵ���ʱ��ȥ����
	test07();

	//��ģ������������
	test08();

	//��ģ����̳�
	test09();

	//��ģ�������ʵ��
	test10();

	//��ģ��ķ��ļ���д
	//��дһ����ģ�壺����д��Ա��Ȼ��ѳ�Ա����ʵ�֣���ô����ģ�弰��Ա�ŵ�h�ļ���������ʵ�ַŵ�cpp�ļ��У��ڷ���ģ��������ֻҪ���������а�����h�ļ��Ϳ�����ɷ��ļ���д�ˣ�h�൱��һ���ӿڣ�cpp��Դ��
	//��������ģ���У���Ա�����ĵ��ò����ڱ���׶����ɵģ������������е���h�����������ʱ��������h��û�е���cpp�������
	//�ڽ��������һ���ǣ����������а���cpp�ļ�����ô����cpp��Ҳ����h�����Ե���cpp���ȷ���hȻ�����cpp�������Ϳ�����ȷ�����ˡ�������ʵ���У�cpp��Դ�룬û����ôֱ�ӵ���Դ���
	//��������һ����������ǣ���h��cpp����һ��Ȼ��Ѻ�׺��Ϊhpp���������е���hpp���ɡ�hpp�ļ�������ģ���ļ�
	test11();

	//��ģ������Ԫ
	test12();

	//�������װ
	//class myArray 
	//{
	//private:
	//	���� T* pAddress   (T * = new T[6])
	//	���� m_capacity
	//	��С m_size
	//public:
	//	���캯��
	//	��������
	//	operator =  //�������ж������ݣ�һ��Ҫ��������+operator =����ֹǳ��������
	//	�����±�ķ�ʽ���������е�Ԫ��  //����Ҫ����
	//	β�巨  //����Ҫ����
	//	βɾ��  //����Ҫ����
	//	��ȡ��������  //����Ҫ����
	//	��ȡ�����С  //����Ҫ����
	//	��������
	//};
	test13();
}