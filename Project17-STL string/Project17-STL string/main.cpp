#include<iostream>
#include<string>
using namespace std;

//string  STL  ֮ǰ�ù��ܶ����
//C�е�string��ʹ��һ��char*ָ�����ά��
//C++�е�string��һ���࣬����find��copy��delete���ຯ����������char*�������ԡ�����C++��������string�Ĺ��ܣ����ʻ���ʹ��char*����ά����
void test01() 
{
	//string�����ֹ��췽��
	string s1;  //1.����һ���յ��ַ���

	const char* str = "string";
	string s2(str);  //2.ʹ���ַ������г�ʼ��
	cout << "s2=" << s2 << endl;

	string s3(s2);  //3.�������죬����s2
	cout << "s3=" << s3 << endl;

	string s4(10, 'a');  //4.n���ַ���ʼ��������aΪ''�����ǡ���
	cout << "s4=" << s4 << endl;
}

//��ֵ
void test02() 
{
	string s1;  //Ĭ�Ϲ���,=��ֵ
	s1 = "string";
	cout << s1 << endl;

	string s2 = s1;  //��������
	cout << s2 << endl;

	string s3;  //string��char
	s3 = 'a';
	cout << s3 << endl;

	string s4;  //assign��ֵ
	s4.assign("string C++", 5);
	cout << s4 << endl;
}

//�ַ���ƴ��
void test03() 
{
	string str1 = "��";
	str1 += "������Ϸ";
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

//�ַ������Һ��滻
void test04() 
{
	//����
	string str1 = "abcdefgcde";
	int pos = str1.find("cde");
	if (pos == -1) 
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else 
	{
		cout << "λ���±�Ϊ��" << pos << endl;
	}

	//���������
	pos = str1.rfind("cde");
	cout << pos << endl;

	//�滻
	str1.replace(1, 3, "1111");  //b��ʼ��bcd�滻��Ϊ1111
	cout << str1 << endl;
}

//�ַ����Ƚ�
void test05() 
{
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) 
	{
		cout << "str1 == str2" << endl;
	}
}

//�ַ�����ȡ
void test06() 
{
	string str = "hello";
	//1.[]����Ԫ��
	for (int i = 0; i < str.size(); i++) 
	{
		cout << str[i] << " ";
	}
	cout << endl;
	//2.at����Ԫ��
	for (int i = 0; i < str.size(); i++) 
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//�޸��ַ���
	str[0] = 'x';  //�޸��ַ����е�ĳһ���ַ�����Ҫ��ֵchar
	str.at(1) = 'o';
	cout << str << endl;
}

//�ַ����Ĳ����ɾ��
void test07() 
{
	string str = "hello";
	//����
	str.insert(1, "111");  //λ�úͲ��������
	cout << str << endl;
	//ɾ��
	str.erase(1, 3);
	cout << str << endl;  //λ�ú�Ҫ�����ĳ���
}

//�ַ������Ӵ��Ļ�ȡ
void test08() 
{
	string str = "abcdefg";
	string substring = str.substr(1, 3);
	cout << substring << endl;

	//ʵ�ò�����������ʽ
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