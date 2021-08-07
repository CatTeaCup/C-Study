#include<iostream>
using namespace std;

//全局函数做友元
class Building 
{
	friend void goodgay(Building* building);  //将全局函数+friend在类中做一下声明，就可以访问该类的private域
public:
	void livingroom() 
	{
		cout << "public域的成员函数：living room" << endl;
	}
private:
	void bedroom() 
	{
		cout << "private域的成员函数：bed room---需要友元来进行访问" << endl;
	}

};

void goodgay(Building * building)  //全局函数
{
	building->livingroom();
	building->bedroom();  //将想访问private域的全局函数在类中使用friend定义，即可在该全局函数中访问私有域
}

void test01() 
{
	//Building* building;
	//goodgay(building);  // 不要用指针来初始化一个类！！！  指针只是定义了一个类指针，并非定义了一个类，这个指针没有指向一个对象的权力
	Building building;
	goodgay(&building);  //应该用值来初始化一个类，生成一个对象，然后传递其地址，如果不这样会报错：使用了未初始化的局部变量。
						 //这也是之前单链表算法里定义一个类指针后必须要在堆区里开辟内存放置对象一样，因为指针是虚的，并非一个对象，只是一个对象指针
}

//类做友元
class Building2;  //提前声明，防止编译器报错

class GoodGay 
{
public:
	GoodGay(); //即使是构造函数，在类外定义时也要类内声明
	void visit();  //用于类外构造
	Building2 * building2;
};

class Building2 
{
	friend class GoodGay;  //类做友元：调用GoodGay会初始化一个Building2对象，再调用visit会访问Building2内的成员变量。GoodGay做Building2的友元
public:
	Building2();  //用于类外构造
	string livingroom;
private:
	string bedroom;
};

Building2::Building2()  // 类内函数（无参构造）类外定义 
{
	livingroom = "客厅";
	bedroom = "卧室";
}
GoodGay::GoodGay()
{
	building2 = new Building2;
}
void GoodGay::visit()  //类内函数（非构造函数）类外定义，需要有void
{
	cout<<building2->livingroom<<endl;
	cout<<building2->bedroom<<endl;  //想要访问Building2的私有变量，需要在Building2的类里定义GoodGay的友元
}

void test02() 
{
	GoodGay goodgay2;
	goodgay2.visit();
}

//成员函数做友元
class Building3;

class GoodGay2 
{
public:
	GoodGay2();
	void visit();
	void visit2();
	Building3 * building3;
};
	//GoodGay2::GoodGay2()
	//{
	//	building3 = new Building3;  //虽然之前声明了class Building3;，告知有这一类，但是并不知道有什么成员，所以new Building3是非法的，不知道有什么怎么在堆区创建这个对象呢。要挪到定义Building3下面去，其余的void visit等也是一样
	//}

class Building3
{
	friend void GoodGay2::visit();  //类的成员函数做友元
public:
	//string m_livingroom = "客厅";
	string m_livingroom;
	Building3();
private:
	//string m_bedroom = "卧室";
	string m_bedroom;
};

GoodGay2::GoodGay2()
{
	building3 = new Building3;  //虽然之前声明了class Building3;，告知有这一类，但是并不知道有什么成员，所以new Building3是非法的，不知道有什么怎么在堆区创建这个对象呢
}
Building3::Building3()
{
	m_livingroom = "客厅";
	m_bedroom = "卧室";
}
void GoodGay2::visit() //成员函数做友元：同样是成员函数，visit2就不能访问
{
	cout << building3->m_livingroom << endl;
	cout << building3->m_bedroom << endl;
}
void GoodGay2::visit2()
{
	cout << building3->m_livingroom << endl;
	//cout << building3->m_bedroom << endl;  //不是友元（成员函数的），不能访问私有变量
}

void test03() 
{
	GoodGay2 gg;
	gg.visit();
	gg.visit2();
}

//加号运算符重载
class Person 
{
public:
	int m_A;
	int m_B;

	//成员函数运算符重载
	//Person PersonAddPerson(Person &p)  //本质定义-也可实现相加，但不是运算符重载。成员函数运算符重载就是要用operator+替换成员函数名
	//Person operator+(Person& p)   //运算符重载定义，可以直接用加号
	//{
	//	Person temp; //定义一个类变量，会在栈区分配其内存生成对象；定义一个类指针变量，不会生成一个对象，只是生成了一个可以指向类对象的指针，还需要指向一个已经存在的对象或在堆区开辟内存新建对象
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}
	////运算符重载+函数重载
	//Person operator+(int b)   //运算符重载定义，可以直接用加号
	//{
	//	Person temp; //定义一个类变量，会在栈区分配其内存生成对象；定义一个类指针变量，不会生成一个对象，只是生成了一个可以指向类对象的指针，还需要指向一个已经存在的对象或在堆区开辟内存新建对象
	//	temp.m_A = this->m_A + b;
	//	temp.m_B = this->m_B + b;
	//	return temp;
	//}
};

	//全局函数运算符重载
	//Person PersonAddPerson(Person& p1, Person& p2)  // 本质定义，下面替换函数名即可实现运算符重载
Person operator+(Person &p1,Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
	//运算符重载+函数重载
Person operator+(Person& p1, int b)
{
	Person temp;
	temp.m_A = p1.m_A + b;
	temp.m_B = p1.m_B + b;
	return temp;
}

void test04() 
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//Person p3 = p1.PersonAddPerson(p2);  //本质定义（成员函数），使用成员函数运算符重载后可以直接用+
	//Person p3 = PersonAddPerson(p1, p2); //本质定义（全局函数）
	Person p3 = p1 + p2;

	cout << p3.m_A << endl;
	cout << p3.m_B << endl;

	//运算符重载也可以与函数重载结合，实现一个运算符多种运算
	Person p4 = p2 + 100;

	cout << p4.m_A << endl;
	cout << p4.m_B << endl;
}

//左移运算符重载
class Mean 
{
	friend ostream& operator<<(ostream& cout, Mean& m);  // 友元（全局函数），用来在该全局函数中访问私有变量
private:
	int m_a;
	int m_b;
public:
	void add_value(int a,int b) 
	{
		m_a = a;
		m_b = b;
	}
};
	//左移运算符只能使用全局函数重载。因为cout类和输出对象m的关系只能是cout在左m在右，而成员函数需要m.成员函数名(cout),顺序是m在左cout在右
ostream& operator<<(ostream & cout,Mean &m) // cout是ostream类中的，使用引用来定义，指向原对象cout 
{
	cout << m.m_a << m.m_b << endl;
	return cout;  //返回该类，可以在使用左移重载运算符时在后面加endl等。即test05中使用重载cout，后面可以接着加cout，链式思维
}
void test05() 
{
	Mean m;
	m.add_value(10, 20);
	cout << m << endl;  //可以重载了
}

//++运算符重载
class addadd 
{
	friend ostream& operator<<(ostream & cout, addadd a);
private:
	int m_a = 10;
public: //++重载可以使用成员函数也可以使用全局函数
	addadd & operator++()  //++a 
	{
		m_a++;
		return *this;  //返回当前对象，其中m_a已经加过了
	};
	addadd operator++(int) //a++，前置后置两个不同，1.返回的不能是指针，因为要返回保存的上一步值，指针又变成返回加后的值了 2.需要int，是占位符，用于函数重载，且只能是int，用于后置，还可以int=10，为形参默认值
	{
		addadd temp; // 记录当前值
		temp = *this;  //*this是this的类，是值而不是指针
		m_a++;  //加
		return temp;  //返回未加之前的对象
	}
};
ostream& operator<<(ostream & cout, addadd a)   //如果此处定义的是addadd &a，则它就是一个指向a对象的指针，那么后置返回的是temp局部对象，使用重载左移运算符会报错，因为传入重载<<的不是a
{
	cout << a.m_a << endl;
	return cout;
}
void test06() 
{
	addadd a;
	cout << ++a << endl;
	cout << a++ << endl;
	cout << a << endl;
}

//--运算符重载
class reduce 
{
	friend ostream& operator<<(ostream& cout, reduce a);
private:
	int m_b = 10;
public:
	reduce& operator--()   //前置重载（成员函数）。并且由于返回的是this的解引用，this是指针常数，所以定义函数类型应该为引用而不能是指针
	{
		m_b--;
		return *this;
	}
	reduce operator--(int) //后置重载（成员函数）
	{
		reduce temp;
		temp = *this;
		m_b--;
		return temp;
	}
};
ostream& operator<<(ostream &cout,reduce a)  //左移重载（只能是全局函数）。并且函数也定义为引用类型（而且返回的是cout对象，为值类型，而不是cout指针。引用方法直接输入变量名就是值的意思，而非像指针需要*才是值）
{
	cout << a.m_b << endl;
	return cout;  //引用类型的函数返回值就是值，而非指针类型的函数返回值是指针。引用类型函数返回值的值，可以直接赋给main函数定义的新引用，正好引用的定义必须是传递变量，而不能是直接定义一个数给引用，除非使用const int &这种常数引用（常数指针常数）
}
void test07()
{
	reduce b;
	cout << --b << endl;
	cout << b-- << endl;
	cout << b << endl;
}

//赋值运算符重载
class give 
{
public:
	int * m_a;
	give(int p) 
	{
		m_a = new int(p);
	}
	~give() //析构函数
	{
		if (this->m_a!=NULL)
		{
			delete m_a;
			m_a = NULL; //防止野指针
		}
	}
	give & operator=(give &p) 
	{
		//编译器默认浅拷贝
		//m_a = p.m_a;

		//深拷贝：应该先判断本对象是否有堆区内存，有的话释放
		if (m_a!=NULL)
		{
			delete m_a;
			m_a = NULL;
		}
		m_a = new int(*p.m_a);  //引用不是别名吗？为什么要解引用？哦，引用是别名，p就表示传进来的对象别名，但这个对象的属性m_a是一个指针，所以读取该属性还需要解引用

		return *this;  //返回自身对象，可以多个赋值
	}
};

void test08() 
{
	give g(10);
	cout << "g的年龄为：" << *g.m_a << endl;
	give g2(12);  //如果不定义赋值函数，为一个浅拷贝，定义了析构函数后，会报错，因为析构的都是同一块内存
	cout << "g2的年龄为：" << *g2.m_a << endl;
	give g3(18);
	g3 = g2 = g;  //多个赋值
	cout << "g3的年龄为：" << *g3.m_a << endl;
}

//重载关系运算符
class MOON 
{
public:
	string m_Name;
	int m_Age;
	MOON(string n, int a) 
	{
		m_Name = n;
		m_Age = a;
	}
	bool operator==(MOON &p) //==  //引用传递和返回的都是值，相当于用引用指向该值起个别名（引用为一个常量指针，不能改指向，可以改值）；指针传递和返回的都是地址，相当于用另一个指针指向该地址
	{
		if ((this->m_Age == p.m_Age) && (this->m_Name == p.m_Name)) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	bool operator!=(MOON& p) //!=
	{
		if ((this->m_Age == p.m_Age) && (this->m_Name == p.m_Name))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

void test09() 
{
	MOON m1("Tom", 18);
	MOON m2("Jerry", 8);
	MOON m3(m1);
	if (m1 == m2) 
	{
		cout << "是相同的" << endl;
	}
	else 
	{
		cout << "不是相同的" << endl;
	}
	if (m1 != m3)
	{
		cout << "不是相同的" << endl;
	}
	else
	{
		cout << "是相同的" << endl;
	}
}

//函数调用运算符重载
class myprint 
{
public:
	void operator()(string a) //函数调用运算符重载
	{
		cout << a << endl;
	}
};

void defprint(string m) //函数
{
	cout << m << endl;
}

class myadd 
{
public:
	int operator()(int a, int b) //函数调用运算符重载实现相加(很灵活，函数调用运算符重载可以实现多种功能)。仿函数这种概念会在后面的STL中经常出现
	{
		int c = a + b;
		return c;
	}
};

void test10() 
{
	myprint m;
	m("函数调用运算符重载");  //函数调用运算符重载，因为使用方法类似于函数使用，所以又叫仿函数
	defprint("函数");//函数使用，用于函数中。上面是函数调用运算符使用，用于一个类中

	myadd m2;
	int sum = m2(11, 10);
	cout << "和为：" << sum << endl;
}

int main() 
{
	// 友元：可以访问一个类的私有域内的成员     1.全局函数做友元 2.类做友元 3.成员函数做友元
	//1.全局函数做友元
	//test01();

	//2.类做友元：友元类
	//test02();

	//3.成员函数做友元
	//test03();

	//运算符重载（加号） :1.成员函数运算符重载 2.全局函数运算符重载 3.运算符重载可以结合函数重载
	//运算符重载用于自定义数据结构之间的运算，比如加减乘除，编译器默认是不知道的，需要用户自定义
	//test04();

	//左移运算符重载
	//test05();

	//++或--运算符重载
	//test06();
	//test07();

	//赋值运算符重载：因为编译器提供的赋值运算符是一个浅拷贝，如果对象内包含指针指向堆区，会析构两个堆区内存
	//test08();

	//重载关系运算符：==与!=、>、<等运算符
	//test09();

	//重载函数调用运算符：()
	test10();

	system("pause");
	return 0;
}