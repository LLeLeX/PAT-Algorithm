#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
int ans = 0;
ll nums[100010];
void twoPointers(ll a[], int left, int right)
{
	while(left <= right)
	{
		ll key = a[left] * m;
		if(right == n)
		{
			ans = max(ans, right - left);
			break;
		}
		if(a[right] > key)
		{
			ans = max(ans, right - left);
		}
		else if(a[right] <= key)
		{
			right++;
			continue;
		}
		left++;
	} 
}
int main(int argc, char *argv[]) {
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &nums[i]);
	}
	sort(nums, nums + n);
	twoPointers(nums, 0, 1);
	printf("%d", ans);
	return 0;
}
