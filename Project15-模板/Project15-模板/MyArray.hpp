#pragma once
#include<iostream>
using namespace std;

template<class T>  //ʹ��ģ�壬������ʾָ��pArray
class MyArray 
{
private:
	T* pArray;  //ָ��������ٵ�����
	int m_Capacity;  //����
	int m_Size;  //����Ŀǰ�ĳߴ�
public:
	//�вι���
	MyArray(int capacity) //�вι���  ��д�вι����Ҫд����������һ�ԡ��вι���-��������-��������-operator=
	{
		cout << "MyArray���вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pArray = new T[this->m_Capacity];  //�ٶ����������飬�������ٴ�С�������Ĵ�С
	}

	//��������
	MyArray(const MyArray& arr)  //��������
	{
		cout << "MyArray�Ŀ����������" << endl;
		this->m_Capacity = arr.m_Capacity;  //��thisΪָ�룬������->����arrΪ���ã�����ֻ����.
		this->m_Size = arr.m_Size;
		//this->pArray = arr->pArray;  //ǳ��������һ�����������ָ���ָ��ͬһ����ַ������������

		//���
		this->pArray = new T[arr.m_Capacity];

		//��arr�е�ֵ���ƹ���
		for (int i = 0; i < arr.m_Size; i++) 
		{
			this->pArray[i] = arr.pArray[i];
		}
	}

	//operator=����ֹ��ֵʱ��ǳ��������
	MyArray& operator=(const MyArray& arr) //ǳ������������⡣MyArray&֮���Է���ֵ�����ã�����ΪҪ����ָ�룬����������ʽ����a=b=c
	{
		cout << "MyArray��operator=����" << endl;
		//�ȿ���������һ������Ϊ�ǹ��캯��������this->pArray�ڶ����Ѿ���ֵ�ˣ���Ҫ���ж϶����Ƿ�Ϊ��
		if (this->pArray != NULL) 
		{
			delete[] this->pArray;
			this->pArray = NULL;
		}

		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pArray = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++) 
		{
			this->pArray[i] = arr.pArray[i];
		}
		return *this;  //�۰�������Ϊһ��ָ�뷵��
	}

	//β�巨
	void Push_Back(const T& val) 
	{
		if (this->m_Size == this->m_Capacity) //����ﵽ������
		{
			return;  //���ؿ�ֵ
		}
		this->pArray[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void Pop_Back()  //���õķ�ʽ��ֵ���������е��ý���������ֵ���ɣ�����ĺ�������Ϊ���� 
	{
		if (this->m_Size == 0) 
		{
			return;
		}
		this->m_Size--;  //�߼�ɾ��
	}

	//ͨ���±�ķ�ʽ���������е�Ԫ��
	T& operator[](int index)  //����[]�±�ĺ��� 
	{
		return this->pArray[index];  //ֱ�ӷ��ظ��±�ֵ�����Һ�������ΪT&�����õķ�ʽ
	}

	//������������
	int returnCapacity() 
	{
		return this->m_Capacity;
	}

	//���������С
	int returnSize() 
	{
		return this->m_Size;
	}

	//��������
	~MyArray() //��������
	{
		cout << "MyArray��������������" << endl;
		if (this->pArray != NULL) 
		{
			delete [] this->pArray;  //������pArray���Ƕ����е�1��λ�ã�����deleteӦ��[]
			this->pArray = NULL;  //delete��Ӧ�ý�ָ����Ϊ�գ���ֹҰָ�루ָ����ָ��
		}
	}
};