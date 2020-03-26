#include <bits/stdc++.h>
using namespace std;
int arr[20];
void getRandom()
{
	srand((unsigned)time(NULL));
	for(int i = 0; i < 15; i++)
	{
		arr[i] = rand() % 101;
	}
}
void display()
{
	for(int i = 0; i < 15; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int randPartition(int a[], int left, int right)
{
	int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);//生成left到right中的随机数P 
	swap(a[p], a[left]);
	int temp = a[left];
	while(left < right)//left与right相遇时会跳出循环 
	{
		while(left < right && a[right] > temp)//满足大数在右侧，则继续移动指针 
		{
			right--;
		}
		a[left] = a[right];//不满足时交换 
		while(left < right && a[left] <= temp)//满足小数在左侧，则继续移动指针 
		{
			left++; 
		}
		a[right] = a[left];//不满足时交换
	}
	a[left] = temp;//left与right相遇的地方 
	return left; 
}
void quickSort(int a[], int left, int right)
{
	if(left < right)
	{
		int pos = randPartition(arr, left, right);
		quickSort(arr, left, pos - 1);
		quickSort(arr, pos + 1, right);
	}
}
int main(int argc, char *argv[]) {
	getRandom();
	cout << "原序列：" << endl;
	display();
	cout << "快速排序：" << endl;
	quickSort(arr, 0, 14);
	display();
	return 0;
}
