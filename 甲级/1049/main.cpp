#include <bits/stdc++.h>
using namespace std;
int N, ans;

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int a = 1, ans = 0;
	int left, now, right;
	while(N / a != 0)
	{
		left = N / (a * 10);
		now = (N / a) % 10;
		right = N % a;
		//cout << left << " " << now << " " << right << endl;
		
		if(now == 0)
		{
			ans += left * a;
		}
		else if(now == 1)
		{
			ans += left * a + right + 1;
		}
		else
		{
			ans += (left + 1) * a;
		}
		a *= 10;
	}
	printf("%d", ans);
	return 0;
}
