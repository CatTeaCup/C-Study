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
	hero[0] = { "关羽",36,"男" };
	hero[1] = { "张飞",39,"男" };
	hero[2] = { "貂蝉",19,"女" };
	hero[3] = { "赵云",28,"男" };
	hero[4] = { "马超",26,"男" };
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
		cout << "英雄姓名：" << hero[i].name << " 年龄：" << hero[i].age << " 性别：" << hero[i].gender << endl;
	}
}