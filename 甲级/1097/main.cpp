#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int start, N;
bool vis[10005];
struct Node{
	int addr, data, next;
	int flag = maxn;
	Node(){}
	Node(int aa, int dd, int nn){
		addr = aa;
		data = dd;
		next = nn;
	}
}nodes[maxn];
bool cmp(Node n1, Node n2)
{
	return n1.flag < n2.flag;
}
int main() {
	scanf("%d%d", &start, &N);
	for(int i = 0; i < N; i++)
	{
		int aa, dd, nn;
		scanf("%d%d%d", &aa, &dd, &nn);
		nodes[aa] = Node(aa, dd, nn);
	}
	//ɸѡ��Ч�ڵ�
	int cnt = 0;
	for(int s = start; s != -1; s = nodes[s].next)
	{
		nodes[s].flag = cnt++; 	
	} 
	sort(nodes, nodes + maxn, cmp);
	
	
	int sIndex2 = maxn, curIndex2, curIndex1;//��ǵڶ������� ͷ����±� & �ڶ�������ǰ�ڵ��±� 
	bool isFirst = false; 
	for(int i = 0; i < cnt; i++)
	{
		int index = abs(nodes[i].data);
		if(!vis[index])//δ�����ʹ� 
		{ 
			vis[index] = true;//��� 
			if(i == 0)//����������һ���ڵ� 
			{
				nodes[i].next = -1;
			}
			else
			{
				nodes[curIndex1].next = nodes[i].addr;//ǰһ�ڵ��nextָ���Լ� 
				nodes[i].next = -1;//�Լ���next��Ϊ-1
				nodes[curIndex1].flag = i;//��һ���ڵ��flagָ���Լ� 
			}
			curIndex1 = i;//flag�е�next�ڵ�����񣬴洢�����±� 
		}
		else//�ѱ����ʹ� 
		{
			if(!isFirst)//���ǵڶ�������ͷ��� 
			{
				isFirst = true;
				sIndex2 = i;//�洢ͷ����±� 
				nodes[i].next = -1;
			}
			else//�ڶ������ĺ����ڵ� 
			{
				nodes[curIndex2].next = nodes[i].addr;
				nodes[i].next = -1;
				nodes[curIndex2].flag = i;
			}
			curIndex2 = i;//�洢Ŀǰ�ڶ����������һ���ڵ� 
		} 
	}
	//һ�� 
	int sIndex1 = 0;
	for(int p = sIndex1; p != -1; p = nodes[p].flag)
	{
		if(nodes[p].next != -1)
		{
			printf("%05d %d %05d\n", nodes[p].addr, nodes[p].data, nodes[p].next);
		}	
		else
		{
			printf("%05d %d %d\n", nodes[p].addr, nodes[p].data, nodes[p].next);
			break;
		}
	}
	//����
	if(sIndex2 != maxn)
	{
		for(int p = sIndex2; p != -1; p = nodes[p].flag)
		{
			if(nodes[p].next != -1)
			{
				printf("%05d %d %05d\n", nodes[p].addr, nodes[p].data, nodes[p].next);
			}	
			else
			{
				printf("%05d %d %d\n", nodes[p].addr, nodes[p].data, nodes[p].next);
				break;
			}
				
		}
	}
	return 0;
}
