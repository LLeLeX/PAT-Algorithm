#include <bits/stdc++.h>
using namespace std;
int N, C;
struct student{
	char id[10];
	char name[20];
	int score;
	student(){}
	student(char *ID, char *n, int s){
		strcpy(id, ID);
		strcpy(name, n);
		score = s;
	}
}stu[100005]; 
void display()
{
	for(int i = 0; i < N; i++)
	{
		printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
}
bool cmp1(student s1, student s2)
{
	return strcmp(s1.id, s2.id) < 0;
}
bool cmp2(student s1, student s2)
{
	if(strcmp(s1.name, s2.name))
	{
		return strcmp(s1.name, s2.name) < 0;
	}
	else
	{
		return strcmp(s1.id, s2.id) < 0;
	}
}
bool cmp3(student s1, student s2)
{
	if(s1.score != s2.score)
	{
		return s1.score < s2.score;
	}
	else
	{
		return strcmp(s1.id, s2.id) < 0;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &C);
	for(int i = 0; i < N; i++)
	{
		char str[20], ID[10];
		int s;
		scanf("%s %s %d", ID, str, &s);
		stu[i] = student(ID, str, s);
	}
	switch(C)
	{
		case 1:
			sort(stu, stu + N, cmp1);
			display();
			break;
		case 2:
			sort(stu, stu + N, cmp2);
			display();
			break;
		case 3:
			sort(stu, stu + N, cmp3);
			display();
			break;
	}
	return 0;
}
