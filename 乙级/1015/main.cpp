#include <bits/stdc++.h>
using namespace std;
int N, L, H;
struct student{
	char id[10];
	int de;
	int cai;
	int total;
	int flag = 5;//考生类别 
	student(){}
	student(char* str, int dd, int cc)
	{
		strcpy(id, str);
		de = dd;
		cai = cc;
		total = dd + cc;
	}
}stu[100005];

bool cmp(student s1, student s2)
{
	if(s1.flag != s2.flag)//按类标签 升序 
	{
		return s1.flag < s2.flag;
	}
	else
	{
		if(s1.total != s2.total)//按总分  降序 
		{
			return s1.total > s2.total;		
		} 
		else
		{
			if(s1.de != s2.de)//按德分 降序 
			{
				return s1.de > s2.de;
			}
			else//按准考证号  升序 
			{
				return strcmp(s1.id, s2.id) < 0;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &L, &H);
	int cntPass = N;
	for(int i = 0; i < N; i++)
	{
		char str[10];
		int d, c;
		scanf("%s %d %d", str, &d, &c);
		stu[i] = student(str, d, c);
		if(stu[i].de < L || stu[i].cai < L)
		{
			stu[i].flag = 5;
			cntPass--;		
		}
		else if(stu[i].de >= H && stu[i].cai >= H)
		{
			stu[i].flag = 1;
		} 
		else if(stu[i].de >= H && stu[i].cai < H)
		{
			stu[i].flag = 2;
		}
		else if(stu[i].de >= stu[i].cai)
		{
			stu[i].flag = 3;
		}
		else
		{
			stu[i].flag = 4;
		}
		
	}
	sort(stu, stu + N, cmp); 
	printf("%d\n", cntPass);
	for(int i = 0; i < cntPass; i++)
	{
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
		//cout << stu[i].id << " " << stu[i].de << " " << stu[i].cai << " " <<  stu[i].total << " " << stu[i].flag << endl;
	}
	return 0;
}
