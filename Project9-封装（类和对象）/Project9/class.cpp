#include<iostream>
#include<string>
#include<cmath>
#include"point.h"
#include"circle.h"
using namespace std;

class Student 
{
// ���е�������Ϊͳ��Ϊ ��Ա
// ���Գ�Ϊ ��Ա���� ��Ա����
// ������Ϊ ��Ա���� ��Ա����
public:
	string name;
	int ID;

	void Show() 
	{
		cout << "ѧ���������ǣ�" << name << endl;
		cout << "ѧ����ѧ���ǣ�" << ID << endl;
	}

	void setname(string set_name) 
	{
		name = set_name;
	}
};

// public������Ȩ�ޣ����ڿɷ��ʣ�����ɷ���
// protected������Ȩ�ޣ����ڿɷ��ʣ����ⲻ�ɷ��ʡ��̳������ʹ�ø���
// private��˽�����ԣ����ڿɷ��ʣ����ⲻ�ɷ��ʡ��̳����಻��ʹ�ø���

class Person 
{
public:
	string name = "����";
protected:
	int IDcard = 54321;
private:
	string car = "����";
public:
	void give_value() 
	{
		name = "����";
		IDcard = 12345;
		car = "������";
	}

	void Show()
	{
		cout << "�����ǣ�" << name << endl;
		cout << "���п����ǣ�" << IDcard << endl;
		cout << "�����ǣ�" << car << endl;
	}
};

// struct�ṹ���class�඼���Դ����࣬����structĬ��Ȩ����public��classĬ��Ȩ����private

class Clock 
{
private:
	string name;  // �ɶ���д
	string lover;  // ֻд
	int age = 10;  // ֻ��

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

//���Բ
//class Point  //���ļ���д
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

//class Circle  //���ļ���д
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
		cout << "����Բ��" << endl;
	}
	else if(pow(c.get_p().get_x() - p.get_x(), 2) + pow(c.get_p().get_y() - p.get_y(), 2) > pow(c.get_r(), 2))
	{
		cout << "����Բ��" << endl;
	}
	else 
	{
		cout << "����Բ��" << endl;
	}
}

int main() 
{
	//// ���ѧ����
	//class Student student;
	//student.ID = 2020110040;
	//student.name = "��";
	//student.Show();
	//student.setname("��");
	//student.Show();

	//// ����Ȩ��
	//class Person person;
	////person.name = "κ��";
	////person.IDcard = 12345;  //protected���ɷ���
	////person.car = "������";  //private���ɷ���
	//person.Show();
	//person.give_value();
	//person.Show();

	// struct��class

	// ˽�����Եĺô�
	/*Clock clock;
	clock.write_name("����");
	cout<< "�����ǣ�" << clock.read_name() << endl;
	clock.write_lover("����");
	cout << "�����ǣ�" << clock.read_age() << endl;*/

	// ʵ�ʰ�����������
	//Cube cube;
	//cube.set_h(5);
	//cube.set_l(6);
	//cube.set_w(5);
	//cout << "�����������" << cube.calcuate_s() << endl;
	//cout << "�����������" << cube.calcuate_v() << endl;
	//Cube cube2;
	//cube2.set_h(5);
	//cube2.set_l(6);
	//cube2.set_w(6);

	//bool ret = Choose(cube, cube2); // ȫ�ֺ����ж�
	//if (ret) 
	//{
	//	cout << "������������ͬ" << endl;
	//}
	//else
	//{
	//	cout << "���������岻ͬ" << endl;
	//}
	//bool ret2 = cube.Choose(cube2);  //��Ա�����ж�
	//if (ret2)
	//{
	//	cout << "������������ͬ" << endl;
	//}
	//else
	//{
	//	cout << "���������岻ͬ" << endl;
	//}

	//ʵ�ʰ��������Բ
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