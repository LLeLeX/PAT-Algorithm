#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int K;
//行visx，斜率为正的对角线vis1，斜率为负的对角线vis2 
bool visx[maxn], vis1[maxn], vis2[maxn];
int arr[maxn];
int main(int argc, char *argv[]) {
	scanf("%d", &K);
	while(K--)
	{
		int N;
		scanf("%d", &N);
		memset(visx, false, sizeof(visx));
		memset(vis1, false, sizeof(vis1));
		memset(vis2, false, sizeof(vis2));
		memset(arr, 0, sizeof(arr));
		bool isSolution = true;
		for(int i = 1; i <= N; ++i)
		{
			scanf("%d", &arr[i]);
			if(visx[arr[i]] == false)
				visx[arr[i]] = true;
			else
				isSolution = false;
			//正斜率，行列相减为常数；负斜率相加为常数
			int temp1 = i - arr[i] + N;
			int temp2 = i + arr[i];
			if(vis1[temp1] == true || vis2[temp2] == true)
				isSolution = false;
			else
				vis1[temp1] = vis2[temp2] = true;
		} 
		if(isSolution == false)
			printf("NO\n");
		else
			printf("YES\n");
	
	
	}
	return 0;
}
