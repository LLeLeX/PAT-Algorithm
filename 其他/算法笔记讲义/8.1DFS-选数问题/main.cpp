#include <bits/stdc++.h>
using namespace std;
int N, K, X;//N��������ѡ��K������֮��ΪX 
int num[10];
int maxSqu;//����������ƽ���� 
vector<int> temp, ans;
//��ǰ������index����ǰ�Ѿ�ѡ������ĸ���nowK����ǰ��ѡ����֮��sum����ǰƽ����sumSqu 
void dfs(int index, int nowK, int sum, int sumSqu)
{
	if(nowK == K && sum == X)//�պ�K�������Ҹպ�ΪX 
	{
		if(sumSqu > maxSqu)
		{
			maxSqu = sumSqu;
			ans = temp;	//��������vectorֱ�Ӹ�ֵ�� 
		}
		return; 
	} 
	if(index == N || nowK > K || sum > X)
		return;
	//ѡ��index������ 
	temp.push_back(num[index]);
	dfs(index + 1, nowK + 1, sum + num[index], sumSqu + num[index] * num[index]);
	//dfs(index, nowK + 1, sum + num[index], sumSqu + num[index] * num[index]);//���ظ� 
	temp.pop_back();
	//��ѡ��index������
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
