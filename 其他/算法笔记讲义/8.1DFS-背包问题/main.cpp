#include <bits/stdc++.h>
using namespace std;
int n, V, w[10], c[10];//n����Ʒ����������V��ÿ����Ʒ����w[i]��ÿ����Ʒ��ֵc[i]
int maxValue;//��¼�����е�����ֵ 
void dfs(int index, int sumW, int sumC)
{
	if(index == n)//�Ѿ���n����Ʒ������� 
	{
		return;
	}
	dfs(index + 1, sumW, sumC);//���������Ʒ
	if(sumW + w[index] <= V)
	{
		if(sumC + c[index] > maxValue)
			maxValue = sumC + c[index];
		dfs(index + 1, sumW + w[index], sumC + c[index]);//�������Ʒ 
	}	
}
int main(int argc, char** argv) {
	scanf("%d%d", &n, &V);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &w[i]); 
	} 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	dfs(0, 0, 0);
	printf("C:%d\n", maxValue);
	return 0;
}
