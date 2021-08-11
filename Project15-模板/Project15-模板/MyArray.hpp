#pragma once
#include<iostream>
using namespace std;

template<class T>  //使用模板，用来表示指针pArray
class MyArray 
{
private:
	T* pArray;  //指向堆区开辟的数组
	int m_Capacity;  //容量
	int m_Size;  //数组目前的尺寸
public:
	//有参构造
	MyArray(int capacity) //有参构造  ④写有参构造就要写析构函数，一对。有参构造-析构函数-拷贝构造-operator=
	{
		cout << "MyArray的有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pArray = new T[this->m_Capacity];  //①堆区开辟数组，堆区开辟大小是容量的大小
	}

	//拷贝构造
	MyArray(const MyArray& arr)  //拷贝构造
	{
		cout << "MyArray的拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;  //⑤this为指针，所以用->；而arr为引用，所以只能用.
		this->m_Size = arr.m_Size;
		//this->pArray = arr->pArray;  //浅拷贝，这一句两个对象的指针会指向同一个地址，因此这句会出错

		//深拷贝
		this->pArray = new T[arr.m_Capacity];

		//将arr中的值复制过来
		for (int i = 0; i < arr.m_Size; i++) 
		{
			this->pArray[i] = arr.pArray[i];
		}
	}

	//operator=，防止赋值时的浅拷贝问题
	MyArray& operator=(const MyArray& arr) //浅拷贝会出现问题。MyArray&之所以返回值是引用，是因为要返回指针，这样才能链式法则：a=b=c
	{
		cout << "MyArray的operator=调用" << endl;
		//比拷贝构造多的一步：因为非构造函数，所以this->pArray在堆区已经有值了，需要先判断堆区是否为空
		if (this->pArray != NULL) 
		{
			delete[] this->pArray;
			this->pArray = NULL;
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pArray = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++) 
		{
			this->pArray[i] = arr.pArray[i];
		}
		return *this;  //③把自身作为一个指针返回
	}

	//尾插法
	void Push_Back(const T& val) 
	{
		if (this->m_Size == this->m_Capacity) //如果达到了容量
		{
			return;  //返回空值
		}
		this->pArray[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back()  //引用的方式传值，主函数中调用仅需正常传值即可，这里的函数定义为引用 
	{
		if (this->m_Size == 0) 
		{
			return;
		}
		this->m_Size--;  //逻辑删除
	}

	//通过下标的方式访问数组中的元素
	T& operator[](int index)  //重载[]下标的函数 
	{
		return this->pArray[index];  //直接返回该下标值，并且函数类型为T&，引用的方式
	}

	//返回数组容量
	int returnCapacity() 
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int returnSize() 
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray() //析构函数
	{
		cout << "MyArray的析构函数调用" << endl;
		if (this->pArray != NULL) 
		{
			delete [] this->pArray;  //②由于pArray不是堆区中的1个位置，所以delete应该[]
			this->pArray = NULL;  //delete后应该将指针置为空，防止野指针（指针乱指）
		}
	}
};