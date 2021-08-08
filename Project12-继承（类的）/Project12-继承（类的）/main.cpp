#include<iostream>
using namespace std;

//class Java 
//{
//public:
//	void header() 
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer() 
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left() 
//	{
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void content() 
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};

//继承
class Father 
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...（公共分类列表）" << endl;
	}
};
	//继承 基本语法- class 子类:继承方式 父类
	//子类 也叫 派生类
	//父类 也叫 基类
class Java :public Father 
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

class Python :public Father 
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

class CPP :public Father 
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

void test01() 
{
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "--------------------------------------------" << endl;

	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "--------------------------------------------" << endl;

	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}

//继承方式
class GrandFather 
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Father02:private GrandFather 
{
public:
	void read() 
	{
		m_a = 10;  //m_a和m_b在父类中分别是public与protected，在子类中都是private，在子类内可以访问
		m_b = 12;
		cout << m_a << endl << m_b << endl;
	}
};

class Son :public Father02 
{
public:
	void read() 
	{
		/*m_a = 12;
		m_b = 10;*/  //即使孙类以public继承，还是无法继承到，因为这两个在子类上就被继承为private，子类的子类无法继承
	}
};

void test02() 
{
	Father02 f;
	f.read();
}

//继承中的对象模型
class User 
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son_03 :public User 
{
public:
	int m_d;
};

void test03() 
{
	Son_03 s;
	cout << sizeof(s) << endl; //说明即使子类不能访问父类的所有属性（私有），但是子类是继承了所有父类属性的，包括父类的private
	//利用开发人员命令提示符工具查看对象模型
	//跳转盘符：D:
	//跳转文件路径 cd 具体路径下
	//查看命名
	//cl / dl reportSingleClassLayout类名 文件名   （报告单个类的布局）
}

//继承的构造与析构
class Base
{
public:
	Base() 
	{
		cout << "父类的构造函数" << endl;
	}
	~Base() 
	{
		cout << "父类的析构函数" << endl;
	}
};

class Son_04 :public Base 
{
public:
	Son_04() 
	{
		cout << "子类的构造函数" << endl;
	}
	~Son_04() 
	{
		cout << "子类的析构函数" << endl;
	}
};

void test04() 
{
	Base b;
	Son_04 s;
}

//继承的同名对象处理
class BASE 
{
public:
	int m_a = 10;
	void father() 
	{
		cout << "父类成员函数" << endl;
	}
	void father(int a)
	{
		cout << "父类成员函数 int a" << endl;
	}
};

class SON :public BASE 
{
public:
	int m_a = 100;
	void father()
	{
		cout << "子类成员函数" << endl;
	}
};

void test05() 
{
	SON S;
	cout << S.m_a << endl;  //子类属性
	cout << S.BASE::m_a << endl;  //父类属性
	S.father();  //子类函数
	S.BASE::father();  //父类函数
	S.BASE::father(10);  //父类重载函数
}

//继承的静态同名对象处理
class BASE1 
{
public:
	static int m_a;
	static void father() 
	{
		cout << "父类成员函数" << endl;
	}
	static void father(int a)
	{
		cout << "父类成员函数 int a" << endl;
	}
};
int BASE1::m_a = 10;  //静态变量类内声明，类外初始化 

class SON1:public BASE1 
{
public:
	static int m_a;
	static void father()
	{
		cout << "子类成员函数" << endl;
	}
};
int SON1::m_a = 100;

void test06() 
{
	SON1 s;
	cout << s.m_a << endl;  //静态变量通过对象访问
	cout << s.BASE1::m_a << endl;
	cout << SON1::m_a << endl;  //静态变量通过类名访问
	cout << SON1::BASE1::m_a << endl;

	s.father(); //静态函数通过对象访问
	s.BASE1::father();
	s.BASE1::father(10);
	SON1::father();  //静态函数通过类名访问
	SON1::BASE1::father();
	SON1::BASE1::father(10);
}

//多继承
class BASE2 
{
public:
	int m_a = 100;
};

class BASE3 
{
public:
	int m_a = 200;
};

class SON2 :public BASE2,public BASE3  //多继承
{
public:
	int m_b;
	int m_c;
};

void test07() 
{
	SON2 s;
	cout << s.BASE2::m_a << endl;  //多继承二义性解决
	cout << s.BASE3::m_a << endl;  //多继承二义性解决
}

//菱形继承
class Animal 
{
public:
	int m_age;
};

class Sheep :virtual public Animal {}; // vbptr，虚基类指针，指向虚基类表。即继承的是一个指针，该指针指向Animal的属性。无论是Sheep、Tuo、SheepTuo都共享一个m_age

class Tuo :virtual public Animal {};  //在底层上，如果虚基类表中Sheep地址是0，Tuo地址是4，Animal地址是8，则Sheep的vbptr偏移量为8，指向8，Tuo地址是4，偏移量为4，指向8

class SheepTuo :public Sheep, public Tuo {};

void test08()
{
	SheepTuo st; //不使用虚基类指针，st大小为8，继承两个m_age。使用虚基类指针，st大小为12，两个vbptr（Sheep及Tuo）以及一个m_age（Animal）
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;
	cout << st.Sheep::m_age << endl; //虽然可以使用域名访问两个同名属性
	cout << st.Tuo::m_age << endl; //
	cout << st.m_age << endl; //但是st继承了两个m_age,没法弄了，只能用vbptr
}

int main() 
{
	//继承 基本语法- class 子类:继承方式 父类 
	//test01();

	//继承方式 公共继承public 保护继承protected 私有继承private
	//父类中含有 public、protected、private三种域
	//公共继承：（父类->子类）public->public   protected->protected   private->不能继承
	//保护继承：public、protected->protected   private->不能继承
	//私有继承：public、protected->private     private->不能继承
	//protected与private之间的区别是：protected可以被继承、private不能被继承
	//test02();

	//继承中的对象模型
	//test03();

	//继承的构造与析构
	test04();

	//继承的同名对象处理(属性  与  函数)
	test05();

	//继承的静态同名对象处理（属性  与  函数）
	test06();  //静态同名对象 与 同名对象 的处理方式完全一样，只不过静态对象除了对象访问还可以通过类名进行访问

	//多继承
	//test07();

	//菱形继承:虚基类指针、虚基类表
	test08();

	system("pause");
	return 0;
}