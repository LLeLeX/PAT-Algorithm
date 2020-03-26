#include <bits/stdc++.h>
using namespace std;
int N, K, M;
int mark[10];
struct student{
	int id;
	int score[6];//ǰ����ǵ������������ܷ� 
	int total = 0; 
	int cntper = 0;
	bool flag = false;//�Ƿ������ύ 
	int rank;
	student(){}
}stu[10005];
bool cmpTotal(student s1, student s2)
{
	return s1.total > s2.total;
} 
bool cmp(student s1, student s2)
{
	if(s1.rank != s2.rank)
	{
		return s1.rank < s2.rank;
	}
	else
	{
		if(s1.cntper != s2.cntper)
		{
			return s1.cntper > s2.cntper;
		}
		else
		{
			return s1.id < s2.id;
		}
	}
} 
int main(int argc, char *argv[]) {
	//���� 
	scanf("%d%d%d", &N, &K, &M);
	for(int i = 1; i <= K; i++)
	{
		scanf("%d", &mark[i]);
	}
	//��ʼ��
	for(int i = 1; i <= N; i++)
	{
		stu[i].id = i;
		memset(stu[i].score, -1, sizeof(stu[i].score));
	} 
	//���� 
	for(int i = 0; i < M; i++)
	{
		int idd, ques, sc;
		scanf("%d %d %d", &idd, &ques, &sc);
		if(sc == -1)//�ύʧ�� 
		{
			if(stu[idd].score[ques] > -1)
			{
				continue;
			}
			else
			{
				stu[idd].score[ques] = 0;
			}	
		}
		else//�ύ�ɹ� 
		{
			stu[idd].flag = true;
			if(sc == mark[ques])//AC 
			{
				if(stu[idd].score[ques] != mark[ques])
				{
					stu[idd].cntper++; 
				}
			}
			if(stu[idd].score[ques] == -1)//��һ���ύ���� 
			{
				stu[idd].score[ques] = sc;
				stu[idd].total += sc;
			} 
			else if(sc > stu[idd].score[ques])//�����ύ�������� 
			{
				stu[idd].total -= stu[idd].score[ques];//��ȥԭ���ĳɼ� 
				stu[idd].score[ques] = max(sc, stu[idd].score[ques]);
				stu[idd].total += stu[idd].score[ques];	//�����³ɼ�		
			}
		}	
	}
	sort(stu + 1, stu + N + 1, cmpTotal);
	stu[1].rank = 1;
	//���� 
	for(int i = 2; i <= N; i++)
	{
		if(stu[i].total != stu[i - 1].total)
		{
			stu[i].rank = i;
		}
		else
		{
			stu[i].rank = stu[i - 1].rank;
		}
	}
	//����������
	sort(stu + 1, stu + N + 1, cmp);
	for(int i = 1; i <= N; i++)
	{
		if(!stu[i].flag)
		{
			continue;
		}
		printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
		for(int j = 1; j <= K; j++)
		{
			if(stu[i].score[j] == -1)
			{
				printf(" -");
			}
			else
			{
				printf(" %d", stu[i].score[j]);
			}
		}
		printf("\n");
	} 
	return 0;
}
