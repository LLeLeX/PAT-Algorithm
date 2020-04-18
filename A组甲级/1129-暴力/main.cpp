#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int N, K;
struct Rec{
	int data;
	int cnt;
}rec[maxn];
bool cmp(Rec r1, Rec r2)
{
	if(r1.cnt != r2.cnt)
		return r1.cnt > r2.cnt;
	else
		return r1.data < r2.data;
}
int cntAccess[maxn];
multimap<int, int> cnt2id;
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	int size = 0;
	for(int i = 0; i < N; ++i)
	{
		int data;
		scanf("%d", &data);
		rec[i].data = data;
		if(i != 0)
		{
			sort(rec, rec + i + 1, cmp);
			printf("%d: ", data);
			for(int j = 0; j < min(K, size); ++j)
			{
				printf("%d", rec[j].data);
				if(j < min(K, size) - 1)
					printf(" ");
				else
					printf("\n");
			}
			size++;
		}
		for(int j = 0; j <= i; ++j)
		{
			if(rec[j].data == data)
			{
				rec[j].cnt++;
				break;
			}
		}
		if(i == 0)
		{
			size++;
			continue;
		}	
	}
	return 0;
}
