#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int N;
int num[maxn];
int leftmax[maxn], rightmin[maxn];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int minnum = 0x3fffffff, maxnum = -1;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);
		if(num[i] > maxnum)
		{
			maxnum = num[i];
		}
		leftmax[i] = maxnum;
	}
	for(int i = N - 1; i >= 0; --i)
	{
		if(num[i] < minnum)
		{
			minnum = num[i];
		}
		rightmin[i] = minnum;
	}
	vector<int> ans;
	for(int i = 0; i < N; ++i)
	{
		if(num[i] == leftmax[i] && leftmax[i] == rightmin[i])
			ans.push_back(num[i]);
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i)
	{
		printf("%d", ans[i]);
		if(i < ans.size() - 1)
			printf(" ");
	}
	if(ans.size() == 0)
		printf("\n");
	return 0;
}
