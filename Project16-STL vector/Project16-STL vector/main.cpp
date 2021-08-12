#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//1.vector��������������ͣ�����Ҫ���յ�������
void print_define(int val) //void�Ϳ���
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

	//������
	vector<int>::iterator itbegin = vec.begin();  //���������Ϳ������Ϊһ��ָ��
	vector<int>::iterator itend = vec.end();

	//1.��һ�ֱ���
	while (itbegin != itend) 
	{
		cout << *itbegin << endl;  //itbegin��һ��ָ��
		itbegin++;
	}

	//2.�ڶ��ֱ���
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++) 
	{
		cout << *it << endl;
	}

	//3.�����ֱ���������STL�ı�������
	for_each(vec.begin(), vec.end(), print_define);
}

//2.vector����Զ�����������
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
	Person p1("aaa",18);  //���ȶ���Person����Ҫһ�����Ͷ���vector
	Person p2("bbb",19);
	Person p3("ccc",17);
	Person p4("ddd",16);
	Person p5("eee",15);

	vector<Person> v;
	v.push_back(p1);  //Ȼ���ٲ���vector
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator temp = v.begin(); temp < v.end(); temp++) //����������
	{
		cout << " ������ " << (*temp).name << " ���䣺 " << (*temp).age << endl;  //(*temp)��Person���ͣ�����.name��.age
	}

	for (vector<Person>::iterator temp = v.begin(); temp < v.end(); temp++) 
	{
		cout<< " ������ " << temp->name << " ���䣺 " << temp->age << endl;  //*temp��Person����ôtemp����Person��ָ�룬ֱ��temp->name��temp->age�Ϳ���
	}

	//��vector�洢Person��ָ��ʱ������

	vector<Person*>v2;
	v2.push_back(&p1);  //��vector�в���Person����ָ���ʱ�򣬶���Person������ֱ�Ӷ��壬����vector��ֻ��Ҫȡ��ַ���룬��������ָ��
	v2.push_back(&p2);  
	v2.push_back(&p3);  
	v2.push_back(&p4);  
	v2.push_back(&p5);

	for (vector<Person*>::iterator temp = v2.begin(); temp < v2.end(); temp++) 
	{
		//(*temp)������Person*�������ָ�룬����(*temp)->name��->age����
		cout << " ������ " << (*temp)->name << " ���䣺 " << (*temp)->age << endl;
	}
}

//3.����Ƕ������
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