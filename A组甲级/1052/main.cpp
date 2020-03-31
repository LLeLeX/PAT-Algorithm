#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int N, start;
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
	if(n1.flag != n2.flag)
	{
		return n1.flag < n2.flag;
	}
	else
	{
		return n1.data < n2.data;
	}
}
int main(int argc, char** argv) {
	scanf("%d%d", &N, &start);
	for(int i = 0; i < N; i++)
	{
		int aa, dd ,nn;
		scanf("%d%d%d", &aa, &dd, &nn);
		nodes[aa] = Node(aa, dd, nn);
	}
	//ɸѡ��Ч�ڵ� 
	int cnt = 0;//��Ч�ڵ���� 
	for(int p = start; p != -1; p = nodes[p].next)
	{
		nodes[p].flag = 0;
		cnt++;
	}
	if(cnt == 0)
	{
		printf("0 -1");
	}
	else
	{
		sort(nodes, nodes + maxn, cmp);//���ܼ�N����Ϊ�Ǵ�node[0]˳�������� 
		printf("%d %05d\n", cnt, nodes[0].addr);
		for(int i = 0; i < cnt; i++)
		{
			if(i < cnt - 1)//�������һ���ڵ� 
			{
				printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i + 1].addr);
			}
			else//���һ���ڵ� 
			{
				printf("%05d %d -1\n", nodes[i].addr, nodes[i].data);
			}
		}
	}
	return 0;
}
