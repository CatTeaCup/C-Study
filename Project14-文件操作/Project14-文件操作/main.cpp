#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void test01() 
{
	//1.����ͷ�ļ�fstream
	//2.����������
	ofstream ofs;  //ofstream����fstream�еĿ�д�࣬ifstream�ǿɶ��࣬fstream�ǿɶ���д��
	//3.ָ���򿪷�ʽ
	ofs.open("D:\C++\Personal\Project14-�ļ�����\test01.txt", ios::out);
	//4.д����
	ofs << "����������" << endl;
	ofs << "���䣺18" << endl;
	ofs << "�Ա���" << endl;
	//5.�ر��ļ�
	ofs.close();
}

//���ļ�
void test02() 
{
	//1.
	ifstream ifs;  //2.
	ifs.open("test01.txt", ios::in);  //3. 2��3����һ��������python�е�fp=open('','rb')
	if (!ifs.is_open()) // �ж��Ƿ�ɹ���
	{
		cout << "��ȡ�ļ�ʧ��" << endl;
	}
	//char buf[1024] = { 0 };
	//while (ifs >> buf) // 4.�����ݣ�4�ַ�����  4.������Python��fb.read()��fb.write(~~~)
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

//д�������ļ�
class Person 
{
public:
	char m_name[64];
	int m_age;
};

void test03() 
{
	//1.
	ofstream ofs("test02.txt", ios::out|ios::binary); //2+3,ʡ��open��Ϊofs��Ĺ��캯��
	Person p = {"����", 18};
	ofs.write((const char*)&p, sizeof(Person));  //4.�����Ƶ�д�룬��ͬ��ofs<<��д��
	ofs.close();  //5.
}

//���������ļ�
void test04() 
{
	//1.
	ifstream ifs("test02.txt", ios::in | ios::binary);  //2.+3.
	if (!ifs.is_open()) 
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char *)&p, sizeof(Person));  //4.�����ƵĶ�ȡ����ȡ�Ķ�������Ҫ�½�һ����ͬ�ṹ����Person����write��ͬ���ڣ�writeΪ(const char *)���ͣ���readΪ(char*)����-----��ָ���ַ
	cout << "����Ϊ��" << p.m_age << "  ����Ϊ��" << p.m_name << endl;
	ifs.close();
}

int main() 
{
	//д�ļ�
	//test01();

	//���ļ�
	test02();
	//Python:
	//1. fp = open('','rb')   ('wb')
	//2. fp.read()            (fp.write(~~~))
	//3. fp.close()
	//C++
	//1. ����ͷ�ļ�
	//2. ifstream ifs             (ofstream ofs)
	//3. ifs.open("",ios::in)     (ios::out)
	//4. while(ifs>>buf)          (ofs<<)
	//5. ifs.close()              (ofs.close())

	//д�������ļ�
	test03();

	//���������ļ�
	test04();

	system("pause");
	return 0;
}