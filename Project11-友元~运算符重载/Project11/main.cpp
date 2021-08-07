#include<iostream>
using namespace std;

//ȫ�ֺ�������Ԫ
class Building 
{
	friend void goodgay(Building* building);  //��ȫ�ֺ���+friend��������һ���������Ϳ��Է��ʸ����private��
public:
	void livingroom() 
	{
		cout << "public��ĳ�Ա������living room" << endl;
	}
private:
	void bedroom() 
	{
		cout << "private��ĳ�Ա������bed room---��Ҫ��Ԫ�����з���" << endl;
	}

};

void goodgay(Building * building)  //ȫ�ֺ���
{
	building->livingroom();
	building->bedroom();  //�������private���ȫ�ֺ���������ʹ��friend���壬�����ڸ�ȫ�ֺ����з���˽����
}

void test01() 
{
	//Building* building;
	//goodgay(building);  // ��Ҫ��ָ������ʼ��һ���࣡����  ָ��ֻ�Ƕ�����һ����ָ�룬���Ƕ�����һ���࣬���ָ��û��ָ��һ�������Ȩ��
	Building building;
	goodgay(&building);  //Ӧ����ֵ����ʼ��һ���࣬����һ������Ȼ�󴫵����ַ������������ᱨ��ʹ����δ��ʼ���ľֲ�������
						 //��Ҳ��֮ǰ�������㷨�ﶨ��һ����ָ������Ҫ�ڶ����￪���ڴ���ö���һ������Ϊָ������ģ�����һ������ֻ��һ������ָ��
}

//������Ԫ
class Building2;  //��ǰ��������ֹ����������

class GoodGay 
{
public:
	GoodGay(); //��ʹ�ǹ��캯���������ⶨ��ʱҲҪ��������
	void visit();  //�������⹹��
	Building2 * building2;
};

class Building2 
{
	friend class GoodGay;  //������Ԫ������GoodGay���ʼ��һ��Building2�����ٵ���visit�����Building2�ڵĳ�Ա������GoodGay��Building2����Ԫ
public:
	Building2();  //�������⹹��
	string livingroom;
private:
	string bedroom;
};

Building2::Building2()  // ���ں������޲ι��죩���ⶨ�� 
{
	livingroom = "����";
	bedroom = "����";
}
GoodGay::GoodGay()
{
	building2 = new Building2;
}
void GoodGay::visit()  //���ں������ǹ��캯�������ⶨ�壬��Ҫ��void
{
	cout<<building2->livingroom<<endl;
	cout<<building2->bedroom<<endl;  //��Ҫ����Building2��˽�б�������Ҫ��Building2�����ﶨ��GoodGay����Ԫ
}

void test02() 
{
	GoodGay goodgay2;
	goodgay2.visit();
}

//��Ա��������Ԫ
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
	//	building3 = new Building3;  //��Ȼ֮ǰ������class Building3;����֪����һ�࣬���ǲ���֪����ʲô��Ա������new Building3�ǷǷ��ģ���֪����ʲô��ô�ڶ���������������ء�ҪŲ������Building3����ȥ�������void visit��Ҳ��һ��
	//}

class Building3
{
	friend void GoodGay2::visit();  //��ĳ�Ա��������Ԫ
public:
	//string m_livingroom = "����";
	string m_livingroom;
	Building3();
private:
	//string m_bedroom = "����";
	string m_bedroom;
};

GoodGay2::GoodGay2()
{
	building3 = new Building3;  //��Ȼ֮ǰ������class Building3;����֪����һ�࣬���ǲ���֪����ʲô��Ա������new Building3�ǷǷ��ģ���֪����ʲô��ô�ڶ����������������
}
Building3::Building3()
{
	m_livingroom = "����";
	m_bedroom = "����";
}
void GoodGay2::visit() //��Ա��������Ԫ��ͬ���ǳ�Ա������visit2�Ͳ��ܷ���
{
	cout << building3->m_livingroom << endl;
	cout << building3->m_bedroom << endl;
}
void GoodGay2::visit2()
{
	cout << building3->m_livingroom << endl;
	//cout << building3->m_bedroom << endl;  //������Ԫ����Ա�����ģ������ܷ���˽�б���
}

void test03() 
{
	GoodGay2 gg;
	gg.visit();
	gg.visit2();
}

//�Ӻ����������
class Person 
{
public:
	int m_A;
	int m_B;

	//��Ա�������������
	//Person PersonAddPerson(Person &p)  //���ʶ���-Ҳ��ʵ����ӣ���������������ء���Ա������������ؾ���Ҫ��operator+�滻��Ա������
	//Person operator+(Person& p)   //��������ض��壬����ֱ���üӺ�
	//{
	//	Person temp; //����һ�������������ջ���������ڴ����ɶ��󣻶���һ����ָ���������������һ������ֻ��������һ������ָ��������ָ�룬����Ҫָ��һ���Ѿ����ڵĶ�����ڶ��������ڴ��½�����
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}
	////���������+��������
	//Person operator+(int b)   //��������ض��壬����ֱ���üӺ�
	//{
	//	Person temp; //����һ�������������ջ���������ڴ����ɶ��󣻶���һ����ָ���������������һ������ֻ��������һ������ָ��������ָ�룬����Ҫָ��һ���Ѿ����ڵĶ�����ڶ��������ڴ��½�����
	//	temp.m_A = this->m_A + b;
	//	temp.m_B = this->m_B + b;
	//	return temp;
	//}
};

	//ȫ�ֺ������������
	//Person PersonAddPerson(Person& p1, Person& p2)  // ���ʶ��壬�����滻����������ʵ�����������
Person operator+(Person &p1,Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
	//���������+��������
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

	//Person p3 = p1.PersonAddPerson(p2);  //���ʶ��壨��Ա��������ʹ�ó�Ա������������غ����ֱ����+
	//Person p3 = PersonAddPerson(p1, p2); //���ʶ��壨ȫ�ֺ�����
	Person p3 = p1 + p2;

	cout << p3.m_A << endl;
	cout << p3.m_B << endl;

	//���������Ҳ�����뺯�����ؽ�ϣ�ʵ��һ���������������
	Person p4 = p2 + 100;

	cout << p4.m_A << endl;
	cout << p4.m_B << endl;
}

//�������������
class Mean 
{
	friend ostream& operator<<(ostream& cout, Mean& m);  // ��Ԫ��ȫ�ֺ������������ڸ�ȫ�ֺ����з���˽�б���
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
	//���������ֻ��ʹ��ȫ�ֺ������ء���Ϊcout����������m�Ĺ�ϵֻ����cout����m���ң�����Ա������Ҫm.��Ա������(cout),˳����m����cout����
ostream& operator<<(ostream & cout,Mean &m) // cout��ostream���еģ�ʹ�����������壬ָ��ԭ����cout 
{
	cout << m.m_a << m.m_b << endl;
	return cout;  //���ظ��࣬������ʹ���������������ʱ�ں����endl�ȡ���test05��ʹ������cout��������Խ��ż�cout����ʽ˼ά
}
void test05() 
{
	Mean m;
	m.add_value(10, 20);
	cout << m << endl;  //����������
}

//++���������
class addadd 
{
	friend ostream& operator<<(ostream & cout, addadd a);
private:
	int m_a = 10;
public: //++���ؿ���ʹ�ó�Ա����Ҳ����ʹ��ȫ�ֺ���
	addadd & operator++()  //++a 
	{
		m_a++;
		return *this;  //���ص�ǰ��������m_a�Ѿ��ӹ���
	};
	addadd operator++(int) //a++��ǰ�ú���������ͬ��1.���صĲ�����ָ�룬��ΪҪ���ر������һ��ֵ��ָ���ֱ�ɷ��ؼӺ��ֵ�� 2.��Ҫint����ռλ�������ں������أ���ֻ����int�����ں��ã�������int=10��Ϊ�β�Ĭ��ֵ
	{
		addadd temp; // ��¼��ǰֵ
		temp = *this;  //*this��this���࣬��ֵ������ָ��
		m_a++;  //��
		return temp;  //����δ��֮ǰ�Ķ���
	}
};
ostream& operator<<(ostream & cout, addadd a)   //����˴��������addadd &a����������һ��ָ��a�����ָ�룬��ô���÷��ص���temp�ֲ�����ʹ����������������ᱨ����Ϊ��������<<�Ĳ���a
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

//--���������
class reduce 
{
	friend ostream& operator<<(ostream& cout, reduce a);
private:
	int m_b = 10;
public:
	reduce& operator--()   //ǰ�����أ���Ա���������������ڷ��ص���this�Ľ����ã�this��ָ�볣�������Զ��庯������Ӧ��Ϊ���ö�������ָ��
	{
		m_b--;
		return *this;
	}
	reduce operator--(int) //�������أ���Ա������
	{
		reduce temp;
		temp = *this;
		m_b--;
		return temp;
	}
};
ostream& operator<<(ostream &cout,reduce a)  //�������أ�ֻ����ȫ�ֺ����������Һ���Ҳ����Ϊ�������ͣ����ҷ��ص���cout����Ϊֵ���ͣ�������coutָ�롣���÷���ֱ���������������ֵ����˼��������ָ����Ҫ*����ֵ��
{
	cout << a.m_b << endl;
	return cout;  //�������͵ĺ�������ֵ����ֵ������ָ�����͵ĺ�������ֵ��ָ�롣�������ͺ�������ֵ��ֵ������ֱ�Ӹ���main��������������ã��������õĶ�������Ǵ��ݱ�������������ֱ�Ӷ���һ���������ã�����ʹ��const int &���ֳ������ã�����ָ�볣����
}
void test07()
{
	reduce b;
	cout << --b << endl;
	cout << b-- << endl;
	cout << b << endl;
}

//��ֵ���������
class give 
{
public:
	int * m_a;
	give(int p) 
	{
		m_a = new int(p);
	}
	~give() //��������
	{
		if (this->m_a!=NULL)
		{
			delete m_a;
			m_a = NULL; //��ֹҰָ��
		}
	}
	give & operator=(give &p) 
	{
		//������Ĭ��ǳ����
		//m_a = p.m_a;

		//�����Ӧ�����жϱ������Ƿ��ж����ڴ棬�еĻ��ͷ�
		if (m_a!=NULL)
		{
			delete m_a;
			m_a = NULL;
		}
		m_a = new int(*p.m_a);  //���ò��Ǳ�����ΪʲôҪ�����ã�Ŷ�������Ǳ�����p�ͱ�ʾ�������Ķ����������������������m_a��һ��ָ�룬���Զ�ȡ�����Ի���Ҫ������

		return *this;  //����������󣬿��Զ����ֵ
	}
};

void test08() 
{
	give g(10);
	cout << "g������Ϊ��" << *g.m_a << endl;
	give g2(12);  //��������帳ֵ������Ϊһ��ǳ���������������������󣬻ᱨ����Ϊ�����Ķ���ͬһ���ڴ�
	cout << "g2������Ϊ��" << *g2.m_a << endl;
	give g3(18);
	g3 = g2 = g;  //�����ֵ
	cout << "g3������Ϊ��" << *g3.m_a << endl;
}

//���ع�ϵ�����
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
	bool operator==(MOON &p) //==  //���ô��ݺͷ��صĶ���ֵ���൱��������ָ���ֵ�������������Ϊһ������ָ�룬���ܸ�ָ�򣬿��Ը�ֵ����ָ�봫�ݺͷ��صĶ��ǵ�ַ���൱������һ��ָ��ָ��õ�ַ
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
		cout << "����ͬ��" << endl;
	}
	else 
	{
		cout << "������ͬ��" << endl;
	}
	if (m1 != m3)
	{
		cout << "������ͬ��" << endl;
	}
	else
	{
		cout << "����ͬ��" << endl;
	}
}

//�����������������
class myprint 
{
public:
	void operator()(string a) //�����������������
	{
		cout << a << endl;
	}
};

void defprint(string m) //����
{
	cout << m << endl;
}

class myadd 
{
public:
	int operator()(int a, int b) //�����������������ʵ�����(��������������������ؿ���ʵ�ֶ��ֹ���)���º������ָ�����ں����STL�о�������
	{
		int c = a + b;
		return c;
	}
};

void test10() 
{
	myprint m;
	m("�����������������");  //����������������أ���Ϊʹ�÷��������ں���ʹ�ã������ֽзº���
	defprint("����");//����ʹ�ã����ں����С������Ǻ������������ʹ�ã�����һ������

	myadd m2;
	int sum = m2(11, 10);
	cout << "��Ϊ��" << sum << endl;
}

int main() 
{
	// ��Ԫ�����Է���һ�����˽�����ڵĳ�Ա     1.ȫ�ֺ�������Ԫ 2.������Ԫ 3.��Ա��������Ԫ
	//1.ȫ�ֺ�������Ԫ
	//test01();

	//2.������Ԫ����Ԫ��
	//test02();

	//3.��Ա��������Ԫ
	//test03();

	//��������أ��Ӻţ� :1.��Ա������������� 2.ȫ�ֺ������������ 3.��������ؿ��Խ�Ϻ�������
	//��������������Զ������ݽṹ֮������㣬����Ӽ��˳���������Ĭ���ǲ�֪���ģ���Ҫ�û��Զ���
	//test04();

	//�������������
	//test05();

	//++��--���������
	//test06();
	//test07();

	//��ֵ��������أ���Ϊ�������ṩ�ĸ�ֵ�������һ��ǳ��������������ڰ���ָ��ָ����������������������ڴ�
	//test08();

	//���ع�ϵ�������==��!=��>��<�������
	//test09();

	//���غ��������������()
	test10();

	system("pause");
	return 0;
}