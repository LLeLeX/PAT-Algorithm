#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int inf = 0x3fffffff;
const int h = 10000;//hashɢ������ 
int N;
vector<int> G[maxn];
unordered_map<int, int> line;//���վ��������·����ÿ����·�ϵ�ÿ��վ����hashɢ�� 
unordered_map<int, int> isTransfer;//���վ���Ƿ�Ϊ��ת�㣬>=2Ϊ��ת�� 
bool vis[maxn];

int getTransfer(vector<int> a)//������תվ�ĸ��� 
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
		//��·�ϵ�ǰ��վ��pre����·��ʼfirst���յ�last 
		int M, pre, first, last;
		scanf("%d%d", &M, &pre);
		
		isTransfer[pre]++;//���� 
		first = pre;//��ʼ����ʼվ 
		
		for(int j = 0; j < M - 1; ++j)
		{
			int temp;//��·�ϵ�����վ 
			scanf("%d", &temp);
			
			isTransfer[temp]++;
			if(j == M - 2)
				last = temp;//��ʼ���յ�վ 
				
			G[pre].push_back(temp);
			G[temp].push_back(pre);
			//ɢ�б�֤��תվ������·��ͬ��hashֵ��ͬ 
			line[pre * h + temp] = line[temp * h + pre] = i;
			pre = temp;//����ǰ��վ�� 
		}
		if(first == last)//��·�Լ� 
			isTransfer[first]--;
	}
	int K;
	scanf("%d", &K);
	while(K--)
	{
		int start, end;
		scanf("%d%d", &start, &end);
	//	memset(vis, false, sizeof(vis)); //ÿ��dfs���ݶ����ʼ��������Ҫ�ظ���ʼ�� 
		tempPath.clear();
		optStep = optTransCnt = inf;
		dfs(start, 0, end, 0);
		printf("%d\n", optPath.size() - 1);//��ʼվ���� 
	

		/*int transCnt = 0;
		bool isExist = false;
		for(int i = 1; i < optPath.size(); ++i)
		{
			int station = optPath[i];
			if(isTransfer[station] >= 2)//��ǰΪ��תվ 
			{
				if(isExist == false)//��һ����תվ 
				{
					printf("Take Line#%d from %d to %d.\n", line[optPath[i - 1] * h + optPath[i]], start, optPath[i]);
					isExist = true;
					start = optPath[i];
				}
				else//�ǵ�һ����תվ 
				{
					printf("Take Line#%d from %d to %d.\n", line[optPath[i - 1] * h + optPath[i]], start, optPath[i]);
					start = optPath[i];
				}	
			}
			else//��ǰ����תվ 
			{
				if(optPath[i] == end)//�����յ� 
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
