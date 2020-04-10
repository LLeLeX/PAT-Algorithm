#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int N, M;
int couple[maxn];
vector<int> guests, alone;
bool inparty[maxn];
bool cmp(int a, int b)
{
	return a < b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		couple[a] = b;
		couple[b] = a;//³õÊ¼»¯couple 
	}
	scanf("%d", &M);
	for(int i = 0; i < M; ++i)
	{
		int g;
		scanf("%d", &g);
		inparty[g] = true;
		guests.push_back(g);
	}
	for(int i = 0; i < guests.size(); ++i)
	{
		int guy = guests[i];
		int partner = couple[guy];
		if(inparty[partner] == true)
			continue;
		alone.push_back(guy);
	}
	printf("%d\n", alone.size());
	sort(alone.begin(), alone.end(), cmp);
	for(int i = 0; i < alone.size(); ++i)
	{
		printf("%05d", alone[i]);
		if(i < alone.size() - 1)
			printf(" ");
	}
	return 0;
}
