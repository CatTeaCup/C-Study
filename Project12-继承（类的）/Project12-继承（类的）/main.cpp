#include<iostream>
using namespace std;

//class Java 
//{
//public:
//	void header() 
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer() 
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left() 
//	{
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void content() 
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//};
//class Python
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//};
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void content()
//	{
//		cout << "C++ѧ����Ƶ" << endl;
//	}
//};

//�̳�
class Father 
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}
	void left()
	{
		cout << "Java��Python��C++...�����������б�" << endl;
	}
};
	//�̳� �����﷨- class ����:�̳з�ʽ ����
	//���� Ҳ�� ������
	//���� Ҳ�� ����
class Java :public Father 
{
public:
	void content()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}
};

class Python :public Father 
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

class CPP :public Father 
{
public:
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
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

//�̳з�ʽ
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
		m_a = 10;  //m_a��m_b�ڸ����зֱ���public��protected���������ж���private���������ڿ��Է���
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
		m_b = 10;*/  //��ʹ������public�̳У������޷��̳е�����Ϊ�������������Ͼͱ��̳�Ϊprivate������������޷��̳�
	}
};

void test02() 
{
	Father02 f;
	f.read();
}

//�̳��еĶ���ģ��
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
	cout << sizeof(s) << endl; //˵����ʹ���಻�ܷ��ʸ�����������ԣ�˽�У������������Ǽ̳������и������Եģ����������private
	//���ÿ�����Ա������ʾ�����߲鿴����ģ��
	//��ת�̷���D:
	//��ת�ļ�·�� cd ����·����
	//�鿴����
	//cl / dl reportSingleClassLayout���� �ļ���   �����浥����Ĳ��֣�
}

//�̳еĹ���������
class Base
{
public:
	Base() 
	{
		cout << "����Ĺ��캯��" << endl;
	}
	~Base() 
	{
		cout << "�������������" << endl;
	}
};

class Son_04 :public Base 
{
public:
	Son_04() 
	{
		cout << "����Ĺ��캯��" << endl;
	}
	~Son_04() 
	{
		cout << "�������������" << endl;
	}
};

void test04() 
{
	Base b;
	Son_04 s;
}

//�̳е�ͬ��������
class BASE 
{
public:
	int m_a = 10;
	void father() 
	{
		cout << "�����Ա����" << endl;
	}
	void father(int a)
	{
		cout << "�����Ա���� int a" << endl;
	}
};

class SON :public BASE 
{
public:
	int m_a = 100;
	void father()
	{
		cout << "�����Ա����" << endl;
	}
};

void test05() 
{
	SON S;
	cout << S.m_a << endl;  //��������
	cout << S.BASE::m_a << endl;  //��������
	S.father();  //���ຯ��
	S.BASE::father();  //���ຯ��
	S.BASE::father(10);  //�������غ���
}

//�̳еľ�̬ͬ��������
class BASE1 
{
public:
	static int m_a;
	static void father() 
	{
		cout << "�����Ա����" << endl;
	}
	static void father(int a)
	{
		cout << "�����Ա���� int a" << endl;
	}
};
int BASE1::m_a = 10;  //��̬�������������������ʼ�� 

class SON1:public BASE1 
{
public:
	static int m_a;
	static void father()
	{
		cout << "�����Ա����" << endl;
	}
};
int SON1::m_a = 100;

void test06() 
{
	SON1 s;
	cout << s.m_a << endl;  //��̬����ͨ���������
	cout << s.BASE1::m_a << endl;
	cout << SON1::m_a << endl;  //��̬����ͨ����������
	cout << SON1::BASE1::m_a << endl;

	s.father(); //��̬����ͨ���������
	s.BASE1::father();
	s.BASE1::father(10);
	SON1::father();  //��̬����ͨ����������
	SON1::BASE1::father();
	SON1::BASE1::father(10);
}

//��̳�
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

class SON2 :public BASE2,public BASE3  //��̳�
{
public:
	int m_b;
	int m_c;
};

void test07() 
{
	SON2 s;
	cout << s.BASE2::m_a << endl;  //��̳ж����Խ��
	cout << s.BASE3::m_a << endl;  //��̳ж����Խ��
}

//���μ̳�
class Animal 
{
public:
	int m_age;
};

class Sheep :virtual public Animal {}; // vbptr�������ָ�룬ָ�����������̳е���һ��ָ�룬��ָ��ָ��Animal�����ԡ�������Sheep��Tuo��SheepTuo������һ��m_age

class Tuo :virtual public Animal {};  //�ڵײ��ϣ������������Sheep��ַ��0��Tuo��ַ��4��Animal��ַ��8����Sheep��vbptrƫ����Ϊ8��ָ��8��Tuo��ַ��4��ƫ����Ϊ4��ָ��8

class SheepTuo :public Sheep, public Tuo {};

void test08()
{
	SheepTuo st; //��ʹ�������ָ�룬st��СΪ8���̳�����m_age��ʹ�������ָ�룬st��СΪ12������vbptr��Sheep��Tuo���Լ�һ��m_age��Animal��
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;
	cout << st.Sheep::m_age << endl; //��Ȼ����ʹ��������������ͬ������
	cout << st.Tuo::m_age << endl; //
	cout << st.m_age << endl; //����st�̳�������m_age,û��Ū�ˣ�ֻ����vbptr
}

int main() 
{
	//�̳� �����﷨- class ����:�̳з�ʽ ���� 
	//test01();

	//�̳з�ʽ �����̳�public �����̳�protected ˽�м̳�private
	//�����к��� public��protected��private������
	//�����̳У�������->���ࣩpublic->public   protected->protected   private->���ܼ̳�
	//�����̳У�public��protected->protected   private->���ܼ̳�
	//˽�м̳У�public��protected->private     private->���ܼ̳�
	//protected��private֮��������ǣ�protected���Ա��̳С�private���ܱ��̳�
	//test02();

	//�̳��еĶ���ģ��
	//test03();

	//�̳еĹ���������
	test04();

	//�̳е�ͬ��������(����  ��  ����)
	test05();

	//�̳еľ�̬ͬ������������  ��  ������
	test06();  //��̬ͬ������ �� ͬ������ �Ĵ���ʽ��ȫһ����ֻ������̬������˶�����ʻ�����ͨ���������з���

	//��̳�
	//test07();

	//���μ̳�:�����ָ�롢������
	test08();

	system("pause");
	return 0;
}