#include <bits/stdc++.h>
using namespace std;
int n, arr[25], ans;
//index:��Ʒ�±꣬v����ǰ��� 
void dfs(int index, int v)
{
	//�ݹ�߽�
	if(index > n)
		return; 
	if(v == 40)
	{
		ans++;
		return;
	}
	if(v + arr[index] <= 40)//ע�⣡�� 
		dfs(index + 1, v + arr[index]);//���� 
	dfs(index + 1, v);//������ 
}
int main(int argc, char *argv[]) {
	while(1)
	{
		scanf("%d", &n); 
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		dfs(0, 0);
		printf("%d\n", ans); 
	}
	return 0;
}
