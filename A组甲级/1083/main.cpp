#include <bits/stdc++.h>
using namespace std;
int N;
struct student{
	char name[15];
	char id[15];
	int score;
	student(){}
	student(char *s1, char *s2, int s)
	{
		strcpy(name, s1);
		strcpy(id, s2);
		score = s;
	}
}stu[100005];
bool cmp(student s1, student s2)
{
	return s1.score > s2.score;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		char s1[15], s2[15];
		int sc;
		scanf("%s %s %d", s1, s2, &sc);
		stu[i] = student(s1, s2, sc);
	}
	sort(stu, stu + N, cmp);
	int minsc, maxsc; 
	bool flag = false;
	scanf("%d%d", &minsc, &maxsc);
	for(int i = 0; i < N; i++)
	{
		if(stu[i].score >= minsc && stu[i].score <= maxsc)
		{
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = true;
		}
	} 
	if(!flag)
	{
		printf("NONE");
	}
	return 0;
}
