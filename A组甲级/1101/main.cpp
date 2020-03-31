#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int arr[100005];
int MAX[100005];
int MIN[100005];
int main(int argc, char *argv[]) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int maxnum = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > maxnum)
		{
			MAX[i] = arr[i];
			maxnum = arr[i];
		}
		else
		{
			MAX[i] = maxnum;
		}
	}
	int minnum = arr[n - 1];
	for(int i = n - 1; i >= 0; i--)
	{
		if(arr[i] < minnum)
		{
			MIN[i] = arr[i];
			minnum = arr[i];
		}
		else
		{
			MIN[i] = minnum;
		}
	}
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == MAX[i] && MAX[i] == MIN[i])
		{
			cnt++;
			arr[index++] = arr[i];
		}
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
	{
		printf("%d", arr[i]);
		if(i < cnt - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
	/*for(int i = 0; i < n; i++)
	{
		cout << MAX[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout << MIN[i] << " ";
	}*/
	return 0;
}
