#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int N;
map<int, bool> mp;
int maxNum = -1;
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		mp[num] = true;
		maxNum = max(maxNum, num);
	}
	int ans;
	if(maxNum < 0)
	{
		printf("1");
		return 0;
	}
	for(int i = 1; i <= maxNum + 1; ++i)
	{
		if(mp[i] == false)
		{
			ans = i;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
