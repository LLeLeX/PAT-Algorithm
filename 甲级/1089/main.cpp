#include <bits/stdc++.h>
using namespace std;
int n;
int origi[105];
int origi2[105];
int first[105];
bool sortFlag = false;//false：归并，true：插入 
bool judge(int a[], int b[])
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
void display(int a[])
{
	for(int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if(i < n - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}
void insertSort(int a[])
{ 
	int tempn = n; 
	for(int i = 1; i < tempn; i++)
	{
		int temp = a[i], j = i;
		while(j > 0 && temp < a[j - 1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
		if(judge(a, first))//数组一致
		{
			tempn = i + 2;
			sortFlag = true;
		}
		else
		{
			continue;
		}
	}
}
void mergeSort(int a[])
{
	int tempn = n;
	for(int step = 2; step / 2 <= tempn; step *= 2)
	{
		for(int i = 0; i < n; i += step)
		{
			sort(a + i, a + min(i + step, n));
		}
		if(judge(a, first))
		{
			tempn = step;
		}
		else
		{
			continue;
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &origi[i]);
		origi2[i] = origi[i];
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &first[i]);
	}
	insertSort(origi);
	if(sortFlag)
	{
		printf("Insertion Sort\n");
		display(origi);
	}
	else
	{
		printf("Merge Sort\n");
		mergeSort(origi2);
		display(origi2);
	}
	return 0;
}
