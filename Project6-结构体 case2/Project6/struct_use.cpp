#include<iostream>
#include<string>
using namespace std;

struct Hero {
	string name;
	int age;
	string gender;
};

int main() {
	struct Hero hero[5];
	hero[0] = { "����",36,"��" };
	hero[1] = { "�ŷ�",39,"��" };
	hero[2] = { "����",19,"Ů" };
	hero[3] = { "����",28,"��" };
	hero[4] = { "��",26,"��" };
	int len = sizeof(hero) / sizeof(hero[0]);
	struct Hero temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) 
		{
			if (hero[j].age > hero[j + 1].age) {
				temp = hero[j];
				hero[j] = hero[j + 1];
				hero[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		cout << "Ӣ��������" << hero[i].name << " ���䣺" << hero[i].age << " �Ա�" << hero[i].gender << endl;
	}
}