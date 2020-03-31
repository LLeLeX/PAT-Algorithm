#include <bits/stdc++.h>
using namespace std;
int N;
struct student{
	string id;
	int loc;
	int score;
	int rank;
	int locRank;
	student(){}
	student(string str, int l, int s)
	{
		id = str;
		loc = l;
		score = s;
	}
}stu[35000];
bool cmpScore(student s1, student s2)
{
	if(s1.score != s2.score)
	{
		return s1.score > s2.score;
	}
    else
	{
		return s1.id < s2.id;
	}
}
bool cmpRank(student s1, student s2)
{
	if(s1.rank != s2.rank)
	{
		return s1.rank < s2.rank;
	}
	else
	{
		return s1.id < s2.id;
	}
}
bool cmpLocRank(student s1, student s2)
{
	if(s1.loc != s2.loc)
	{
		return s1.loc < s2.loc;
	}
	else if(s1.score != s2.score)
	{
		return s1.score > s2.score;
	}
	else
	{
		return s1.id < s2.id;
	}
}
int main() {
	scanf("%d", &N);
	int cnt = 0;
	for(int i = 1; i <= N; i++)
	{
		int K = 0;
		scanf("%d", &K);
		while(K--)
		{
			char str[20];
			int s;
			scanf("%s %d", str, &s);
			stu[cnt++] = student(str, i, s);
		}
	}
	//地区排名
	sort(stu, stu + cnt, cmpLocRank);
	int cntLoc = 1;//计一个地区的人数 
	stu[0].locRank = 1;
	for(int i = 1; i < cnt; i++)
	{
		int temp = stu[i - 1].loc;
		if(stu[i].loc == temp)//是同一地区
		{
			cntLoc++;
			if(stu[i].score == stu[i - 1].score)
			{
				stu[i].locRank = stu[i - 1].locRank;
			}
			else
			{
				stu[i].locRank = cntLoc;
			}
		}
		else//不是同一地区 
		{
			stu[i].locRank = 1;
			cntLoc = 1; 
		} 
	} 
	sort(stu, stu + cnt, cmpScore);
	//最终排名 
	stu[0].rank = 1;
	for(int i = 1; i < cnt; i++)
	{
		if(stu[i].score == stu[i - 1].score)
		{
			stu[i].rank = stu[i - 1].rank;
		}
		else
		{
			stu[i].rank = i + 1;
		}
	}
	sort(stu, stu + cnt, cmpRank);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
	{
		cout << stu[i].id << " ";
		printf("%d %d %d\n", stu[i].rank, stu[i].loc, stu[i].locRank);
	}
	return 0;
}
