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
	//筛选有效节点
	int cnt = 0;
	for(int s = start; s != -1; s = nodes[s].next)
	{
		nodes[s].flag = cnt++; 	
	} 
	sort(nodes, nodes + maxn, cmp);
	
	
	int sIndex2 = maxn, curIndex2, curIndex1;//标记第二条链的 头结点下标 & 第二条链当前节点下标 
	bool isFirst = false; 
	for(int i = 0; i < cnt; i++)
	{
		int index = abs(nodes[i].data);
		if(!vis[index])//未被访问过 
		{ 
			vis[index] = true;//标记 
			if(i == 0)//是整条链第一个节点 
			{
				nodes[i].next = -1;
			}
			else
			{
				nodes[curIndex1].next = nodes[i].addr;//前一节点的next指向自己 
				nodes[i].next = -1;//自己的next置为-1
				nodes[curIndex1].flag = i;//上一个节点的flag指向自己 
			}
			curIndex1 = i;//flag承担next节点的任务，存储数组下标 
		}
		else//已被访问过 
		{
			if(!isFirst)//这是第二条链的头结点 
			{
				isFirst = true;
				sIndex2 = i;//存储头结点下标 
				nodes[i].next = -1;
			}
			else//第二条链的后续节点 
			{
				nodes[curIndex2].next = nodes[i].addr;
				nodes[i].next = -1;
				nodes[curIndex2].flag = i;
			}
			curIndex2 = i;//存储目前第二条链的最后一个节点 
		} 
	}
	//一链 
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
	//二链
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
