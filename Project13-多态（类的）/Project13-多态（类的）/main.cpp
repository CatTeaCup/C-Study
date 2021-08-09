#include<iostream>
using namespace std;

class Animal 
{
public:
	virtual void speak()   //�麯����vfptr�麯��ָ�롢�麯����
	{
		cout << "�����ڽ�" << endl;
	}
};

class Cat :public Animal 
{
public:
	void speak() 
	{
		cout << "è�ڽ�" << endl;
	}
};

class Dog :public Animal 
{
public:
	void speak() 
	{
		cout << "���ڽ�" << endl;
	}
};

void Speak(Animal & a) 
{
	a.speak();
}

void test01()
{
	Cat cat;
	Speak(cat);  //��������븸�����á���û�и�����麯�����˴���ֱ�ӵ���Animal��speak�����ܴ�ʲô������Ϊ�ڱ���׶ξ��Ѿ�ȷ����ַ�ˣ�����Animal��
	//��ô�����������н׶βŷ���Ӧ����ô���أ�����Ҫ��̬��̬��ʹ�ø�����麯���Ϳ���ʵ�ֶ�̬��̬���ڵ���ʱ��ָ��ͬ�����ַ

	Dog dog;
	Speak(dog);//��Ҳ�Ƕ�̬����ּ������̳и���������뺯������ÿ�������������ֵ����ֵȷ�ǲ�һ���ġ���ʵ�ֽ׶�ͨ��һ������ָ������ã��Ϳ��Զ�̬ʵ�ֶ������Ķ�̬
}

//��̬�ŵ㣺��������
class calculator   //���ö�̬����ͨд��
{
public:
	int num_1;
	int num_2;
	int calculate(string oper) 
	{
		if (oper == "+") 
		{
			return num_1 + num_2;
		}
		if (oper == "-")
		{
			return num_1 - num_2;
		}
		if (oper == "*")
		{
			return num_1 * num_2;
		}
	}
};

void test02() 
{
	calculator c;
	c.num_1 = 10;
	c.num_2 = 10;
	cout << c.num_1 << "+" << c.num_2 << "=" << c.calculate("+") << endl;
	cout << c.num_1 << "-" << c.num_2 << "=" << c.calculate("-") << endl;
	cout << c.num_1 << "*" << c.num_2 << "=" << c.calculate("*") << endl;
}

class abstract   //ʹ�ö�̬д����ͬһ����������������ʵ�ֲ�ͬ���ܣ�
{
public:
	int num_1;
	int num_2;
	virtual int getresult() 
	{
		return 0;
	}
};

class add_calculator :public abstract
{
public:
	int getresult()
	{
		return num_1 + num_2;
	}
};

class sub_calculator :public abstract
{
public:
	int getresult()
	{
		return num_1 - num_2;
	}
};

class mul_calculator :public abstract
{
public:
	int getresult()
	{
		return num_1 * num_2;
	}
};

void test03() 
{
	abstract * a = new add_calculator;  //���ô���һ���������ָ�루���ã���ָ������
	a->num_1 = 10;
	a->num_2 = 20;
	cout << a->num_1 << "+" << a->num_2 << "=" << a->getresult() << endl;

	abstract* a2 = new sub_calculator;
	a2->num_1 = 10;
	a2->num_2 = 20;
	cout << a2->num_1 << "-" << a2->num_2 << "=" << a2->getresult() << endl;

	abstract* a3 = new mul_calculator;
	a3->num_1 = 10;
	a3->num_2 = 20;
	cout << a3->num_1 << "+" << a3->num_2 << "=" << a3->getresult() << endl;
}

//���麯���������
class Base   //�����ࣺ1.�޷�ʵ����������  2.��������������Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����
{
public:
	virtual void func() = 0; //���麯��
};

class Son :public Base 
{
public:
	void func() 
	{
		cout << "���麯����������д" << endl;
	}
};

void test04() 
{
	//Base b;  //�������޷�ʵ��������
	//new Base;  //�������޷�ʵ��������

	Base* b = new Son;
	b->func();
}

//��̬����2-������Ʒ
class MakeDrink 
{
public:
	virtual void boil() = 0;  //���麯��
	virtual void brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	void MakeDrinking() 
	{
		boil();
		brew();
		PourInCup();
		PutSomething();
	}
};

class coffee :public MakeDrink
{
	void boil() 
	{
		cout << "��ˮ" << endl;
	}; 
	void brew() 
	{
		cout << "����ɽȪˮ" << endl;
	};
	void PourInCup()
	{
		cout << "���뿧��" << endl;
	};
	void PutSomething() 
	{
		cout << "�������" << endl;
	};
};

class tea :public MakeDrink 
{
	void boil()
	{
		cout << "��ũ��ɽȪ" << endl;
	};
	void brew()
	{
		cout << "�����Ȫˮ" << endl;
	};
	void PourInCup()
	{
		cout << "�����" << endl;
	};
	void PutSomething()
	{
		cout << "������ζ�ػ���" << endl;
	};
};

void makedrink(MakeDrink * abc) 
{
	abc->MakeDrinking();  //��̬��ͬһ���ӿ�
	delete abc;  //�ͷŶ���!!!
}

void test05() 
{
	makedrink(new tea); //��̬�����벻ͬ����
	makedrink(new coffee);
};

//�������봿�����������������������Ǵ�������������Ϊ�˽��ʹ���˴��麯��������󣬶��������Ӷ�����Ӷ�����ڴ��ͷ������
class Animal2
{
public:
	virtual void speak() = 0;
	Animal2() 
	{
		cout << "Animal2�Ĺ��캯��" << endl;
	}
	//virtual ~Animal2()  // ������������������������ᵼ���麯��speak���ɵ��Ӷ����޷�����������������ֻ�и��ࡣ���ʹ����������������������ʹ���಻�ǳ����࣬����ʹ�ô�������
	//{
	//	cout << "Animal2��������" << endl;
	//}
	virtual ~Animal2() = 0; //���������������麯�������˶��壨=0������Ҫ��������
};
Animal2::~Animal2() //������������������
{
	cout << "Animal2�Ĵ�������" << endl;
}

class Cat2 :public Animal2 
{
public:
	string* m_name;
	Cat2(string name)  //���캯��
	{
		cout << "Cat2�Ĺ��캯��" << endl;
		m_name = new string(name);  //���ຬ�ж������ݣ������Ƕ�̬���͵ģ��̳д��麯������Ҫ�ڸ��������������ߴ����������ͷ������еĶ������ݣ�
	}
	~Cat2()  //��������
	{
		if (m_name != NULL) 
		{
			cout << "Cat2����������" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	virtual void speak() 
	{
		cout << *m_name << "Сè��" << endl;
	};
};

void test06() 
{
	Animal2* a;
	a = new Cat2("Tom");  //����ָ���������new Cat�����˴�new�Ǹ���ָ�����࣬�Ƕ�̬�Ķ��壬����Ҫ�С������е�new��ʹ����һ�ַ��������ÿɲ���
	a->speak();
	delete a; //a�Ƕ��������ģ��������ͷţ�����
	a = NULL;
}

//����3��������װ
class CPU   //���࣬ʹ�ô��麯��������Ϊ�����ࣨ��̬�Ļ�����
{
public:
	virtual void calculate() = 0;
};
class Gragphy 
{
public:
	virtual void display() = 0;
};
class Memory 
{
public:
	virtual void storage() = 0;
};

class IntelCPU :public CPU  //�̳С����ڸ���ʹ�ô��麯��������Ϊ����Ϊ��̬
{
public:
	void calculate() 
	{
		cout << "Intel��CPU��ʼ����..." << endl;
	}
};
class AMDCPU :public CPU
{
public:
	void calculate()
	{
		cout << "AMD��CPU��ʼ����..." << endl;
	}
};
class AMDGraphy :public Gragphy
{
public:
	void display()
	{
		cout << "AMD���Կ���ʼ��ʾ..." << endl;
	}
};
class ColorfulGragphy :public Gragphy 
{
public:
	void display() 
	{
		cout << "�߲ʺ���Կ���ʼ��ʾ..." << endl;
	}
};
class IntelMemory :public Memory 
{
public:
	void storage() 
	{
		cout << "Intel���ڴ�����ʼ�洢..." << endl;
	}
};
class ShiquanMemory :public Memory
{
public:
	void storage()
	{
		cout << "ʮ�����ڴ�����ʼ�洢..." << endl;
	}
};

class Computer
{
public:
	Computer(CPU* cpu, Gragphy* gragphy, Memory* memory) //���캯�������常��ָ�룬�������������󣨶�̬��
	{
		m_cpu = cpu;
		m_gragphy = gragphy;
		m_memory = memory;
	}
	void work()
	{
		m_cpu->calculate();
		m_gragphy->display();
		m_memory->storage();
	}
	~Computer()  //ֻ��������new��һ����������������Ҫ�ڸ��������������ߴ����������������Ƕ�̬���壺����ָ��ָ��new�������������Ϊ���������new�����ģ������ڸ����д�������
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gragphy != NULL)
		{
			delete m_gragphy;
			m_gragphy = NULL;
		}
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
	}
private:
	CPU* m_cpu;
	Gragphy* m_gragphy;
	Memory* m_memory;
};

void test07() 
{
	cout << "��һ̨���Կ�ʼ����" << endl;
	Computer * Computer1 = new Computer(new IntelCPU, new ColorfulGragphy, new ShiquanMemory);
	//��ֵΪһ��Computer���͵�ָ�롣�ұ�Ϊһ��������ַ�������д洢Computerʵ�������󣬷���ָ������ָ�롣�������ǹ��캯����ʹ���˶�̬��������������븸��֮�������
	Computer1->work();

	cout << "------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	Computer* Computer2 = new Computer(new AMDCPU, new AMDGraphy, new IntelMemory);
	Computer2->work();
	
	cout << "------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	Computer* Computer3 = new Computer(new IntelCPU, new AMDGraphy, new IntelMemory);
	Computer3->work();

	delete Computer1;  //!!!�����ͷţ���ֹ�ڴ����
	delete Computer2;
	delete Computer3;
}

int main() 
{//�����������ԭ�򣺷�װ���̳С���̬
	//��̬����̬��̬����̬��̬
	//��̬��̬�������������أ��β������֣�����������أ�operator-��Ա����ʵ�֡�ȫ�ֺ���ʵ�֣����˸�ֵ���ز��У���
	//��̬��̬�������麯����vfptr�麯��ָ�롢�麯�����������е��������ָ�롢������-----���μ̳������࣬�������麯��
	//��̬��̬�ĺ�����ַ���-����׶�ȷ��������ַ
	//��̬��̬�ĺ�����ַ���-���н׶�ȷ��������ַ
	//��̬�����������
	//1.�м̳й�ϵ
	//2.������д������麯��
	//��̬ʹ�ã�
	//����ָ�������ָ���������
	//test01();

	//��̬ԭ��
	//���ഴ��һ���麯����������һ��vfptr�麯��ָ�룬ָ��vftable�麯������������4���ֽڣ�Ϊָ��Ĵ�С��vftable�д洢�����麯���ĵ�ַ:&Animal::speak
	//�����ڲ���д�����麯����ֻ�̳�ʱ����̳и����һ�У�����vfptr��vftable�������е�vftable�洢����speak��ַ��������д�麯���������vfptrָ���vftable�ᱻ��д����
	//��&Animal::speak��Ϊ&Cat::speak���ٵ��þͻ�ָ�������speak��
	//����Ҳ���н��������ǵ������ࣻ����ʹ�ø���ָ�������ָ���������Animal &animal = cat������ע�����Ҫʹ�ø��������ã�animal.speak()��������Ϊ�����ָ�������
	//ָ�����������ĵ�ַ������vfptrָ���vftabe�д洢����������д�麯���ĵ�ַ��ִ�е����������е�ֵ�����������ʱȷ��������ַ����̬��̬��ԭ��

	//��̬�ŵ㣺��������
	//1.����ṹ������1������n�����࣬����ʵ�ֲ�ͬ���ܣ�����ΪԴ�룩 2.�ɶ���ǿ������������룬���ܸ������룬������⣩  3.���ں�����չ��ά������չ�������Ӧ�����༴�ɣ�ά��ֻ��ά����������༴�ɣ�������಻�ÿ���
	//��ʵ�������ᳫ ����ԭ�򣺶���չ���ţ����޸Ĺرա���չ������չ���༴����չ���ܣ��޸Ĳ����޸�Դ�룬�޸���Ӧ����Ϳ����޸ĳ���Ĺ���
	//test02();
	//test03();

	//���麯���ͳ�����
	//�ڶ�̬�У�ͨ���������麯����ʵ�ֶ��Ǻ�������ģ�ͨ�����ǵ�����������д�ĸ��麯�������Դ�ʱ���԰Ѹø����麯��дΪ���麯������ʱ�������һ��������
	//test04();

	//��̬-����2-������Ʒ
	//test05();

	//�������봿������
	//test06();

	//����3��������װ
	test07();

	system("pause");
	return 0;
}