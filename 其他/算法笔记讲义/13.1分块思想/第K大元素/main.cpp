#include <bits/stdc++.h>
using namespace std;
int block[500], table[100005], blockNum, eleNum;
int N, K, range, num[10];
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &range, &K);
	eleNum = (int)sqrt(1.0 * range + 1);
	blockNum = (int)sqrt(1.0 * N) + 1;
	for(int i = 1; i <= N; ++i)
	{
		int n;
		scanf("%d", &n);
		num[i] = n;
		table[n]++;
		block[n / blockNum]++;
	}
	int sum = 0, ans = 0;
	bool cmplt = false;
	for(int i = 0; i < blockNum; ++i)
	{
		if(cmplt)
			break;
		if(sum + block[i] < K)//小于K 
		{
			sum += block[i];
		}
		else//第K大的元素在block[i]中 
		{
			for(int j = i * eleNum; j < (i + 1) * eleNum; ++j)//对block[i]范围内的数字遍历 
			{//以保证每个不同的数字只遍历一次，不会多次遍历同一个数字 
				if(sum + table[j] < K)
				{
					sum += table[j];
				} 
				else
				{
					ans = j;
					cmplt = true;
					break;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
