#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int head, N, K;
struct Node{
	int addr;
	int data;
	int next;
	int level = maxn; 
	Node(){}
	Node(int aa, int dd, int nn)
	{
		addr = aa;
		data = dd;
		next = nn;
	}
}nodes[maxn];

bool cmp(Node n1, Node n2)
{
	if(n1.level != maxn && n2.level != maxn)
	{
		if(n1.data < 0 && n2.data >= 0 || n1.data >= 0 && n2.data < 0)
			return n1.data < n2.data;	
		else if(n1.data < 0 && n2.data < 0)
			return n1.level < n2.level;
		else
		{
			if(n1.data <= K && n2.data > K || n1.data > K && n2.data <= K)
				return n1.data < n2.data;
			else
				return n1.level < n2.level;
		}
	}
	else
		return n1.level < n2.level;
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &head, &N, &K);
	for(int i = 0; i < N; ++i)
	{
		int aa, dd, nn;
		scanf("%d%d%d", &aa, &dd, &nn);
		nodes[aa] = Node(aa, dd, nn);
	}
	int pos = head;
	int count = 0;//筛选有效节点 
	while(pos != -1)
	{
		nodes[pos].level = count++;
		pos = nodes[pos].next;
	}
	sort(nodes, nodes + maxn, cmp);
	for(int i = 0; i < count; ++i)
	{
		if(i < count - 1)
			printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i + 1].addr);
		else
			printf("%05d %d -1\n", nodes[i].addr, nodes[i].data);
	}
	return 0;
}
