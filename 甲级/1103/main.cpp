#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
int N, K, P;
int maxSum;
bool cmplt;//����Ƿ��н� 
int arr[500];
vector<int> temp, ans, fac;
int poww(int a, int b)//������ 
{
	int aa = 1;
	while(b > 0)
	{
		if(b & 1)
		{
			aa = aa * a;	
		} 
		a = a * a;
		b >>= 1;
	} 
	return aa;
} 
//index����ǰ���֣�nowK����ǰ������sum����ǰ������ ,total:�ܺ� 
void dfs(int index, int nowK, int sum, int total)
{
	if(fac[index] > N || total > N)
	{
		return;
	}
	if(nowK == K)//��������߽� 
	{
		if(total == N)//�Ӻʹﵽ�߽� 
		{
			cmplt = true;
			if(sum > maxSum)//�Ƚϵ����� 
			{
				ans = temp;
				maxSum = sum;
			}
		}
		return;
	}
	if(index - 1 >= 0)
	{
		temp.push_back(index);
		dfs(index, nowK + 1, sum + index, total + fac[index]);//��Ӹ����� 
		temp.pop_back();
		dfs(index - 1, nowK, sum, total);//����Ӹ�����
	}
	
}
bool cmp(int a, int b)
{
	return a > b;
}
void init()
{
	int t = 0;
	while(1)
	{
		int tmpPow = poww(t, P);
		if(tmpPow > N)
		{
			break;
		}
		fac.push_back(tmpPow);
		t++;
	}
}
int main(){
	scanf("%d%d%d", &N, &K, &P);
	init();
	dfs(fac.size() - 1, 0, 0, 0);
	if(!cmplt)
	{
		printf("Impossible\n");
	}
	else
	{
		sort(ans.begin(), ans.end(), cmp);
		printf("%d = ", N);
		for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
		{
			if(it < ans.end() - 1)
				printf("%d^%d + ", *it, P);
			else
				printf("%d^%d", *it, P);
		}
	}
	return 0;
}
