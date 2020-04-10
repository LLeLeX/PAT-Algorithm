#include <bits/stdc++.h>
using namespace std;
int N;
set<int> friendid;
int getid(int n)
{
	int ans = 0;
	while(n)
	{
		int ret = n % 10;
		ans += ret;
		n /= 10;
	}
	return ans;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		int id = getid(num);
		friendid.insert(id);
	}
	printf("%d\n", friendid.size());
	int cnt = 0;
	for(set<int>::iterator it = friendid.begin(); it != friendid.end(); ++it)
	{
		printf("%d", *it);
		cnt++;
		if(cnt < friendid.size())
			printf(" ");
	}
	return 0;
}
