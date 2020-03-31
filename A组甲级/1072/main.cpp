#include <bits/stdc++.h>
using namespace std;
const int maxn = 1015;
const int inf = 0x3fffffff;
int N, M, K, D;
struct Node{
	int v;
	int dist;
	Node(){}
	Node(int vv, int dd)
	{
		v = vv;
		dist = dd;
	}
}node;
vector<Node> G[maxn];
vector<int> station;
bool hashtable[maxn];//GN�Ƿ���뵽station�� 
int d[maxn];
bool vis[maxn];
int str2int(char str[])
{
	int result = 0;
	if(str[0] != 'G')
	{
		sscanf(str, "%d", &result);
	}	
	else
	{
		int len = strlen(str);
		if(len < 3)
			result = N + str[1] - '0';
		else
			result = N + 10;
		if(!hashtable[result])//��ֹ�ظ�����vector 
		{
			station.push_back(result);
			hashtable[result] = true;
		}
	}
	return result;
}
void Dijkstra(int s)
{
	int len = station.size();
	for(int i = 0; i < N + len; ++i)
	{
		int u, udist, mindist = inf;
		for(int j = 1; j <= N + len; ++j)
		{
			if(!vis[j] && d[j] < mindist)
			{
				u = j;
				udist = mindist = d[j];
			}
		}
		vis[u] = true;
		for(int k = 0; k < G[u].size(); ++k)
		{
			int v = G[u][k].v;
			int vdist = G[u][k].dist;
			if(!vis[v])
			{
				if(udist + vdist < d[v])
				{
					d[v] = udist + vdist;
				}
			}
		}
	}
}
double getAverage()
{
	double sum = 0, result = 0;
	for(int i = 1; i <= N; ++i)
		sum += d[i];
	result = sum / N * 1.0;
	return result;
}
int main() {
	scanf("%d%d%d%d", &N, &M, &K, &D);
	for(int i = 0; i < K; ++i)
	{
		char p1[10], p2[10];
		int w;
		scanf("%s %s %d", p1, p2, &w);
		int u, v;
		u = str2int(p1);
		v = str2int(p2);
		G[u].push_back(Node(v, w));
		G[v].push_back(Node(u, w));
	}
	int len = station.size();
	bool flag = false;//����Ƿ��н� 
	int optdist = -1;//��Ѿ���optmindist,����Ѱ����̾���mindist 
	int optIndex;//��Ѿ�����±� 
	double optaver;
	for(int i = 0; i < len; ++i)
	{
		double mindist = inf, aver = 0;
		int start = station[i];
		fill(d, d + maxn, inf);
		memset(vis, false, sizeof(vis));
		d[start] = 0;
		Dijkstra(start);//�õ���Դ�㵽���е����̾��� 
		
		
		//********���Ƚ� 
		bool isValid = true;//����Ƿ�����Ч��Χ�� 
		for(int j = 1; j <= N; ++j)//Ѱ�����·������Сֵmindist 
		{
			/*if(j == i)//Դ�㱾�� !!!i���Ƕ��㣬�Ǽ���վ 
				continue;*/
			if(d[j] > D)//�з��ݲ��ڷ�Χ�� 
			{ 
				isValid = false;
				break;
			}
			if(d[j] < mindist)
				mindist = d[j];
			aver += 1.0 * d[j] / N;
		}
		if(!isValid)//�з��ݲ��ڷ�Χ�� 
			continue;

		flag = true;//��Դ����Ч�������н� 
		if(mindist > optdist)//�Ƚϳ�����mindist 
		{
			optIndex = start;
			optdist = mindist;
			optaver = aver;//����ƽ��ֵ 
		}	
		else if(mindist == optdist && aver < optaver)
		{
			optIndex = start;
			optaver = aver;
		}
	}
	if(flag)
	{
		printf("G%d\n", optIndex - N);
		printf("%.1f %.1f", optdist * 1.0, optaver);
	}
	else
		printf("No Solution");
	return 0;
}
