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
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空通讯录  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

void AddPerson(struct AddressBook * ab) 
{
	bool n = true;
	while(n == true)
	{
		cout << "请输入联系人姓名：" << endl;
		string name;
		cin >> name;
		ab->person[ab->add_size].name = name;
		cout << "请输入联系人性别（1：女/2：男）：" << endl;
		int gender;
		cin >> gender;
		ab->person[ab->add_size].gender = gender;
		cout << "请输入联系人年龄：" << endl;
		int age;
		cin >> age;
		ab->person[ab->add_size].age = age;
		cout << "请输入联系人电话：" << endl;
		string phone;
		cin >> phone;
		ab->person[ab->add_size].phone = phone;
		cout << "请输入联系人地址：" << endl;
		string address;
		cin >> address;
		ab->person[ab->add_size].address = address;

		ab->add_size++;

		cout << "请问是否要继续添加(1：是/0：否)：" << endl;
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
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = 0; i < ab->add_size; i++)
		{
			cout << "姓名：" << ab->person[i].name << "\t";
			cout << "性别：" << (ab->person[i].gender == 1 ? "女" : "男") << "\t";
			cout << "年龄：" << ab->person[i].age << "\t";
			cout << "手机：" << ab->person[i].phone << "\t";
			cout << "地址：" << ab->person[i].address << endl;
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
	cout << "请输入要删除联系人的姓名：" << endl;
	string name;
	cin >> name;
	int add_size;
	add_size = isExit(ab, name);
	if (add_size == -1) 
	{
		cout << "查无此人" << endl;
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
		cout << "删除成功" << endl;
		ab->add_size--;
	}
	system("pause");
	system("cls");
}

void FindPerson(struct AddressBook * ab) 
{
	cout << "请输入要查找人员的姓名：" << endl;
	string name;
	cin >> name;
	int add_size = isExit(ab, name);
	if (add_size == -1) 
	{
		cout << "查无此人" << endl;
	}
	else 
	{
		cout << "姓名：" << ab->person[add_size].name << "\t";
		cout << "性别：" << (ab->person[add_size].gender == 1 ? "女" : "男") << "\t";
		cout << "年龄：" << ab->person[add_size].age << "\t";
		cout << "手机：" << ab->person[add_size].phone << "\t";
		cout << "地址：" << ab->person[add_size].address << endl;
	}
	system("pause");
	system("cls");
}

void ChangePerson(struct AddressBook* ab) 
{
	cout << "请输入要修改人的姓名：" << endl;
	string name;
	cin >> name;
	int add_size = isExit(ab, name);
	if (add_size == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		ab->person[add_size].name = name;
		cout << "请输入要修改人的性别（1：女/2：男）：" << endl;
		int gender;
		cin >> gender;
		ab->person[add_size].gender = gender;
		cout << "请输入要修改人的年龄：" << endl;
		int age;
		cin >> age;
		ab->person[add_size].age = age;
		cout << "请输入要修改人的手机：" << endl;
		string phone;
		cin >> phone;
		ab->person[add_size].phone = phone;
		cout << "请输入要修改人的地址：" << endl;
		string address;
		cin >> address;
		ab->person[add_size].address = address;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}

void ClearAddressBook(struct AddressBook* ab) 
{
	cout << "确认真的清空全部通讯录？(Y/N)" << endl;
	char yn;
	cin >> yn;
	if(yn == 'y' || yn == 'Y')
	{
		ab->add_size = 0;
		cout << "已清空通讯录" << endl;
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
			cout << "欢迎下次使用，再见~" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}