#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int N, M;
vector<int> v[maxn];
unordered_map<int, bool> vis;
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
	}
	vector<int> goods;
	while(M--)
	{
		int K;
		scanf("%d", &K);
		goods.clear();
		vis.clear();
		bool cmplt = true;
		for(int i = 0; i < K; ++i)
		{
			int x;
			scanf("%d", &x);
			goods.push_back(x);
			vis[x] = true;
		}
		for(int i = 0; i < goods.size(); ++i)
		{
			if(cmplt == false)
				break;
			int a = goods[i];
			if(v[a].size() == 0)
				continue;
			else
			{
				for(int j = 0; j < v[a].size(); ++j)
				{
					int b = v[a][j];
					if(cmplt == false)
						break;
					if(vis[b] == true)
						cmplt = false;
				}
			}
		}
		if(cmplt == false)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
