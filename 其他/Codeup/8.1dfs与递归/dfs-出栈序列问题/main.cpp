#include <bits/stdc++.h>
using namespace std;
int n, ans;
//push:��ջ����,pop:��ջ����,size:ջ��Ԫ����Ŀ
void dfs(int push, int pop, int size)
{
	if(pop == n && push == n)//�Ѿ���ջn��ջ�� 
	{
		ans++;
		return;
	}
	if(size < n && push < n)//ջ������������ջ 
		dfs(push + 1, pop, size + 1);
	if(size > 0 && pop < n)//ջ����, ���Գ�ջ 
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
