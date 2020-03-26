#include <bits/stdc++.h>
using namespace std;
int arr[20], temp[20];
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
void merge(int a[], int L1, int R1, int L2, int R2)
{
	int i = L1, j = L2;
	int index = 0;
	while(i <= R1 && j <= R2)
	{
		if(a[i] < a[j])
		{
			temp[index++] = a[i++];
		}
		else
		{
			temp[index++] = a[j++];
		}
	}
	while(i <= R1)
	{
		temp[index++] = a[i++];
	}
	while(j <= R2)
	{
		temp[index++] = a[j++];
	}
	for(int i = 0; i < index; i++)
	{
		arr[L1 + i] = temp[i];//****
	}
}
void mergeSort(int a[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, mid + 1, right);
	}
}
int main(int argc, char *argv[]) {
	getRandom();
	cout << "Ô­ÐòÁÐ£º" << endl;
	display();
	mergeSort(arr, 0, 14);
	cout << "¹é²¢ÅÅÐò£º" << endl;
	//display();
	for(int i = 0; i < 15; i++)
	{
		cout << temp[i] << " ";
	}
	return 0;
}
