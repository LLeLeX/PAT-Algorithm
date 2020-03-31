#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B;
int D;
int ans[100];
int main(int argc, char** argv) {
	scanf("%lld%lld%d", &A, &B, &D);
	ll sum = A + B;
	int index = 0;
	while(sum)
	{
		ans[index] = sum % D;
		sum /= D;
		index++;
	}
	if(index == 0)
	{
		printf("0");
	}
	else
	{
		for(int i = index - 1; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
	}
	return 0;
}
