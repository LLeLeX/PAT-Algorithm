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
bool cmpTotal(student s1, student s2)//���ܷ��ţ��ܷ���ͬ��ge�� 
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
	//���� 
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
	//���� 
	sort(stu, stu + N, cmpTotal);
	stu[0].rank = 1;
	for(int i = 1; i < N; i++)
	{
		if(stu[i].total != stu[i - 1].total)//�ֲܷ��� 
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
	for(int i = 0; i < N; i++)//��������� 
	{
		for(int j = 0; j < K; j++)//��־Ը���� 
		{
			int index = stu[i].choices[j];
			if(school[index])//������ 
			{
				accept[index].push_back(stu[i].id);
				lastRank[index] = stu[i].rank;
				school[index]--;
				break;
			}
			else//������ 
			{
				//����һ����������ͬ������ѧУ��ͬ 
				//������������ԭ������һ��ѧ����Ȼ������ͬ������һ��Ҫȥͬһ��ѧУ 
				//����Ҫ��ȥͬһ��ѧУ����һ��ѧ�������� 
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
	//���
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
