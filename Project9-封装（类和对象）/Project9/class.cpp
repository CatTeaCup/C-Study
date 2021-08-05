#include<iostream>
#include<string>
#include<cmath>
#include"point.h"
#include"circle.h"
using namespace std;

class Student 
{
// 类中的属性行为统称为 成员
// 属性称为 成员属性 成员变量
// 方法称为 成员方法 成员函数
public:
	string name;
	int ID;

	void Show() 
	{
		cout << "学生的姓名是：" << name << endl;
		cout << "学生的学号是：" << ID << endl;
	}

	void setname(string set_name) 
	{
		name = set_name;
	}
};

// public：公共权限，类内可访问，类外可访问
// protected：保护权限，类内可访问，类外不可访问。继承子类可使用父类
// private：私有属性，类内可访问，类外不可访问。继承子类不可使用父类

class Person 
{
public:
	string name = "李四";
protected:
	int IDcard = 54321;
private:
	string car = "奔驰";
public:
	void give_value() 
	{
		name = "张三";
		IDcard = 12345;
		car = "拖拉机";
	}

	void Show()
	{
		cout << "姓名是：" << name << endl;
		cout << "银行卡号是：" << IDcard << endl;
		cout << "车型是：" << car << endl;
	}
};

// struct结构体和class类都可以创建类，其中struct默认权限是public，class默认权限是private

class Clock 
{
private:
	string name;  // 可读可写
	string lover;  // 只写
	int age = 10;  // 只读

public:
	void write_name(string writename) 
	{
		name = writename;
	}
	string read_name() 
	{
		return name;
	}

	void write_lover(string writelover)
	{
		lover = writelover;
	}

	int read_age() 
	{
		return age;
	}
};


class Cube 
{
private:
	int c_h;
	int c_w;
	int c_l;

public:
	void set_h(int h) 
	{
		c_h = h;
	}
	void set_w(int w)
	{
		c_w = w;
	}
	void set_l(int l)
	{
		c_l = l;
	}
	int get_h() 
	{
		return c_h;
	}
	int get_w()
	{
		return c_w;
	}
	int get_l()
	{
		return c_l;
	}
	int calcuate_s() 
	{
		int s;
		s = c_h * c_w * 2 + c_h * c_l * 2 + c_l * c_w * 2;
		return s;
	}
	int calcuate_v()
	{
		int v;
		v = c_h * c_w * c_l;
		return v;
	}
	bool Choose(Cube &c) 
	{
		if (c.get_h() == c_h && c.get_l() == c_l && c.get_w() == c_w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool Choose(Cube &c1,Cube &c2) 
{
	if (c1.get_h() == c2.get_h() && c1.get_l() == c2.get_l() && c1.get_w() == c2.get_w()) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//点和圆
//class Point  //分文件编写
//{
//private:
//	int p_x;
//	int p_y;
//public:
//	void set_x(int x) 
//	{
//		p_x = x;
//	}
//	int get_x() 
//	{
//		return p_x;
//	}
//	void set_y(int y) 
//	{
//		p_y = y;
//	}
//	int get_y() 
//	{
//		return p_y;
//	}
//};

//class Circle  //分文件编写
//{
//private:
//	int c_r;
//	Point c_p;
//public:
//	void set_r(int r) 
//	{
//		c_r = r;
//	}
//	int get_r() 
//	{
//		return c_r;
//	}
//	void set_p(Point p) 
//	{
//		c_p = p;
//	}
//	Point get_p() 
//	{
//		return c_p;
//	}
//};

void is_in_or_out(Point& p, Circle& c) 
{
	if (pow(c.get_p().get_x()-p.get_x(),2) + pow(c.get_p().get_y()-p.get_y(),2) == pow(c.get_r(),2)) 
	{
		cout << "点在圆上" << endl;
	}
	else if(pow(c.get_p().get_x() - p.get_x(), 2) + pow(c.get_p().get_y() - p.get_y(), 2) > pow(c.get_r(), 2))
	{
		cout << "点在圆外" << endl;
	}
	else 
	{
		cout << "点在圆内" << endl;
	}
}

int main() 
{
	//// 设计学生类
	//class Student student;
	//student.ID = 2020110040;
	//student.name = "黄";
	//student.Show();
	//student.setname("武");
	//student.Show();

	//// 访问权限
	//class Person person;
	////person.name = "魏五";
	////person.IDcard = 12345;  //protected不可访问
	////person.car = "拖拉机";  //private不可访问
	//person.Show();
	//person.give_value();
	//person.Show();

	// struct与class

	// 私有属性的好处
	/*Clock clock;
	clock.write_name("张三");
	cout<< "姓名是：" << clock.read_name() << endl;
	clock.write_lover("李四");
	cout << "年龄是：" << clock.read_age() << endl;*/

	// 实际案例，立方体
	//Cube cube;
	//cube.set_h(5);
	//cube.set_l(6);
	//cube.set_w(5);
	//cout << "立方体面积：" << cube.calcuate_s() << endl;
	//cout << "立方体体积：" << cube.calcuate_v() << endl;
	//Cube cube2;
	//cube2.set_h(5);
	//cube2.set_l(6);
	//cube2.set_w(6);

	//bool ret = Choose(cube, cube2); // 全局函数判断
	//if (ret) 
	//{
	//	cout << "两个立方体相同" << endl;
	//}
	//else
	//{
	//	cout << "两个立方体不同" << endl;
	//}
	//bool ret2 = cube.Choose(cube2);  //成员函数判断
	//if (ret2)
	//{
	//	cout << "两个立方体相同" << endl;
	//}
	//else
	//{
	//	cout << "两个立方体不同" << endl;
	//}

	//实际案例：点和圆
	Point p;
	p.set_x(10);
	p.set_y(10);
	Circle c;
	Point c_p;
	c_p.set_x(10);
	c_p.set_y(0);
	c.set_p(c_p);
	c.set_r(10);
	is_in_or_out(p, c);


	system("pause");
	return 0;
}