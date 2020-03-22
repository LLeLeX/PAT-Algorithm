#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s1[200005], s2[200005];
int n1, n2, median;
ll ans;
int main(int argc, char *argv[]) {
	scanf("%d", &n1);
	for(int i = 0; i < n1; i++)
	{
		scanf("%lld", &s1[i]);
	}
	scanf("%d", &n2);
	for(int i = 0; i < n2; i++)
	{
		scanf("%lld", &s2[i]);
	}
	median = (n1 + n2 - 1) / 2;
	int cnt = -1, a = 0, b =0;
	bool complt = false;  
	while(a < n1 && b < n2)
	{
		int temp;
		if(s1[a] < s2[b])
		{
			temp = s1[a];
			a++;
			cnt++;
		}
		else
		{
			temp = s2[b];
			b++;
			cnt++;	
		}
		if(cnt == median)
		{
			ans = temp;
			complt = true;
			break;
		}
	}
	if(!complt)
	{
		while(a < n1)
		{
			cnt++;
			if(cnt == median)
			{
				ans = s1[a];
				break;
			}
			a++;
		}
		while(b < n2)
		{
			cnt++;
			if(cnt == median)
			{
				ans = s2[b];
				break;
			}
			b++;
		}
	}
	printf("%lld", ans);
	return 0;
}
