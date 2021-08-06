# include<iostream>
#include<string>
using namespace std;

//构造函数与析构函数
class Person 
{
public:
	Person() 
	{
		cout << "Person的构造函数" << endl;
	}
	~Person() 
	{
		cout << "Person的析构函数" << endl;
	}
};

void test01() 
{
	Person p;
}

//构造函数的分类与调用
class Utool 
{
private:
	int u_a;
public:
	Utool() 
	{
		cout << "默认构造" << endl;
	}
	Utool(int a) 
	{
		u_a = a;
		cout << "有参构造:" << u_a << endl;
	}
	Utool(const Utool &b) //注意拷贝构造的形式
	{
		u_a = b.u_a;
		cout << "拷贝构造:" << u_a << endl;
	}
};

void test02() 
{
	//括号法
	Utool u1;
	Utool u2(10);
	Utool u3(u2);

	//显式构造
	Utool u4;
	Utool u5 = Utool(10);
	Utool u6 = Utool(u5);
	//Utool(10)单独写就是匿名对象，当前行结束后马上析构

	//隐式转换法
	Utool u7 = 10;
	Utool u8 = u7;
}

class Kaobeigouzao 
{
public:
	int age;
};

//深拷贝与浅拷贝

class Panzer 
{
private:
	int age;
	int* height;
public:
	Panzer() 
	{
		cout << "无参构造函数" << endl;
	}
	Panzer(int ag,int hei) 
	{
		cout << "有参构造函数" << endl;
		age = ag;
		height = new int(hei); //new 后返回的是指针，正好对应height，传进来的hei是值，用来给堆区内存赋值

	}
	~Panzer() 
	{
		cout << "自定义析构函数" << endl;
		if (height != NULL) // 如果指针不为空 
		{
			delete height;
			height = NULL;  //防止野指针出现
		}
	}
	Panzer(const Panzer &p) //拷贝构造形式：为const引用，意为用p指向原对象的地址
	{
		age = p.age;  //新对象赋值为原对象的值
		//height = p.height;  //计算机默认定义的语句，为浅拷贝
		height = new int(*p.height);  //定义堆区内存存储原对象的值用作新对象的值存储位置，深拷贝。p是引用，是指针常量，而p.height也不是值而是地址，需要*
	}
	void printPanzer() 
	{
		cout << "年龄为："<< age << "身高为：" << *height <<endl;  //height为指针
	}
};

void test03() 
{
	Panzer p1(2,160);  // 属性为private不能直接赋值，而又没有定义public域的赋值函数，只有有参构造
	p1.printPanzer();  //public定义的输出函数
	Panzer p2(p1);
	p2.printPanzer();
}

//初始化列表
class List 
{
private:
	int a;
	int b;
public:
	//List(int aa, int bb) //有参构造:使用构造来初始化
	//{
	//	a = aa;
	//	b = bb;
	//}
	List(int aa, int bb):a(aa),b(bb)  //初始化列表，相对于有参构造的好处是书写简洁，并且少了一步拷贝
	{
	}
	void printfList()
	{
		cout << "使用构造来初始化：" << "a的值为："<< a << "b的值为：" << b <<endl;
	}

};

void test04() 
{
	List l1(10,20);
	l1.printfList();
}

// 在一个类中定义另一个类
class Phone 
{
private:
	string phone_name;
public:
	Phone(string a) //有参构造
	{
		phone_name = a;
		cout << "Phone的构造函数" << endl;
	}
	~Phone() 
	{
		cout << "Phone的析构函数" << endl;
	}
	string getfPhone()
	{
		return phone_name;
	}
};

class Person_c 
{
private:
	string name;
	Phone phone;
public:
	Person_c(string a, string b) :name(a), phone(b)   //初始化列表。phone为一个phone类，而其中包含一个字符串属性，所以可以直接把字符串b赋给它
	{
		cout << "Person_c的构造函数" << endl;
	}
	~Person_c() 
	{
		cout << "Person_c的析构函数" << endl;
	}
	void printfPerson() 
	{
		cout << "姓名："<< name <<"手机：" << phone.getfPhone() << endl;
	}
};

void test05() 
{
	Person_c c("张三", "iphone");
	c.printfPerson();
}

//静态成员变量：①   1.类内定义类外赋值 2.所有对象访问同一块内存 3.程序未执行的时候就分配内存
class OOK 
{
public:
	static int a; //静态成员三个性质：1.所有对象访问同一块内存（即静态变量类似于类的属性而非对象的属性）2.在编译阶段就分配内存（程序未执行就分配内存）3.类内定义类外赋值
private:
	static int b; //静态成员变量也有权限限制
};
int OOK::a = 10; //3.类外赋值（int a，在中间加上类定义OOK::）
int OOK::b = 20; // 由于私有属性，b可以赋值类外初始化，但是不能进行别的函数内访问
//int OOK::a = 10;

void test06() 
{
	OOK o;
	cout << "原对象静态成员的值：" << o.a << endl;
	OOK o2;
	o2.a = 20;  //1.
	cout << "另一个对象修改静态成员变量后原对象的静态成员值：" << o.a << endl;  //类中可以定义静态成员变量static int（or），然后可以通过类构造两个对象，其中一个对象的静态属性修改后，另一个对象的该属性也改变，这是因为所有静态成员访问同一块内存空间
}
//②   静态属性不属于对象，而是类似于类的属性，静态成员变量除了可以通过对象访问，还可以通过类名访问OOK::a

void test07() 
{
	//静态成员变量不属于某一个对象，而是类的属性
	//所以访问静态成员变量有两种方式：1.通过对象访问 2.通过类名访问
	//通过对象访问
	OOK o;
	cout << "通过对象进行访问：" << o.a << endl;
	cout << "通过类名进行访问：" << OOK::a << endl;
}

//静态成员函数：③   静态函数只能访问静态属性，因为它不知道该属性属于哪个对象，只知道属性属于一个类，所以只能访问类的属性
class PWM 
{
public:
	static void static_func() 
	{
		cout << "静态成员函数输出" << endl;
	}
	static void static_func2() 
	{
		cout<<"静态函数输出静态变量："<< b <<endl;
		//cout<<"静态函数输出变量："<< a <<endl;  //会报错，因为静态成员函数只能访问静态成员变量，不能访问普通变量，由于静态函数的属性其不知道该变量属于哪个对象
	}
private:
	int a = 50;
	static int b;  //静态成员变量，不能直接=40，需要类外赋值
};
int PWM::b = 40;

//④   静态函数也类似于静态属性，可以通过对象和类名两种方式访问
void test08() 
{
	//静态成员函数有两个属性：1.可以通过对象进行访问，也可以通过类名进行访问(访问同一块内存) 2.静态成员函数内只能访问静态成员变量（因为静态成员函数也不属于某一个对象，而是一整个类，如果里面不是静态成员变量（也作用于一个类），访问不知道访问哪个对象的成员属性）
	//通过对象进行访问
	PWM p;
	cout << "通过对象访问静态函数："  <<endl;
	p.static_func();
	//通过类名进行访问
	cout << "通过类名访问静态函数：" << endl;
	PWM::static_func();

	//静态函数访问静态变量
	PWM::static_func2();
}

//成员变量与成员函数分开存储
class Value 
{
public:
	int a = 10;
	static int b;
	void func() {}
	static void func2(){}
};
int Value::b = 10;

void test09() 
{
	Value v;
	cout << "size of:" << sizeof(v) << endl;
}

//this指针
class This 
{
public:
	This(int age) 
	{
		//age = age;  //1.不用this的话，左值age不会指向类成员变量age，而是会被认为是形参。所以需要this将左age链接到后面建立对象t1中的age，并对其赋右age的值
		this->age = age;
	}
	int get_age() 
	{
		cout << "age为：" << age << endl;
		return age;
	}
	This& add_func(This &p) 
	{
		this->age += p.get_age();
		return *this; //2.返回对象本身，即返回值为后续的t2对象。引用在定义时需要使用&，但是在传输过程中传输的是值，即&a相当于一个引用，传输时只传输a，所以这里也同理，
		//this为一个指针，由于函数是This&类型的，所以传输过程中应该取*this(这里之所以不清楚是因为是&与*的混用，只要记住指针定义*，*a表示值，传输无*传输指针；引用定义&，
		//a表示值，传输无&传输值)，所以这里遵循引用的方式，传输值，传输*this，传输的是this指向的This类（this表示指向类的指针，this->age表示age，*this表示类，*this.age
		//表示age；->和.都可以访问类成员，但是->表示类指针，.表示类，两者不是一个级别；->的左值比.的左值高一个级别--this和*this的区别）。所以This类后面可以继续.访问类成员（后面的t1与t2）

		//此函数类似于拷贝构造函数，所以定义的形参为类类型，所以也需定义一个指针，&b。（指针=地址，不等于值，指针相当于存了地址的一块内存，硬件原理与存了值的内存一样，但指针指向一个值）
		//（p是指针，*p是值，&b是指针，b是值；*p的*只有在定义时、和取值时能用到，&b的&只有定义时能用到）
		//（&在定义时代表引用，包括定义变量、定义函数、定义对象（也是一种变量）等等情况；&在非定义时代表取地址）
	}
private:
	int age;
};

void test10() 
{
	This t1(18);
	cout << "t1的age为：" << t1.get_age() << endl;

	This t2(18);
	t2.add_func(t1).add_func(t1).add_func(t1); //t2.add_func(t1)令t2对象的age加上了t1对象的age，并返回t2对象，然后t2.add_func(t1).add_func(t1)相当于加了age后的新t2再调用add_func
	//这种思维叫做链式思维，下面的cout也是这样的原理，可以不断向后加
	//如果add_func定义时不是定义的指针类型（*或&），而是值类型，This，那么这一句最后输出的是36。因为相当于拷贝了一个值进行返回，注意这里的值不只是能指一个数字
	//值也可以是一个对象，即拷贝了相同的一个对象返回，那么t2.add_func(t1)后返回的相当于是一个新对象，t2'，再往后就是新的t2''，所以一直为18+18
	cout << "t2的age为：" << t2.get_age() << endl;
}

//空指针访问成员函数：结合test11一起看，C++允许使用空指针访问成员函数，但是不能使用this，即空指针不能通过成员函数访问成员属性
class Null 
{
public:
	int m_A;
	void aaa() 
	{
		cout << "没有访问任何成员 的 函数" << endl;  //没有访问m_A
	}
	void bbb() 
	{
		//改进bbb
		if (this == NULL)   //一定是指针为空，而不能是指向的值为空this->m_A == NULL
		{
			return ;  //增加了代码的健壮性
		}
		cout << "访问了成员（变量）的函数" << m_A <<endl;  //访问了m_A
	}
};

void test11()
{
	Null * n1 = NULL; // Null n1 = NULL;不行，因为除了拷贝构造，没有直接给对象赋值的；Null& n1 = NULL;也不行，因为&引用的右边一定是个变量、对象的地址而非值
	n1->aaa(); // 不会报错
	n1->bbb(); // 报错，报错的原因是n1本身就是一个空对象，那么在类内调用m_A时其实编译器默认是this->m_A，指向每一个对象的，空对象根本没有m_A，怎么调用呢。所以返回bbb改进
}

//常函数与常对象（类的）:const定义常量属性与常量函数，但是常量函数要放在后面；而常量函数是没办法修改属性的，除非使用mutable来使得属性可以被修改
class MNIST 
{
public:
	int m_a;
	mutable int m_b;
	void func() 
	{
		this->m_a = 10;  //可以修改值。this指针相当于一个指针常量，指向每一个对象。等于MNIST * const this
		//this = NULL;  //不能修改指针指向：指针常量
	}
	void const_func() const //常量函数。 const常量函数中的const相当于修饰this，等于const MNIST * const this，从原来的不能修改指向变为了即不能修改值也不能修改指向
	{
		//this->m_a = 10; //不能修改值了。变为既不能修改值也不能修改指向
		this->m_b = 10;  // 当使用mutable来定义m_b时，就可以在常量函数中用this指针修改m_b的值了
		cout << "常函数与常对象+破这两个的：mutable" << endl;
	}
};

void test12() 
{
	MNIST m1; // 普通对象
	const MNIST m2;  // 常对象
	//m2.m_a = 10; // 无法修改常对象的属性，和常函数一样，该常对象的所有属性为只读的
	m2.m_b = 10; // 当加了mutable后，可以修改，变为可写的了

	//m2.func(); //常对象不可以调用普通函数
	m2.const_func(); //常对象可以调用常函数
}

int main() 
{
	//构造函数与析构函数：类似于手机的初始化与清除空间，构造函数用于初始化每个类生成的对象，析构函数用来删除销毁对象后的空间
	//构造函数：类名(){}   析构函数：~类名(){}       都不用定义类型
	//test01();  // 调用函数生成类会执行构造函数与析构函数，因为函数中定义的为一个局部变量，函数执行完会清空对象
	//Person p;  // 而主函数中定义局部变量，要等到主函数退出后才会执行析构函数，所以窗口只会出现构造函数的作用


	//构造函数 的 分类 与 调用
	//分类可以分为：构造与拷贝构造---构造又可以分为默认构造与有参构造，所以一共有三种：默认构造（无参构造）、有参构造、拷贝构造
	//调用可以分为：括号法、显式法、隐式转换法
	//test02();


	//拷贝构造函数：直接传值时会调用、值传递（函数，非地址传递）时会调用、函数返回值时会调用（并且构造函数是类中独有的概念，所以传递的都是类）

	
	//默认情况下，C++至少给一个类添加三个函数：默认构造函数（无参，函数体为空）、析构函数（无参，函数体为空）、拷贝构造函数（属性做值拷贝）
	//Kaobeigouzao k;
	//k.age = 18;
	//Kaobeigouzao k2(k);  // 拷贝构造
	//cout << "原对象值：" << k.age << endl;
	//cout << "拷贝构造的值" << k2.age << endl;
	//构造规则：1.用户构造了有参构造，系统不会自动构建无参构造，但会自动构建拷贝构造
	//2.用户构造了拷贝构造，系统不会自动构造无参与有参构造

	//深拷贝与浅拷贝
	//深拷贝就是拷贝到堆区，浅拷贝就是寻常拷贝。浅拷贝会遇到析构函数重复释放的问题，即类中定义指针类型的时候，浅拷贝会同样拷贝该指针，并且该指针在有参构造函数中指向一个堆区，
	//那么拷贝构造时就会两个指针都指向同一个堆区，然后在函数运行完（包含原对象与拷贝对象）就会进行析构（析构函数也需要自定义，用来释放堆区内存），定义的析构会析构两个指针，
	//那么第二个的时候就遇到了问题，元对象已经析构过了这个堆区内存，拷贝对象再析构就报错，所以需要深拷贝，深拷贝可以在拷贝对象时创建一个堆区内存，不会指向同一块堆区内存
	//1.析构函数有用：在类定义的指针在有参构造中指向堆区内存时，需要析构函数来释放
	//2.同时，如果使用了拷贝构造函数来构造对象，需要使用深拷贝而不是浅拷贝来复制一块堆区内存
	//test03();

	//初始化列表：用来初始化对象的属性值
	//test04();

	//类对象作为类成员（一个类中用另一个类，先构造哪个，先析构哪个）
	//test05(); //构造时先构造Phone，再构造Person（引用了Phone作为类成员），析构时相反

	//类的 静态成员 变量+函数
	//静态成员变量：1.2.3. + 有一个访问权限
	/*test06();
	test07();*/

	//静态成员函数：1.2. + 同静态变量一样，有一个访问权限，私有域下定义的静态函数不能访问
	//test08();

	//成员变量 和 成员函数 是分开存储的。在一个对象里，只有成员变量是存储在该对象内的，静态成员变量、成员函数、静态成员函数都不存在对象里
	//test09();

	//this指针：1.当形参和成员变量同名时，可以通过this指向调用该类中函数的对象 2.返回对象本身（可以使用链式思维进行编程了：不断调用函数）
	//test10();  //一句话总结就是，this指向调用该类内东西的对象（实际上这么想对象就是类，结构都相同，只不过把类实例化了，所以this定义在类内在实例化后就指向该对象）

	//空指针访问成员函数
	//test11();  //类这种，一定是指针=NULL，而不会是指向的值=NULL，NULL是和指针一个量级的

	//常函数 与 常对象（const修饰的，只读）：1.常函数相当于const修饰this指针 2.常函数：mutable可以将const的只读状态变为可写（修改值） 3.常对象只能调用常函数
	test12();


	system("pause");
	return 0;
}