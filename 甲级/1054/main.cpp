#include <bits/stdc++.h>
using namespace std;
int M, N;
map<int, int> record;
int ans = -1;
int main(int argc, char *argv[]) {
	scanf("%d%d", &M, &N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			int num;
			scanf("%d", &num);
			record[num]++;
		}
	}
	for(map<int, int>::iterator it = record.begin(); it != record.end(); it++)
	{
		if(it->second > ans && it->second > (M * N) / 2)
		{
			ans = it->first;
		}
	}
	printf("%d", ans);
	return 0;
}
