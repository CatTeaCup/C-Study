#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

struct Person {
	string name;
	int gender;
	int age;
	string phone;
	string address;
};

struct AddressBook {
	struct Person person[MAX];
	int add_size = 0;
};

void ShowMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.���ͨѶ¼  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

void AddPerson(struct AddressBook * ab) 
{
	bool n = true;
	while(n == true)
	{
		cout << "��������ϵ��������" << endl;
		string name;
		cin >> name;
		ab->person[ab->add_size].name = name;
		cout << "��������ϵ���Ա�1��Ů/2���У���" << endl;
		int gender;
		cin >> gender;
		ab->person[ab->add_size].gender = gender;
		cout << "��������ϵ�����䣺" << endl;
		int age;
		cin >> age;
		ab->person[ab->add_size].age = age;
		cout << "��������ϵ�˵绰��" << endl;
		string phone;
		cin >> phone;
		ab->person[ab->add_size].phone = phone;
		cout << "��������ϵ�˵�ַ��" << endl;
		string address;
		cin >> address;
		ab->person[ab->add_size].address = address;

		ab->add_size++;

		cout << "�����Ƿ�Ҫ�������(1����/0����)��" << endl;
		int yn;
		cin >> yn;
		if (yn == 1) 
		{
			system("cls");
			ShowMenu();
		}
		else 
		{
			system("cls");
			n = false;
		}
	}
}

void ShowPerson(struct AddressBook * ab) 
{
	if (ab->add_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = 0; i < ab->add_size; i++)
		{
			cout << "������" << ab->person[i].name << "\t";
			cout << "�Ա�" << (ab->person[i].gender == 1 ? "Ů" : "��") << "\t";
			cout << "���䣺" << ab->person[i].age << "\t";
			cout << "�ֻ���" << ab->person[i].phone << "\t";
			cout << "��ַ��" << ab->person[i].address << endl;
		}
		system("pause");
		system("cls");
	}

}

int isExit(struct AddressBook* ab , string name) 
{
	for (int i = 0; i < ab->add_size; i++)
	{
		if (ab->person[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void DeletePerson(struct AddressBook* ab) 
{
	cout << "������Ҫɾ����ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int add_size;
	add_size = isExit(ab, name);
	if (add_size == -1) 
	{
		cout << "���޴���" << endl;
	}
	else 
	{
		for (int i = add_size ; i < ab->add_size ; i++)
		{
			/*ab->person[i].name = ab->person[i + 1].name;
			ab->person[i].gender = ab->person[i + 1].gender;
			ab->person[i].age = ab->person[i + 1].age;
			ab->person[i].phone = ab->person[i + 1].phone;
			ab->person[i].address = ab->person[i + 1].address;*/
			if( add_size != ab->add_size - 1)
			{
				ab->person[i] = ab->person[i + 1];
			}
			else 
			{
				ab->add_size--;
			}
		}
		cout << "ɾ���ɹ�" << endl;
		ab->add_size--;
	}
	system("pause");
	system("cls");
}

void FindPerson(struct AddressBook * ab) 
{
	cout << "������Ҫ������Ա��������" << endl;
	string name;
	cin >> name;
	int add_size = isExit(ab, name);
	if (add_size == -1) 
	{
		cout << "���޴���" << endl;
	}
	else 
	{
		cout << "������" << ab->person[add_size].name << "\t";
		cout << "�Ա�" << (ab->person[add_size].gender == 1 ? "Ů" : "��") << "\t";
		cout << "���䣺" << ab->person[add_size].age << "\t";
		cout << "�ֻ���" << ab->person[add_size].phone << "\t";
		cout << "��ַ��" << ab->person[add_size].address << endl;
	}
	system("pause");
	system("cls");
}

void ChangePerson(struct AddressBook* ab) 
{
	cout << "������Ҫ�޸��˵�������" << endl;
	string name;
	cin >> name;
	int add_size = isExit(ab, name);
	if (add_size == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		ab->person[add_size].name = name;
		cout << "������Ҫ�޸��˵��Ա�1��Ů/2���У���" << endl;
		int gender;
		cin >> gender;
		ab->person[add_size].gender = gender;
		cout << "������Ҫ�޸��˵����䣺" << endl;
		int age;
		cin >> age;
		ab->person[add_size].age = age;
		cout << "������Ҫ�޸��˵��ֻ���" << endl;
		string phone;
		cin >> phone;
		ab->person[add_size].phone = phone;
		cout << "������Ҫ�޸��˵ĵ�ַ��" << endl;
		string address;
		cin >> address;
		ab->person[add_size].address = address;
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void ClearAddressBook(struct AddressBook* ab) 
{
	cout << "ȷ��������ȫ��ͨѶ¼��(Y/N)" << endl;
	char yn;
	cin >> yn;
	if(yn == 'y' || yn == 'Y')
	{
		ab->add_size = 0;
		cout << "�����ͨѶ¼" << endl;
	}
	system("pause");
	system("cls");
}

int main() 
{
	struct AddressBook ab;
	while(true)
	{
		ShowMenu();

		int select = 0;
		cin >> select;
		switch (select) 
		{
		case 1:
			AddPerson(&ab);
			break;
		case 2:
			ShowPerson(&ab);
			break;
		case 3:
			DeletePerson(&ab);
			break;
		case 4:
			FindPerson(&ab);
			break;
		case 5:
			ChangePerson(&ab);
			break;
		case 6:
			ClearAddressBook(&ab);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã��ټ�~" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}