#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Ppp
{
public:
	T1 m_age;
	T2 m_name;
	Ppp(T1 age, T2 name);
	void show();
};
template<class T1, class T2>
Ppp<T1, T2>::Ppp(T1 age, T2 name)
{
	this->m_name = name;
	this->m_age = age;
}
template<class T1, class T2>
void Ppp<T1, T2>::show()
{
	cout << "name:" << this->m_name << endl;
	cout << "age:" << this->m_age << endl;
}