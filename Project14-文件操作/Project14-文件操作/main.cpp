#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void test01() 
{
	//1.包含头文件fstream
	//2.创建流对象
	ofstream ofs;  //ofstream类是fstream中的可写类，ifstream是可读类，fstream是可读可写类
	//3.指定打开方式
	ofs.open("D:\C++\Personal\Project14-文件操作\test01.txt", ios::out);
	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "年龄：18" << endl;
	ofs << "性别：男" << endl;
	//5.关闭文件
	ofs.close();
}

//读文件
void test02() 
{
	//1.
	ifstream ifs;  //2.
	ifs.open("test01.txt", ios::in);  //3. 2和3合在一起类似于python中的fp=open('','rb')
	if (!ifs.is_open()) // 判断是否成功打开
	{
		cout << "读取文件失败" << endl;
	}
	//char buf[1024] = { 0 };
	//while (ifs >> buf) // 4.读内容（4种方法）  4.类似于Python的fb.read()与fb.write(~~~)
	//{
	//	cout << buf << endl;
	//}
	string buf;
	while ( getline(ifs,buf)) 
	{
		cout << buf << endl;
	}
	ifs.close();  //5.
}

//写二进制文件
class Person 
{
public:
	char m_name[64];
	int m_age;
};

void test03() 
{
	//1.
	ofstream ofs("test02.txt", ios::out|ios::binary); //2+3,省略open，为ofs类的构造函数
	Person p = {"张三", 18};
	ofs.write((const char*)&p, sizeof(Person));  //4.二进制的写入，不同于ofs<<的写法
	ofs.close();  //5.
}

//读二进制文件
void test04() 
{
	//1.
	ifstream ifs("test02.txt", ios::in | ios::binary);  //2.+3.
	if (!ifs.is_open()) 
	{
		cout << "打开文件失败" << endl;
		return;
	}
	Person p;
	ifs.read((char *)&p, sizeof(Person));  //4.二进制的读取，读取的东西必须要新建一个相同结构的类Person。与write不同在于，write为(const char *)类型，而read为(char*)类型-----都指向地址
	cout << "年龄为：" << p.m_age << "  姓名为：" << p.m_name << endl;
	ifs.close();
}

int main() 
{
	//写文件
	//test01();

	//读文件
	test02();
	//Python:
	//1. fp = open('','rb')   ('wb')
	//2. fp.read()            (fp.write(~~~))
	//3. fp.close()
	//C++
	//1. 包含头文件
	//2. ifstream ifs             (ofstream ofs)
	//3. ifs.open("",ios::in)     (ios::out)
	//4. while(ifs>>buf)          (ofs<<)
	//5. ifs.close()              (ofs.close())

	//写二进制文件
	test03();

	//读二进制文件
	test04();

	system("pause");
	return 0;
}