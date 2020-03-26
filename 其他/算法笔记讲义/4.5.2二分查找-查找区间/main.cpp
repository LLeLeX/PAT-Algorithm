#include <bits/stdc++.h>
using namespace std;
int arr[105];
int lowerBound(int a[], int left, int right, int x)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(a[mid] >= x)
		{
			right = mid;
		} 
		else if(a[mid] < x)
		{
			left = mid + 1;
		}
	}
	return left;
	//return right;//均可 
}
int upperBound(int a[], int left, int right, int x)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(a[mid] > x)
		{
			right = mid;
		}
		else if(a[mid] <= x)
		{
			left = mid + 1;
		}
	} 
	return left;
}
int binarySearch(int a[], int left, int right, int x)
{
	int mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == x)
		{
			return mid;
		}
		else if(a[mid] > x)
		{
			right = mid - 1;
		}
		else if(a[mid] < x)
		{
			left = mid + 1;
		}
	}
	return -1;
}
int main(int argc, char *argv[]) {
	for(int i = 0; i < 105; i++)
	{
		arr[i] = rand() % 40;
	}
	sort(arr, arr + 105);
	
	for(int i = 0; i < 105; i++)
	{
		cout << i << " " << arr[i] << endl;
	}
	printf("输入要查找的数字的区间：");
	int num;
	scanf("%d", &num);
	int L = lowerBound(arr, 0, 104, num);
	int R = upperBound(arr, 0, 104, num);
	printf("区间：[%d,%d)", L, R);
	return 0;
}
