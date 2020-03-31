#include <bits/stdc++.h>
using namespace std;
int N;
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int up = 6, down = 4, stop = 5;
	int pos = 0, ans = 0;
	for(int i = 1; i <= N; ++i)
	{
		int floors;
		scanf("%d", &floors);
		if(floors > pos)//ÏòÉÏ×ß 
			ans += (floors - pos) * up + stop;
		else
			ans += (pos - floors) * down + stop;
		pos = floors;
	}
	printf("%d", ans);
	return 0;
}
