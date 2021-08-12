#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//1.vector存放内置数据类型（我主要掌握迭代器）
void print_define(int val) //void就可以
{
	cout << val << endl;
}

void test01() 
{
	vector<int>vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	//迭代器
	vector<int>::iterator itbegin = vec.begin();  //迭代器，就可以理解为一个指针
	vector<int>::iterator itend = vec.end();

	//1.第一种遍历
	while (itbegin != itend) 
	{
		cout << *itbegin << endl;  //itbegin是一个指针
		itbegin++;
	}

	//2.第二种遍历
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++) 
	{
		cout << *it << endl;
	}

	//3.第三种遍历，利用STL的遍历函数
	for_each(vec.begin(), vec.end(), print_define);
}

//2.vector存放自定义数据类型
class Person
{
public:
	string name;
	int age;
	Person(string name, int age) 
	{
		this->name = name;
		this->age = age;
	}
};

void test02() 
{
	Person p1("aaa",18);  //首先定义Person，不要一上来就定义vector
	Person p2("bbb",19);
	Person p3("ccc",17);
	Person p4("ddd",16);
	Person p5("eee",15);

	vector<Person> v;
	v.push_back(p1);  //然后再插入vector
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator temp = v.begin(); temp < v.end(); temp++) //迭代器遍历
	{
		cout << " 姓名： " << (*temp).name << " 年龄： " << (*temp).age << endl;  //(*temp)是Person类型，所以.name，.age
	}

	for (vector<Person>::iterator temp = v.begin(); temp < v.end(); temp++) 
	{
		cout<< " 姓名： " << temp->name << " 年龄： " << temp->age << endl;  //*temp是Person，那么temp就是Person的指针，直接temp->name、temp->age就可以
	}

	//当vector存储Person的指针时（※）

	vector<Person*>v2;
	v2.push_back(&p1);  //当vector中不是Person而是指针的时候，定义Person还可以直接定义，放入vector中只需要取地址放入，即是它的指针
	v2.push_back(&p2);  
	v2.push_back(&p3);  
	v2.push_back(&p4);  
	v2.push_back(&p5);

	for (vector<Person*>::iterator temp = v2.begin(); temp < v2.end(); temp++) 
	{
		//(*temp)，它是Person*，是类的指针，所以(*temp)->name、->age即可
		cout << " 姓名： " << (*temp)->name << " 年龄： " << (*temp)->age << endl;
	}
}

//3.容器嵌套容器
void test03() 
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	
	for (int i = 0; i < 4; i++) 
	{
		v1.push_back(0 + i);
		v2.push_back(4 + i);
		v3.push_back(8 + i);
		v4.push_back(12 + i);
	}

	vector<vector<int>>v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	for (vector<vector<int>>::iterator it = v.begin(); it < v.end(); it++) 
	{
		//(*it)-----vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit < (*it).end(); vit++) 
		{
			cout << (*vit) << " ";
		}
		cout << endl;
	}
}

void main() 
{
	test01();
	test02();
	test03();

	system("pause");
	return;
}