#include <bits/stdc++.h>
using namespace std;
int N;
int scoreFe = -1, scoreMa = 100;
int indexFe = -1, indexMa = -1;
struct student{
	char name[20];
	char gen;
	char id[20];
	int score;
	student(){}
}stu[10005];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%s %c %s %d", stu[i].name, &stu[i].gen, stu[i].id, &stu[i].score);
		if(stu[i].gen == 'F')//女生
		{
			if(scoreFe < stu[i].score)//最高分 
			{
				scoreFe = stu[i].score;
				indexFe = i;
			}
		}
		else//男生 
		{
			if(scoreMa > stu[i].score)//最低分 
			{
				scoreMa = stu[i].score;
				indexMa = i; 
			}
		}
	}
	bool flag = false;
	if(indexFe == -1)
	{
		printf("Absent\n");
		flag = true;
	}
	else
	{
		printf("%s %s\n", stu[indexFe].name, stu[indexFe].id);
	}
	if(indexMa == -1)
	{
		printf("Absent\n");
		flag = true;
	}
	else
	{
		printf("%s %s\n", stu[indexMa].name, stu[indexMa].id);
	}
	if(flag)
	{
		printf("NA");
	}
	else
	{
		printf("%d", stu[indexFe].score - stu[indexMa].score);
	}
	return 0;
}
