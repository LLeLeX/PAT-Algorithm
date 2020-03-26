#include <bits/stdc++.h>
using namespace std;
struct student{
	char name[20];
	int score;
	student(){}//¢Ù 
	student(char *n, int s)//¢Ú 
	{
		strcpy(name, n);
		score = s;
	}
}stu[10];
void display(){
	for(int i = 0; i < 3; i++)
	{
		cout << stu[i].name << " " << stu[i].score << endl;
	}
}
int main(int argc, char** argv) {
	for(int i = 0; i < 3; i++)
	{
		/*char str[10];
		int sc;
		scanf("%c %d", str, &sc);
		stu[i] = student(str, sc);*///¢Ú 
		scanf("%c %d", &stu[i].name, &stu[i].score);//¢Ù 
		getchar();
	}
	display();
	return 0;
}
