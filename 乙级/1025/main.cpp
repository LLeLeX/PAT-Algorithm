#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct Node{
	int address, data, next;
	int order = maxn;
}nodes[maxn];
int L, total, K;
bool cmp(Node n1, Node n2)
{
	return n1.order < n2.order;
}
void displayList()
{
	printf("-----------------\n");
	int addr = L;
	while(addr != -1)
	{
		printf("%05d %d %05d Order:%d\n", nodes[addr].address, nodes[addr].data, nodes[addr].next, nodes[addr].order);
		addr = nodes[addr].next;
	}
}
void displayStruct()
{
	printf("-----------------\n");
	for(int i = 0; i < 10; i++)
	{
		printf("%05d %d %05d Order:%d\n", nodes[i].address, nodes[i].data, nodes[i].next, nodes[i].order);
	}
}
int main(int argc, char** argv) {
	scanf("%d%d%d", &L, &total, &K);
	for(int i = 0; i < total; i++)
	{
		int aa, dd, nn;
		scanf("%d%d%d", &aa, &dd, &nn);
		nodes[aa].address = aa;
		nodes[aa].data = dd;
		nodes[aa].next = nn;
	}
	int addr = L, cnt = 0;
	while(addr != -1)
	{
		nodes[addr].order = cnt++;
		addr = nodes[addr].next;
	}
	sort(nodes, nodes + maxn, cmp);
	//displayStruct();
	
	for(int i = 0; i < cnt / K; i++)
	{
		for(int j = (i + 1) * K - 1; j > i * K; j--)
		{
			printf("%05d %d %05d\n", nodes[j].address, nodes[j].data, nodes[j - 1].address);
		}
		//完整块的最后一个结点
		printf("%05d %d ", nodes[i * K].address, nodes[i * K].data);
		if(i < cnt / K - 1)
		{
			printf("%05d\n", nodes[(i + 2) * K - 1].address);
		}
		else
		{
			if(cnt % K == 0)
			{
				printf("-1\n");
			}
			else
			{
				printf("%05d\n", nodes[(i + 1) * K].address);
				for(int j = cnt / K * K; j < cnt; j++)
				{
					printf("%05d %d ", nodes[j].address, nodes[j].data);
					if(j < cnt - 1)
					{
						printf("%05d\n", nodes[j].next);
					}
					else
					{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}
