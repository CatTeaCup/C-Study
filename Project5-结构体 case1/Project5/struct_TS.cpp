#include<iostream>
#include<string>
using namespace std;
#include<ctime>

struct Student {
	string name;
	int score;
};

struct Teacher {
	string name;
	struct Student sarray[5];
};

void givevalue(struct Teacher *p,int len) {
	string name = "12345";
	for (int i = 0; i < len; i++) {
		p[i].name = "Teacher_";
		p[i].name += name[i];
		string namet = "ABCDE";
		for (int j = 0; j < 5; j++) {
			p[i].sarray[j].name = "Student_";
			p[i].sarray[j].name += namet[j];
			int random = rand() % 40 + 60;
			p[i].sarray[j].score = random;
		}
	}
}

void printInfo(struct Teacher *p, int len) 
{
	for (int ii = 0; ii < len; ii++) {
		cout << "��ʦ�����֣�" << p[ii].name << endl;
		for (int jj = 0; jj < 5; jj++) {
			cout << "\t����ʦ����ѧ�����֣�" << p[ii].sarray[jj].name << " ��ѧ��������" << p[ii].sarray[jj].score << endl;
		}
	}
}

int main() {
	//���������
	srand((unsigned int)time(NULL));
	struct Teacher tarray[3];
	int len = sizeof(tarray) / sizeof(tarray[0]);
	givevalue(tarray, len);
	printInfo(tarray, len);
}