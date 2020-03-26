#include <bits/stdc++.h>
using namespace std;
int N, K, X;//N个整数，选出K个数，之和为X 
int num[10];
int maxSqu;//过程中最大的平方和 
vector<int> temp, ans;
//当前处理编号index，当前已经选择的数的个数nowK，当前已选整数之和sum，当前平方和sumSqu 
void dfs(int index, int nowK, int sum, int sumSqu)
{
	if(nowK == K && sum == X)//刚好K个数，且刚好为X 
	{
		if(sumSqu > maxSqu)
		{
			maxSqu = sumSqu;
			ans = temp;	//？？可以vector直接赋值？ 
		}
		return; 
	} 
	if(index == N || nowK > K || sum > X)
		return;
	//选择index号数字 
	temp.push_back(num[index]);
	dfs(index + 1, nowK + 1, sum + num[index], sumSqu + num[index] * num[index]);
	//dfs(index, nowK + 1, sum + num[index], sumSqu + num[index] * num[index]);//可重复 
	temp.pop_back();
	//不选择index号数字
	dfs(index + 1, nowK, sum, sumSqu); 
}
int main(int argc, char** argv) {
	scanf("%d%d%d", &N, &K, &X);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	dfs(0, 0, 0, 0);
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		printf("%d ", *it);
	}
	return 0;
}
