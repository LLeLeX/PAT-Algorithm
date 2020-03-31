#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int N, maxDeep;
//ͳ����ͨ�������ͳ��ÿ���ڵ������໥ì�� 
bool isFirst = true;//�Ƿ��ǵ�һ�α�����Ϊ��inqͳ�ƣ� 
bool flag = false;//����Ƿ�Ϊ��ͨͼ��trueΪ�� 
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
vector<int> G[maxn];//��ͨͼ ���޻� 
vector<Node> root; 
bool inq[maxn];
//��ǰ�ڵ�v�����α����Ľ����� 
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
		cnt++;//ͳ�Ʊ��α�������ͨͼ�����
		if(now.deep > maxDeep)
		{
			node.deep = now.deep;
			maxDeep = now.deep;
		} 
		for(int i = 0; i < G[now.index].size(); ++i)
		{
			int nextid = G[now.index][i];
			if(!inq[nextid])//��ֹ���α����������ظ����� 
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
	//�ڵ��������ͨ����� 
	int nodeCnt = 0, groupCnt = 0;
	
	for(int i = 1; i <= N; ++i)
	{
		if(isFirst)//��һ�α��� 
		{
			groupCnt++;
			bfs(i, nodeCnt);
			isFirst = false;
			if(nodeCnt == N)//��ͨͼ��ͼ����n�����
			{
				flag = true;
				root.push_back(node);
			}
			continue;
		}
		if(flag)//����ͨͼ 
		{
			maxDeep = -1;
			memset(inq, false, sizeof(inq));
			bfs(i, nodeCnt);//�������нڵ��¼��� 
			root.push_back(node);
		}
		else//������ͨͼ 
		{
			if(!inq[i])//ͳ����ͨ��ĸ��� 
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
