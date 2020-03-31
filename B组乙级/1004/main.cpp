#include <bits/stdc++.h>
using namespace std;
int n;
struct student{
	char name[15];
	char id[15];
	int score;
	student(){}
	student(char* str1, char* str2, int s)
	{
		strcpy(name, str1);
		strcpy(id, str2);
		score = s;
	}
};
bool cmp(student s1, student s2)
{
	return s1.score > s2.score;
}
int main(int argc, char** argv) {
	scanf("%d", &n);
	student stu[n + 3];
	for(int i = 1; i <= n; i++)
	{
		char N[15], ID[15];
		int s;
		getchar();
		scanf("%s", N);
		getchar();
		scanf("%s", ID);
		scanf("%d", &s);
		stu[i] = {N, ID, s};
	}
	sort(stu + 1, stu + n + 1, cmp);
	printf("%s %s\n", stu[1].name, stu[1].id);
	printf("%s %s", stu[n].name, stu[n].id);
	return 0;
}
