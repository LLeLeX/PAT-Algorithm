#include <bits/stdc++.h>
using namespace std;
struct student{
	char id[10];
	int scC, scM, scE, av;
	int rankC, rankM, rankE, rankAv;
	student(){}
}stu[2200];
int N, M;
bool cmpC(student s1, student s2)
{
	return s1.scC > s2.scC;
}
bool cmpM(student s1, student s2)
{
	return s1.scM > s2.scM;
}
bool cmpE(student s1, student s2)
{
	return s1.scE > s2.scE;
}
bool cmpAv(student s1, student s2)
{
	return s1.av > s2.av;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		scanf("%s %d %d %d", stu[i].id, &stu[i].scC, &stu[i].scM, &stu[i].scE);
		stu[i].av = (stu[i].scC + stu[i].scM + stu[i].scE) / 3;
	}
	//¶ÔCÅÅÐò 
	sort(stu, stu + N, cmpC);
	stu[0].rankC = 1;
	for(int i = 1; i < N; i++)
	{
		if(stu[i].scC == stu[i - 1].scC)
		{
			stu[i].rankC = stu[i - 1].rankC;
		}
		else
		{
			stu[i].rankC = i + 1;
		}
	}
	//¶ÔMÅÅÐò 
	sort(stu, stu + N, cmpM);
	stu[0].rankM = 1;
	for(int i = 1; i < N; i++)
	{
		if(stu[i].scM == stu[i - 1].scM)
		{
			stu[i].rankM = stu[i - 1].rankM;
		}
		else
		{
			stu[i].rankM = i + 1;
		}
	}
	//¶ÔEÅÅÐò 
	sort(stu, stu + N, cmpE);
	stu[0].rankE = 1;
	for(int i = 1; i < N; i++)
	{
		if(stu[i].scE == stu[i - 1].scE)
		{
			stu[i].rankE = stu[i - 1].rankE;
		}
		else
		{
			stu[i].rankE = i + 1;
		}
	}
	//¶ÔAVÅÅÐò 
	sort(stu, stu + N, cmpAv);
	stu[0].rankAv = 1;
	for(int i = 1; i < N; i++)
	{
		if(stu[i].av == stu[i - 1].av)
		{
			stu[i].rankAv = stu[i - 1].rankAv;
		}
		else
		{
			stu[i].rankAv = i + 1;
		}
	}
	while(M--)
	{
		char str[20];
		scanf("%s", str);
		bool cmplt = false;
		for(int i = 0; i < N; i++)
		{
			if(!(strcmp(stu[i].id, str)))
			{
				char c;
				int r;
				if(stu[i].rankAv <= stu[i].rankC)
				{
					c = 'A', r = stu[i].rankAv;
				}
				else
				{
					c = 'C', r = stu[i].rankC;
				}
				
				if(stu[i].rankM < r)
				{
					c = 'M', r = stu[i].rankM;
				}
				if(stu[i].rankE < r)
				{
					c = 'E', r = stu[i].rankE;
				}
				printf("%d %c\n", r, c);
				cmplt = true;
				break;
			}
		}
		if(!cmplt)
		{
			printf("N/A\n");
		}
	}
	return 0;
}
