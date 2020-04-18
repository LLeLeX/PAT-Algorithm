#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int inf = 0x3fffffff;
const int h = 10000;//hash散列运算 
int N;
vector<int> G[maxn];
unordered_map<int, int> line;//标记站点所在线路，对每条线路上的每个站点做hash散列 
unordered_map<int, int> isTransfer;//标记站点是否为中转点，>=2为中转点 
bool vis[maxn];

int getTransfer(vector<int> a)//计算中转站的个数 
{
	int result = 0;
	for(int i = 1; i < a.size(); ++i)
	{
		int pos = a[i];
		if(isTransfer[pos] >= 2)
			result++;
	}
	return result;
}

vector<int> tempPath, optPath;
int optStep = inf, optTransCnt = inf;
void dfs(int now, int lastline, int E, int step)
{
	if(now == E)
	{
		tempPath.push_back(now);
		int tempTransCnt = getTransfer(tempPath);
		if(tempPath.size() < optStep)
		{
			optStep = tempPath.size();
			optTransCnt = step;
			/*cout << "path:";
			for(int i = 0; i < tempPath.size(); ++i)
				cout << tempPath[i] << " "; 
			cout << endl <<tempTransCnt << " " << step << endl; */
			optPath = tempPath;
		}
		else if(tempPath.size() == optStep && step < optTransCnt)
		{
			/*cout << "path:";
			for(int i = 0; i < tempPath.size(); ++i)
				cout << tempPath[i] << " "; 
			cout << endl <<tempTransCnt << " " << step << endl;*/
			optTransCnt = step;
			optPath = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	vis[now] = true;
	tempPath.push_back(now);
	for(int v = 0; v < G[now].size(); ++v)
	{
		int pos = G[now][v];
		/*if(vis[pos] == false)
			dfs(pos, E, step + 1);*/
		if(vis[pos] == false)
		{
			if(line[now * h + pos] != lastline)
				dfs(pos, line[now * h + pos], E, step + 1);
			else
				dfs(pos, lastline, E, step);
		}
	}
	vis[now] = false;
	tempPath.pop_back();
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		//线路上的前驱站点pre，线路起始first，终点last 
		int M, pre, first, last;
		scanf("%d%d", &M, &pre);
		
		isTransfer[pre]++;//自增 
		first = pre;//初始化起始站 
		
		for(int j = 0; j < M - 1; ++j)
		{
			int temp;//线路上的其余站 
			scanf("%d", &temp);
			
			isTransfer[temp]++;
			if(j == M - 2)
				last = temp;//初始化终点站 
				
			G[pre].push_back(temp);
			G[temp].push_back(pre);
			//散列保证中转站所在线路不同，hash值不同 
			line[pre * h + temp] = line[temp * h + pre] = i;
			pre = temp;//更新前驱站点 
		}
		if(first == last)//环路自减 
			isTransfer[first]--;
	}
	int K;
	scanf("%d", &K);
	while(K--)
	{
		int start, end;
		scanf("%d%d", &start, &end);
	//	memset(vis, false, sizeof(vis)); //每次dfs回溯都会初始化，不需要重复初始化 
		tempPath.clear();
		optStep = optTransCnt = inf;
		dfs(start, 0, end, 0);
		printf("%d\n", optPath.size() - 1);//起始站不算 
	

		/*int transCnt = 0;
		bool isExist = false;
		for(int i = 1; i < optPath.size(); ++i)
		{
			int station = optPath[i];
			if(isTransfer[station] >= 2)//当前为中转站 
			{
				if(isExist == false)//第一个中转站 
				{
					printf("Take Line#%d from %d to %d.\n", line[optPath[i - 1] * h + optPath[i]], start, optPath[i]);
					isExist = true;
					start = optPath[i];
				}
				else//非第一个中转站 
				{
					printf("Take Line#%d from %d to %d.\n", line[optPath[i - 1] * h + optPath[i]], start, optPath[i]);
					start = optPath[i];
				}	
			}
			else//当前非中转站 
			{
				if(optPath[i] == end)//到达终点 
				{
					printf("Take Line#%d from %d to %d.\n", line[optPath[i - 1] * h + optPath[i]], start, end);
				} 
			} 
		}*/
		
		int startLine = line[optPath[0] * h + optPath[1]];
		int startPoint = optPath[0];
		for(int i = 1; i < optPath.size() - 1; ++i)
		{
			if(line[optPath[i] * h + optPath[i + 1]] != startLine)
			{
				printf("Take Line#%d from %04d to %04d.\n", startLine, startPoint, optPath[i]);
				startLine = line[optPath[i] * h + optPath[i + 1]];
				startPoint = optPath[i];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", startLine, startPoint, end);
	}
	return 0;
}
