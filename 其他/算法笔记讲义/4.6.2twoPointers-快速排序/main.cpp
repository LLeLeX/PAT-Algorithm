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
	int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);//����left��right�е������P 
	swap(a[p], a[left]);
	int temp = a[left];
	while(left < right)//left��right����ʱ������ѭ�� 
	{
		while(left < right && a[right] > temp)//����������Ҳ࣬������ƶ�ָ�� 
		{
			right--;
		}
		a[left] = a[right];//������ʱ���� 
		while(left < right && a[left] <= temp)//����С������࣬������ƶ�ָ�� 
		{
			left++; 
		}
		a[right] = a[left];//������ʱ����
	}
	a[left] = temp;//left��right�����ĵط� 
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
	cout << "ԭ���У�" << endl;
	display();
	cout << "��������" << endl;
	quickSort(arr, 0, 14);
	display();
	return 0;
}
