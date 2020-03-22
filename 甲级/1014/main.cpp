#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const int maxn = 1005;
int N, M, K, Q;
int serveTime[maxn], customer[maxn];//����ʱ��,�ͻ�����ʱ�� 
int open = 8 * 60, close = 17 * 60;
struct Window{
	int frontTime = open;//���׿ͻ�����ʱ�� 
	int endTime = open;//���ڽ���ʱ�� 
	queue<int> q;
}windows[25];//��ʼ���������ǽṹ�����飬��Ҫ��ʼ�� 
//����ʱ��m������ʱ��d 
void display(int m, int d)//�������ʱ�� 
{
	if(m - d < close)
	{
		int hh = m / 60;
		int mm = m % 60;
		printf("%02d:%02d\n", hh, mm);
	}
	else//����ʱ�䳬��17:00���sorry 
		printf("Sorry\n");
}

int main(int argc, char *argv[]) {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	//�±�ȫ��0��ʼ 
	for(int i = 0; i < K; ++i)
	{
		scanf("%d", &serveTime[i]);
	}
	
	
	int index = 0;//��ǰΪ��ӵĿͻ��±�
	//����ȡģ�������±��0��ʼ 
	for(int i = 0; i < min(N * M, K); ++i)//�Ȱ����ж�������,���K��С������ֶ��в�������� 
	{
		int winID = index % N;
		windows[winID].q.push(index);//�ͻ����
		windows[winID].endTime += serveTime[index];
		if(index < N)//�ж϶��׿ͻ� 
			windows[winID].frontTime =  windows[winID].endTime;
		customer[index] = windows[winID].endTime;
		++index;
	} 
	//���ж�����������δ��ӵĿͻ� 
	for(; index < K; ++index)
	{
		int winID = -1, minFrontTime = inf;
		for(int i = 0; i < N; ++i)//�ҽ�������Ķ��� 
		{
			if(windows[i].frontTime < minFrontTime)
			{
				winID = i;
				minFrontTime = windows[i].frontTime;
			}
		}
		windows[winID].q.pop();//���׳���  
		int cusID = windows[winID].q.front();
		windows[winID].frontTime = customer[cusID];//���¶��׽���ʱ�� 
		windows[winID].q.push(index);//���
		windows[winID].endTime += serveTime[index];//���´��ڽ���ʱ��
		customer[index] = windows[winID].endTime;//
	}
	
	
	for(int i = 1; i <= Q; ++i)
	{
		int query;
		scanf("%d", &query);
		display(customer[query - 1], serveTime[query - 1]);//�±��0��ʼ 
	}
	return 0;
}
