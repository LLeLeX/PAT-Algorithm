#include <bits/stdc++.h>
using namespace std;
int N, M, K;
set<int> arr[55];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &M);
		for(int j = 0; j < M; j++)
		{
			int num;
			scanf("%d", &num);
			arr[i].insert(num);
		} 
	}
	scanf("%d", &K);
	while(K--)
	{
		int a, b, cnt = 0, total = 0;//记录两个集合中不同元素的个数 
		scanf("%d%d", &a, &b);
		int n1 = arr[a].size(), n2 = arr[b].size(); 
		/*if(n1 > n2)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		total = max(n1, n2);//元素多的做计数的初始值 */
		cnt = 0;
		total = arr[b].size();//用不同的集合分别做遍历和计数的初始值即可 
		for(set<int>::iterator it = arr[a].begin(); it != arr[a].end(); it++)//用元素少的find遍历 
		{
			int temp = *it;
			//set<int>::iterator it2 = find(arr[b].begin(), arr[b].end(), temp);
			set<int>::iterator it2 = arr[b].find(temp);
			if(it2 != arr[b].end())
			{
				cnt++;
			}
			else
			{
				total++;
			}
		}
		double rate = cnt * 1.0000 / total * 100;
		printf("%.1f%%\n", rate);
	}
	return 0;
}
