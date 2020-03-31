#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int N, maxDeep;
//统计连通块个数和统计每个节点的深度相互矛盾 
bool isFirst = true;//是否是第一次遍历（为了inq统计） 
bool flag = false;//标记是否为连通图，true为是 
struct Node{
	int index;
	int deep;
	Node(){}
	Node(int id , int d)
	{
		index = id;
		deep = d;
	}
}node; 
vector<int> G[maxn];//连通图 且无环 
vector<Node> root; 
bool inq[maxn];
//当前节点v，本次遍历的结点个数 
void bfs(int v, int &cnt)
{
	queue<Node> q;
	node = Node(v, 1);
	q.push(node);
	inq[v] = true;
	while(!q.empty())
	{
		Node now = q.front();
		q.pop();
		cnt++;//统计本次遍历的连通图结点数
		if(now.deep > maxDeep)
		{
			node.deep = now.deep;
			maxDeep = now.deep;
		} 
		for(int i = 0; i < G[now.index].size(); ++i)
		{
			int nextid = G[now.index][i];
			if(!inq[nextid])//防止本次遍历过程中重复访问 
			{
				Node temp = Node(nextid, now.deep + 1);
				q.push(temp);
				inq[nextid] = true;
			}
		}
	}
}
bool cmp(Node n1, Node n2)
{
	if(n1.deep != n2.deep)
		return n1.deep > n2.deep;
	else
		return n1.index < n2.index;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	//节点个数，连通块个数 
	int nodeCnt = 0, groupCnt = 0;
	
	for(int i = 1; i <= N; ++i)
	{
		if(isFirst)//第一次遍历 
		{
			groupCnt++;
			bfs(i, nodeCnt);
			isFirst = false;
			if(nodeCnt == N)//连通图，图内有n个结点
			{
				flag = true;
				root.push_back(node);
			}
			continue;
		}
		if(flag)//是连通图 
		{
			maxDeep = -1;
			memset(inq, false, sizeof(inq));
			bfs(i, nodeCnt);//遍历所有节点记录深度 
			root.push_back(node);
		}
		else//不是连通图 
		{
			if(!inq[i])//统计连通块的个数 
			{
				groupCnt++;
				bfs(i, nodeCnt);
			}
		}
	}
	if(flag)
	{
		sort(root.begin(), root.end(), cmp);
		maxDeep = root[0].deep;
		for(int i = 0; i < root.size(); ++i)
		{
			if(root[i].deep < maxDeep)
				break;
			else
				printf("%d\n", root[i].index);
		}
	}
	else
	{
		printf("Error: %d components\n", groupCnt);
	}
	return 0;
}
