#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int school[105];
int lastRank[105]; 
vector<vector<int> > accept(105);
struct student{
	int id;
	int ge;
	int gi;
	int total;
	int choices[6];
	int rank;
	student(){}
}stu[40005];
bool cmpTotal(student s1, student s2)//按总分排，总分相同按ge排 
{
	if(s1.total != s2.total)
	{
		return s1.total > s2.total;
	}
	else
	{
		return s1.ge > s2.ge;
	}
}
bool cmpRank(student s1, student s2)
{
	return s1.rank < s2.rank;
} 
int main(int argc, char *argv[]) {
	//输入 
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &school[i]);
	}
	for(int i = 0; i < N; i++)
	{
		stu[i].id = i;
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		stu[i].total = stu[i].ge + stu[i].gi;
		for(int j = 0; j < K; j++)
		{
			scanf("%d", &stu[i].choices[j]);
		}
	}
	//排名 
	sort(stu, stu + N, cmpTotal);
	stu[0].rank = 1;
	for(int i = 1; i < N; i++)
	{
		if(stu[i].total != stu[i - 1].total)//总分不等 
		{
			stu[i].rank = i + 1;
		}
		else
		{
			if(stu[i].ge != stu[i - 1].ge)
			{
				stu[i].rank = i + 1; 
			}
			else
			{
				stu[i].rank = stu[i - 1].rank;
			}
		}
	}
	sort(stu, stu + N, cmpRank);
	for(int i = 0; i < N; i++)//对申请遍历 
	{
		for(int j = 0; j < K; j++)//对志愿遍历 
		{
			int index = stu[i].choices[j];
			if(school[index])//有名额 
			{
				accept[index].push_back(stu[i].id);
				lastRank[index] = stu[i].rank;
				school[index]--;
				break;
			}
			else//无名额 
			{
				//与上一个人名次相同，报考学校相同 
				//！！！！错误原因，其上一个学生虽然排名相同，并不一定要去同一所学校 
				//所以要跟去同一所学校的上一个学生比排名 
				if(i != 0 && stu[i].rank == lastRank[index])
				{
					accept[index].push_back(stu[i].id);
					lastRank[index] = stu[i].rank;
					break;	
				} 
				else
				{
					continue;
				}
			}
		}
	} 
	//输出
	for(int i = 0; i < M; i++)
	{
		if(accept[i].size())
		{
			bool flag = false;
			sort(accept[i].begin(), accept[i].end());
			for(vector<int>::iterator it = accept[i].begin(); it != accept[i].end(); it++)
			{
				if(!flag)
				{
					printf("%d", *it);
					flag = true;
				}
				else
				{
					printf(" %d", *it);
				}
			}
		}
		printf("\n");
	} 
	return 0;
}
