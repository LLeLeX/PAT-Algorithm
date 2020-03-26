#include <bits/stdc++.h>
using namespace std;
int n, x;
int arr[205];
int pos[100010];
int binarySearch(int a[], int left, int right, int key)
{
	int mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == key)
		{
			return mid;
		}
		else if(a[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
int main(int argc, char *argv[]) {
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			int num;
			scanf("%d", &num);
			pos[num] = i;
			arr[i] = num;
		}
		scanf("%d", &x); 
		sort(arr, arr + n);
		int ans = binarySearch(arr, 0, n - 1, x);
		if(ans == -1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", pos[arr[ans]]);
		} 
	}	
	return 0;
}
