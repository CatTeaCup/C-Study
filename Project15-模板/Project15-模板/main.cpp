#include<iostream>
#include<string>
#include"classmode.hpp"
#include"MyArray.hpp"
using namespace std;

//函数模板
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

template<typename T> //声明一个模板，后面代码中的T不要报错，T是一个通用数据类型。T代替了所有类型，可以是int、float、double等等
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//函数模板的注意事项
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

//函数模板案例-数组排序
template<class T>
void myswapp(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void mysort(T * arr, int len)  //选择排序
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

//函数模板与普通函数的区别
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
	int d = add(a, c);  //隐式类型转换
	cout << d << endl;

	//int e = add2(a, c); //不能隐式类型转换
	int f = add2<int>(a, c);  //可以隐式类型转换
	cout << f << endl;
}

//普通函数与函数模板的调用规则
void myfunc(int a, int b) 
{
	cout << "调用普通函数" << endl;
}

template<class T>
void myfunc(T a, T b) 
{
	cout << "调用函数模板" << endl;
}

template<class T>
void myfunc(T a, T b, T c)
{
	cout << "调用函数模板-重载" << endl;
}

void test03() 
{
	int a = 10;
	int b = 20;
	myfunc(a, b); //1.默认调用普通函数
	myfunc<>(a, b);  //2.通过空模板强制调用函数模板
	int c = 30;
	myfunc(a, b, c);  //3.函数模板重载
	char aa = 'c';
	char bb = 'd';
	myfunc(aa, bb);  //4.函数模板符合条件的话，优先调用函数模板，而非普通函数
}

//模板的局限性
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
void compare(T &p1, T &p2)   //不能是值传递，必须和下面一样也是引用，上面和下面唯一不一样的两点 1.template<> 2.Person而不是T
{
	if (p1 == p2) 
	{
		cout << "相等" << endl;
	}
	else 
	{
		cout << "不相等" << endl;
	}
}
template<> void compare(Person& p1, Person& p2)   //必须有上面的函数模板才能使用特定类型函数模板。并且！如果这段使用的是引用，那么上一段函数模板必须也是引用，不能是值传递
{
	if ((p1.m_age == p2.m_age) && (p1.m_name == p2.m_name)) 
	{
		cout << "类也相等" << endl;
	}
	else 
	{
		cout << "类不相等" << endl;
	}
}

void test04() 
{
	int a = 10;
	int b = 20;
	compare(a, b);

	Person p1("Tom", 10);
	Person p2("Tom", 10);
	compare(p1, p2); //传入类时需要定义特定类型函数模板
}

//类模板
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
	Person2<string,int> p1("老虎",12);  //定义时要把类模板的类型传过去，string=NameType，int=AgeType
	cout << "name:" << p1.m_name << "  age:" << p1.m_age << endl;
}

//类模板与函数模板的区别
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

template<class NameType, class AgeType = int>  //2.类模板的默认类型
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
	//Person3 p3("猪八戒", 18);  //1.自动类型推导，类模板不能用
	Person3<string, int>p3("猪八戒", 18);
	cout << p3.m_name << "  " << p3.m_age << endl;
	Person4<string>p4("猪八戒", 18);  //2.类模板默认类型的时候，只需要传另一个类型
	cout << p4.m_name << "  " << p4.m_age << endl;
}

//类模板中成员函数的创建时机
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
		obj.showPerson11(); //showPerson11为类Person11中的一个成员函数，此时obj不知道是什么类型就可以这么写，是因为类模板中的成员函数是在调用时才创建的
	}
	void func2() 
	{
		obj.showPerson12();
	}
};

void test07() 
{
	myPerson<Person11>mp11;
	mp11.func1();  //调用时才会生成func1
	myPerson<Person12>mp12;
	mp12.func2();  //调用时才会生成func2
}

//类模板做函数参数
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

void show1(myPerson2 <string, int> &mp) //1.指定传入类型（最常用）
{
	mp.show();
}

template<class T1, class T2 > //
void show2(myPerson2<T1, T2>& mp) //2.参数模板化
{
	mp.show();
	cout << "T1的数据类型：" << typeid(T1).name() << endl;  //看模板的数据类型
	cout << "T2的数据类型：" << typeid(T2).name() << endl;
}

template<class T> //
void show3(T& t)  //3.整个类模板化
{
	t.show();
	cout << "T的数据类型：" << typeid(T).name() << endl;
}

void test08() 
{
	myPerson2 <string,int> mp("Tom", 18);
	show1(mp);
	show2(mp);
	show3(mp);
}

//类模板与继承
template<class T>
class BASE 
{
public:
	T m_t;
};

class Child:public BASE<int>  //类模板继承：①指定父类T的类型
{
};

template<class T1, class T2>  //类模板继承：②任意类型
class Child2 :public BASE<T1>  //②
{
public:
	T2 m_t2;
	Child2() 
	{
		cout << "T1的类型为:" << typeid(T1).name() << endl;
		cout << "T2的类型为:" << typeid(T2).name() << endl;
	}
};

void test09() 
{
	Child2<int, char>c2;  //类模板不能自动类型推导，只能赋类型。int赋给T1,所以BASE类传下来的是个int型，char赋给T2，所以Child2是个char类型
}

//类模板的类外实现
template<class T1, class T2>
class Base 
{
public:
	string m_name;
	int m_age;
	Base(T1 name, T2 age); //构造函数
	/*{
		this->m_name = name;
		this->m_age = age;
	}*/
	void show(); //普通函数
};
template<class T1,class T2> //类外实现，加template
Base<T1, T2>::Base(T1 name, T2 age) //类外实现，加Base，加<T1, T2>
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

//类模板的分文件编写
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

//类模板与友元
template<class T1, class T2>
class Personn;
template<class T1, class T2> //全局函数的类外实现。是一个函数模板，用来访问类模板的private
void showperson2(Personn<T1, T2> p)   //有Personn，还要事先声明Personn的存在
{
	cout << "姓名是：" << p.name << "   年龄是：" << p.age << endl;
}

template<class T1, class T2>
class Personn 
{
public:
	friend void showperson(Personn<T1,T2> p)//全局函数的类内实现-友元
	{
		cout << "姓名是：" << p.name << "   年龄是：" << p.age << endl;
	}

	//全局函数的类外实现-友元
	//friend void showperson2(Personn<T1, T2> p);  //这个是一个普通函数的声明，但是上面的类外实现定义的是一个函数模板，所以需要让编译器知道这是一个函数模板的声明
	friend void showperson2<>(Personn<T1, T2> p);  //加空参数列表声明这是一个函数模板

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
	showperson(p);  //全局函数的类内实现-友元（可以访问一个类的私有成员）
	Personn<string, int>p2("Jerry", 20);
	showperson2(p2);  //全局函数的类外实现-友元
}

//数组类封装
void printArr(MyArray <int>& arr) 
{
	for (int i = 0; i < arr.returnSize(); i++) 
	{
		cout << arr[i] << endl;  //访问下标
	}
}

void test13() 
{
	MyArray<int>arr1(5); //有参构造
	//MyArray<int>arr2(arr1);  //拷贝构造
	//MyArray<int>arr3(100);
	//arr3 = arr1;  //operator=

	for (int i = 0; i < arr1.returnCapacity(); i++)  //尾插法插入元素
	{
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为：  " << endl;
	printArr(arr1);  //按下标访问数组中的元素

	arr1.Pop_Back();  //尾删法
	cout << "arr1的打印输出为：  " << endl;
	printArr(arr1);
	cout << "arr1的capacity为：" << arr1.returnCapacity() << endl;
	cout << "arr1的size为：" << arr1.returnSize() << endl;
}


int main() 
{
	//C++提高部分存在：泛型编程与STL。模板是用来实现泛型编程的
	//模板就是建立通用的模具，大大提高复用性

	//模板又可以分为函数模板与类模板
	//函数模板：将类型参数化（int、float等）
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
	myswap(a1, b1);  //两种方式使用函数模板：1.自动类型推导
	cout << a1 << "   " << b1 << endl;
	myswap<int>(a1, b1);  //2.显示指定类型：myswap函数名、<int>表示指定了T的类型是int、(a,b)表示传入函数的两个参数为a和b
	cout << a1 << "   " << b1 << endl;

	//函数模板注意事项：  1.自动类型推导，T必须为一致的数据类型  2.模板必须确定出数据类型T，才能使用
	int a2 = 10;
	int b2 = 20;
	char c2 = 'a';
	swapswap(a2, b2);
	//swapswap(a2, c2);  // 不正确，两个T必须一样
	//func(); //此时就不能用自动类型推导了，因为没有传输任何T，所以编译器无法推断出T的类型
	func<int>(); //只能这么用

	//函数模板案例-数组排序
	test01();

	//函数模板与普通函数的区别：普通函数可以发生隐式类型转换；函数模板的自动类型推导不能发生隐式类型转换；函数模板的显示指定类型可以发生隐式类型转换
	test02();

	//普通函数与函数模板的调用规则：
	//1.都可以调用，优先调用普通函数
	//2.通过空模板参数列表强制调用函数模板
	//3.函数模板可以发生重载
	//4.如果函数模板可以产生更好的匹配，优先调用函数模板
	test03();

	//模板的局限性
	//模板处理默认的数据类型是可以随意使用的，比如int、float、char等，但是当数组、结构体、类等就不能默认使用了。因此需要提供特定类的函数模板
	test04();
	//现在学模板不是为了定义模板，而是为了在STL中学会使用模板。STL实际上就是别人定义好了模板，你拿来用（比如unordered<char int>need或者vector<int>arr）

	//类模板
	test05();
	//STL中的vector<int>index、unordered<char, int>need实际上就是个类模板？

	//类模板与函数模板的区别
	//1.类模板不能使用自动类型推导 2.类模板可以在参数列表里定义默认值
	test06();

	//类模板中成员函数的创建时机
	//类模板中成员函数的创建不是像类一样一开始就创建的，而是调用时才去创建
	test07();

	//类模板做函数参数
	test08();

	//类模板与继承
	test09();

	//类模板的类外实现
	test10();

	//类模板的分文件编写
	//①写一个类模板：首先写成员，然后把成员类外实现，那么把类模板及成员放到h文件，把类外实现放到cpp文件中，在非类模板的情况下只要在主函数中包含。h文件就可以完成分文件编写了，h相当于一个接口，cpp是源码
	//但是在类模板中，成员函数的调用不是在编译阶段生成的，所以主程序中调用h会出现在声明时仅调用了h而没有调用cpp的情况。
	//②解决方法第一个是，在主程序中包含cpp文件，那么由于cpp中也声明h，所以调用cpp会先访问h然后访问cpp，这样就可以正确调用了。但是在实际中，cpp是源码，没有这么直接调用源码的
	//③所以另一个解决方案是，把h和cpp合在一起，然后把后缀改为hpp，主程序中调用hpp即可。hpp文件就是类模板文件
	test11();

	//类模板与友元
	test12();

	//数组类封装
	//class myArray 
	//{
	//private:
	//	数组 T* pAddress   (T * = new T[6])
	//	容量 m_capacity
	//	大小 m_size
	//public:
	//	构造函数
	//	拷贝构造
	//	operator =  //当类中有堆区数据，一定要拷贝构造+operator =，防止浅拷贝出现
	//	利用下标的方式访问数组中的元素  //案例要求功能
	//	尾插法  //案例要求功能
	//	尾删法  //案例要求功能
	//	获取数组容量  //案例要求功能
	//	获取数组大小  //案例要求功能
	//	析构函数
	//};
	test13();
}