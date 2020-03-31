#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int N, K, pos = 1, maxWeight;//pos����������ţ�maxweight��¼����Ȩֵ 
int group;//��¼��ͨͼ������ 
int G[maxn][maxn];//ͼ 
int weight[maxn];//������Ȩֵ�ͣ�����ͳ�����Ȩֵ 
bool vis[maxn];
map<string, int> mp;//����ӳ���� 
map<int, string> mpMirror;//���ӳ������ 
map<string, int> gang;//��֯��Ϣ 
struct Node{//ͷĿ��Ϣ 
	int index, member;
	Node(){}
	Node(int id, int m)
	{
		index = id;
		member = m;
	}
}node;


//��ǰ����v����ǰȨֵ��sum����ǰ��Ա��cnt 
void dfs(int v, int &sum, int &cnt)
{
	if(vis[v])
		return;
	vis[v] = true;
	cnt = cnt + 1;//!!!���ʵ���ǰ�ڵ�ͽ��в��������ܷ���ѭ���� 
	node.member = cnt;
	if(weight[v] > maxWeight)//��ǰ���ʵĶ���Ȩֵ�ʹ������ֵ 
	{
		maxWeight = weight[v];
		node.index = v;
	}
	for(int i = 1; i <= N; ++i)//�뵱ǰ������ͨ�ĵ� 
	{
		if(G[v][i])//�ߴ��� 
		{ 
			sum += G[v][i]; 
			G[v][i] = 0;//ɾ���ߣ���ֹ�ظ����� 
			if(!vis[i]) //û���ʹ� 
				dfs(i, sum, cnt);
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i)
	{
		string name1, name2;
		int w;
		cin >> name1 >> name2;
		scanf("%d", &w);
		if(!mp[name1])//������ 
		{
			mp[name1] = pos;//���±�1��ʼ
			mpMirror[pos] = name1;
			pos++;
		}
		if(!mp[name2])
		{
			mp[name2] = pos;
			mpMirror[pos] = name2;
			pos++;
		}
		int v1 = mp[name1], v2 = mp[name2];
		weight[v1] += w;
		weight[v2] += w;
		G[v1][v2] = w;
	}
	for(int i = 1; i <= N; ++i)
	{
		if(!vis[i])
		{
			int total = 0, count = 0;
			maxWeight = -1;
			node = Node(0, 0);
			dfs(i, total, count);
			if(total > K && count > 2)
			{
				int id = node.index;//ͷĿid 
				int member = node.member;//ͷĿ��Ա�� 
				gang[mpMirror[id]] = member;
				group++;
			}
		}
	}
	printf("%d\n", group);
	for(map<string, int>::iterator it = gang.begin(); it != gang.end(); it++)
	{
		cout << it->first;
		printf(" %d\n", it->second);
	}
	return 0;
}
