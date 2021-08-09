#include<iostream>
using namespace std;

class Animal 
{
public:
	virtual void speak()   //虚函数（vfptr虚函数指针、虚函数表）
	{
		cout << "动物在叫" << endl;
	}
};

class Cat :public Animal 
{
public:
	void speak() 
	{
		cout << "猫在叫" << endl;
	}
};

class Dog :public Animal 
{
public:
	void speak() 
	{
		cout << "狗在叫" << endl;
	}
};

void Speak(Animal & a) 
{
	a.speak();
}

void test01()
{
	Cat cat;
	Speak(cat);  //子类对象传入父类引用。若没有父类的虚函数，此处会直接调用Animal的speak，不管传什么对象，因为在编译阶段就已经确定地址了，就是Animal。
	//那么我们想在运行阶段才分配应该怎么做呢，就需要动态多态，使用父类的虚函数就可以实现动态多态，在调用时才指向不同对象地址

	Dog dog;
	Speak(dog);//这也是多态的宗旨，子类继承父类的属性与函数，但每个子类对象属性值函数值确是不一样的。在实现阶段通过一个父类指针或引用，就可以动态实现多个对象的多态
}

//多态优点：计算器类
class calculator   //不用多态，普通写法
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

class abstract   //使用多态写法（同一个函数名在子类中实现不同功能）
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
	abstract * a = new add_calculator;  //调用创建一个父类对象指针（引用），指向子类
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

//纯虚函数与抽象类
class Base   //抽象类：1.无法实例化抽象类  2.抽象类的子类必须要重写父类中的纯虚函数，否则也属于抽象类
{
public:
	virtual void func() = 0; //纯虚函数
};

class Son :public Base 
{
public:
	void func() 
	{
		cout << "纯虚函数的子类重写" << endl;
	}
};

void test04() 
{
	//Base b;  //抽象类无法实例化对象
	//new Base;  //抽象类无法实例化对象

	Base* b = new Son;
	b->func();
}

//多态案例2-制作饮品
class MakeDrink 
{
public:
	virtual void boil() = 0;  //纯虚函数
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
		cout << "煮开水" << endl;
	}; 
	void brew() 
	{
		cout << "倒入山泉水" << endl;
	};
	void PourInCup()
	{
		cout << "导入咖啡" << endl;
	};
	void PutSomething() 
	{
		cout << "放入枸杞" << endl;
	};
};

class tea :public MakeDrink 
{
	void boil()
	{
		cout << "煮农夫山泉" << endl;
	};
	void brew()
	{
		cout << "倒入矿泉水" << endl;
	};
	void PourInCup()
	{
		cout << "导入茶" << endl;
	};
	void PutSomething()
	{
		cout << "放入六味地黄丸" << endl;
	};
};

void makedrink(MakeDrink * abc) 
{
	abc->MakeDrinking();  //多态：同一个接口
	delete abc;  //释放堆区!!!
}

void test05() 
{
	makedrink(new tea); //多态：传入不同数据
	makedrink(new coffee);
};

//虚析构与纯虚析构：无论是虚析构还是纯虚析构，都是为了解决使用了纯虚函数抽象类后，堆区生成子对象后子对象的内存释放问题的
class Animal2
{
public:
	virtual void speak() = 0;
	Animal2() 
	{
		cout << "Animal2的构造函数" << endl;
	}
	//virtual ~Animal2()  // 如果父类析构不用虚析构，会导致虚函数speak生成的子对象无法被析构，能析构的只有父类。因此使用虚析构，但是虚析构会使得类不是抽象类，所以使用纯虚析构
	//{
	//	cout << "Animal2的虚析构" << endl;
	//}
	virtual ~Animal2() = 0; //纯虚析构，不像纯虚函数，除了定义（=0），还要类外声明
};
Animal2::~Animal2() //纯虚析构的类外声明
{
	cout << "Animal2的纯虚析构" << endl;
}

class Cat2 :public Animal2 
{
public:
	string* m_name;
	Cat2(string name)  //构造函数
	{
		cout << "Cat2的构造函数" << endl;
		m_name = new string(name);  //子类含有堆区数据，并且是多态类型的，继承纯虚函数，需要在父类中虚析构或者纯虚析构来释放子类中的堆区数据！
	}
	~Cat2()  //析构函数
	{
		if (m_name != NULL) 
		{
			cout << "Cat2的析构函数" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	virtual void speak() 
	{
		cout << *m_name << "小猫叫" << endl;
	};
};

void test06() 
{
	Animal2* a;
	a = new Cat2("Tom");  //父类指向子类对象（new Cat）。此处new是父类指向子类，是多态的定义，必须要有。子类中的new是使用了一种方法，可用可不用
	a->speak();
	delete a; //a是堆区创建的，别忘了释放！！！
	a = NULL;
}

//案例3：电脑组装
class CPU   //父类，使用纯虚函数，所以为抽象类（多态的基础）
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

class IntelCPU :public CPU  //继承。由于父类使用纯虚函数，所以为子类为多态
{
public:
	void calculate() 
	{
		cout << "Intel的CPU开始计算..." << endl;
	}
};
class AMDCPU :public CPU
{
public:
	void calculate()
	{
		cout << "AMD的CPU开始计算..." << endl;
	}
};
class AMDGraphy :public Gragphy
{
public:
	void display()
	{
		cout << "AMD的显卡开始显示..." << endl;
	}
};
class ColorfulGragphy :public Gragphy 
{
public:
	void display() 
	{
		cout << "七彩虹的显卡开始显示..." << endl;
	}
};
class IntelMemory :public Memory 
{
public:
	void storage() 
	{
		cout << "Intel的内存条开始存储..." << endl;
	}
};
class ShiquanMemory :public Memory
{
public:
	void storage()
	{
		cout << "十铨的内存条开始存储..." << endl;
	}
};

class Computer
{
public:
	Computer(CPU* cpu, Gragphy* gragphy, Memory* memory) //构造函数。定义父类指针，传入堆区子类对象（多态）
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
	~Computer()  //只有子类中new了一个堆区变量，才需要在父类中虚析构或者纯虚析构。当仅仅是多态定义：父类指针指向new出来的子类对象，为子类对象是new堆区的，不用在父类中纯虚析构
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
	cout << "第一台电脑开始工作" << endl;
	Computer * Computer1 = new Computer(new IntelCPU, new ColorfulGragphy, new ShiquanMemory);
	//左值为一个Computer类型的指针。右边为一个堆区地址，堆区中存储Computer实例化对象，返回指向它的指针。括号中是构造函数，使用了多态，堆区子类对象与父类之间的链接
	Computer1->work();

	cout << "------------------" << endl;
	cout << "第二台电脑开始工作" << endl;
	Computer* Computer2 = new Computer(new AMDCPU, new AMDGraphy, new IntelMemory);
	Computer2->work();
	
	cout << "------------------" << endl;
	cout << "第二台电脑开始工作" << endl;
	Computer* Computer3 = new Computer(new IntelCPU, new AMDGraphy, new IntelMemory);
	Computer3->work();

	delete Computer1;  //!!!堆区释放，防止内存溢出
	delete Computer2;
	delete Computer3;
}

int main() 
{//面向对象三大原则：封装、继承、多态
	//多态：静态多态、动态多态
	//静态多态：包括函数重载（形参来区分）与运算符重载（operator-成员函数实现、全局函数实现（除了赋值重载不行））
	//动态多态：父类虚函数（vfptr虚函数指针、虚函数表）（虚类中的是虚基类指针、虚基类表）-----菱形继承是虚类，这里是虚函数
	//静态多态的函数地址早绑定-编译阶段确定函数地址
	//动态多态的函数地址晚绑定-运行阶段确定函数地址
	//多态满足的条件：
	//1.有继承关系
	//2.子类重写父类的虚函数
	//多态使用：
	//父类指针或引用指向子类对象
	//test01();

	//多态原理：
	//父类创建一个虚函数，会生成一个vfptr虚函数指针，指向vftable虚函数表，整个父类4个字节，为指针的大小。vftable中存储的是虚函数的地址:&Animal::speak
	//子类在不重写父类虚函数，只继承时，会继承父类的一切，包括vfptr与vftable，子类中的vftable存储父类speak地址。若是重写虚函数，子类的vfptr指向的vftable会被重写覆盖
	//从&Animal::speak变为&Cat::speak，再调用就会指向子类的speak。
	//调用也很有讲究，不是调用子类；而是使用父类指针或引用指向子类对象：Animal &animal = cat，并且注意调用要使用父类对象调用：animal.speak()。这是因为父类的指针或引用
	//指向了子类对象的地址，这样vfptr指向的vftabe中存储的是子类重写虚函数的地址，执行的是子类特有的值。这就是运行时确定函数地址，动态多态的原理

	//多态优点：计算器类
	//1.代码结构清晰（1个父类n个子类，子类实现不同功能，父类为源码） 2.可读性强（子类各个分离，功能各个分离，利于理解）  3.利于后期扩展与维护（扩展仅需加相应的子类即可，维护只需维护出错的子类即可，别的子类不用看）
	//真实开发中提倡 开闭原则：对扩展开放，对修改关闭。扩展仅需扩展子类即可扩展功能，修改不能修改源码，修改相应子类就可以修改出错的功能
	//test02();
	//test03();

	//纯虚函数和抽象类
	//在多态中，通常父类中虚函数的实现都是毫无意义的，通常都是调用子类中重写的该虚函数，所以此时可以把该父类虚函数写为纯虚函数，此时的类就是一个抽象类
	//test04();

	//多态-案例2-制作饮品
	//test05();

	//虚析构与纯虚析构
	//test06();

	//案例3：电脑组装
	test07();

	system("pause");
	return 0;
}