#include <bits/stdc++.h>
using namespace std;
int n, ans;
//push:入栈次数,pop:出栈次数,size:栈内元素数目
void dfs(int push, int pop, int size)
{
	if(pop == n && push == n)//已经出栈n，栈空 
	{
		ans++;
		return;
	}
	if(size < n && push < n)//栈不满，可以入栈 
		dfs(push + 1, pop, size + 1);
	if(size > 0 && pop < n)//栈不空, 可以出栈 
		dfs(push, pop + 1, size - 1); 
}
int main() {
	while(scanf("%d", &n) != EOF)
	{
		ans = 0;
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
