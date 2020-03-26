#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(int argc, char *argv[]) {
	while(~scanf("%d", &n))
	{
		ll ans = 0;
		priority_queue<ll, vector<ll>, greater<ll> > q;
		for(int i = 0; i < n; ++i)
		{
			ll a;
			scanf("%lld", &a);
			q.push(a);
		}
		while(q.size() > 1)
		{
			ll temp = 0;
			temp += q.top();
			q.pop();
			temp += q.top();
			q.pop();
			ans += temp;
			q.push(temp);
		} 
		printf("%lld\n", ans);
	}
	return 0;
}
