#include<iostream>
#include<string>
using namespace std;

//string  STL  之前用过很多次了
//C中的string是使用一个char*指针进行维护
//C++中的string是一个类，包含find、copy、delete等类函数，还包含char*等类属性。所以C++是扩充了string的功能，本质还是使用char*进行维护的
void test01() 
{
	//string有四种构造方法
	string s1;  //1.创建一个空的字符串

	const char* str = "string";
	string s2(str);  //2.使用字符串进行初始化
	cout << "s2=" << s2 << endl;

	string s3(s2);  //3.拷贝构造，复制s2
	cout << "s3=" << s3 << endl;

	string s4(10, 'a');  //4.n个字符初始化。所以a为''而不是“”
	cout << "s4=" << s4 << endl;
}

//赋值
void test02() 
{
	string s1;  //默认构造,=赋值
	s1 = "string";
	cout << s1 << endl;

	string s2 = s1;  //拷贝构造
	cout << s2 << endl;

	string s3;  //string赋char
	s3 = 'a';
	cout << s3 << endl;

	string s4;  //assign赋值
	s4.assign("string C++", 5);
	cout << s4 << endl;
}

//字符串拼接
void test03() 
{
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << str1 << endl;

	str1 += ':';
	cout << str1 << endl;

	string str2 = "BATTLE FIELID";
	str1 += str2;
	cout << str1 << endl;

	string str3 = "I";
	str3.append(" love");
	cout << str3 << endl;

	str3.append(" game loft", 4);
	cout << str3 << endl;
}

//字符串查找和替换
void test04() 
{
	//查找
	string str1 = "abcdefgcde";
	int pos = str1.find("cde");
	if (pos == -1) 
	{
		cout << "未找到字符串" << endl;
	}
	else 
	{
		cout << "位置下标为：" << pos << endl;
	}

	//从右往左查
	pos = str1.rfind("cde");
	cout << pos << endl;

	//替换
	str1.replace(1, 3, "1111");  //b开始，bcd替换成为1111
	cout << str1 << endl;
}

//字符串比较
void test05() 
{
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) 
	{
		cout << "str1 == str2" << endl;
	}
}

//字符串存取
void test06() 
{
	string str = "hello";
	//1.[]访问元素
	for (int i = 0; i < str.size(); i++) 
	{
		cout << str[i] << " ";
	}
	cout << endl;
	//2.at访问元素
	for (int i = 0; i < str.size(); i++) 
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//修改字符串
	str[0] = 'x';  //修改字符串中的某一个字符，需要赋值char
	str.at(1) = 'o';
	cout << str << endl;
}

//字符串的插入和删除
void test07() 
{
	string str = "hello";
	//插入
	str.insert(1, "111");  //位置和插入的内容
	cout << str << endl;
	//删除
	str.erase(1, 3);
	cout << str << endl;  //位置和要铲除的长度
}

//字符串中子串的获取
void test08() 
{
	string str = "abcdefg";
	string substring = str.substr(1, 3);
	cout << substring << endl;

	//实用操作：正则表达式
	string email = "zhangsan@sina.com";
	int pos = email.find('@');
	string name = email.substr(0, pos);
	cout << name << endl;
}

int main() 
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();

	system("pause");
	return 0;
}