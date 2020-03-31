#include <bits/stdc++.h>
using namespace std;
int N, K;
struct Node{
	int start;//������ʱ�������ʾ 
	int d;//����ʱ�������ʾ 
	Node(){}
	Node(int ss, int dd)
	{
		start = ss;
		d = dd;
	}
}nodes[10005];
struct Window{
	int end = 8 * 3600;//��ǰ�û��Ľ���ʱ�� 
	bool status = true;//true:����,false:������ 
	Window(){}
	Window(int e, bool s)
	{
		end = e;
		status = s;
	}
}windows[105];


bool cmp(Node n1, Node n2)
{
	return n1.start < n2.start;
}
//ʱ��������ʾ������00:00:00�����룩 
int getSecond(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	int sum = 0, num = 0;//�ȴ�ʱ��������sum,������num 
	int open = 8 * 3600;//���п���ʱ��
	int end = 17 * 3600;
	for(int i = 0; i < N; ++i)
	{
		int h, m ,s ,d;
		scanf("%d:%d:%d %d", &h, &m, &s, &d);
		int ss = getSecond(h, m, s);
		int dd = d * 60;
		if(ss > end)//���������� 
			continue;
		nodes[num++] = Node(ss, dd);//��Ч�ͻ� 
	}
	sort(nodes, nodes + num, cmp);
	
	for(int i = 0; i < num; ++i)
	{
		//���ڱ��:winID���������ʱ��minEndTime 
		int winID = -1, minEndTime = 0x3fffffff;
		for(int j = 0; j < K; ++j)
		{
			if(windows[j].end < minEndTime)
			{
				minEndTime = windows[j].end;
				winID = j;
			}
		}
		
		if(windows[winID].end <= nodes[i].start)
		{
			windows[winID].end = nodes[i].start + nodes[i].d; 
		}
		else
		{
			sum += (windows[winID].end - nodes[i].start); 
			windows[winID].end += nodes[i].d;
		}
	}
	
	
	
	if(num == 0)
		printf("0.0");
	else
		printf("%.1f", 1.0 * sum / num / 60);
	return 0;
}
