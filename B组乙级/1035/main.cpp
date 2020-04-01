#include <bits/stdc++.h>
using namespace std;
int N;
int origin[105], mergearr[105], num[105], temparr[105];
bool isInsert = false, isMerge = false;
bool judge(int arr[])
{
	for(int i = 0; i < N; ++i)
	{
		if(arr[i] != num[i])
		{
			return false;
		}
	}
	return true;
}
void insertSort()
{
	for(int i = 1; i <= N; ++i)
	{
		if(i != 1 && judge(origin) == true)//说明是插排 
		{
			isInsert = true;
		}
		int temp = origin[i];
		int j = i - 1;
		while(temp < origin[j] && j >= 0)
		{
			origin[j + 1] = origin[j];
			j--;
		}
		origin[j + 1] = temp;
		if(isInsert == true)
		{
			printf("Insertion Sort\n");
			for(int k = 0; k < N; ++k)
			{
				printf("%d", origin[k]);
				if(k < N - 1)
					printf(" ");
			}
			return;
		}	
	}
}
void merge(int a[], int l1, int r1, int l2, int r2)
{
	int i = l1, j = l2;
	int index = 0;
	while(i <= r1 && j <= r2)
	{
		if(a[i] <= a[j])
		{
			temparr[index++] = a[i++];
		}
		else
		{
			temparr[index++] = a[j++];
		}
	}
	while(i <= r1)
		temparr[index++] = a[i++];
	while(j <= r2)
		temparr[index++] = a[j++];
	
	for(i = 0; i < index; ++i)
	{
		a[l1 + i] = temparr[i];
	}	
	
	/*if(judge(temparr) == true)
	{
		isMerge = true;
	}
	if(isMerge == true)
	{
		for(int i = 0; i < index; ++i)
		{
			printf("%d", temparr[i]);
			if(i < index - 1)
				printf(" ");
		}
		return;
	}*/
}
void mergeSort(int a[], int left, int right)//无法查看每一趟的结果 
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, mid + 1, right);
		printf("Merge Sort\n");
		for(int i = 1; i <= N; ++i)
		{
			printf("%d", a[i]);
			if(i < N)
				printf(" ");
		}
		printf("\n");
		/*if(judge(a) == true)
		{
			isMerge = true;
		}
		else if(isMerge == true)
		{
			printf("Merge Sort\n");
			for(int i = 1; i <= N; ++i)
			{
				printf("%d", a[i]);
				if(i < N)
					printf(" ");
			}
			printf("\n");
			return;
		}*/	
	}
}
void mergeByStep()
{
	for(int step = 2; step / 2 <= N; step *= 2)
	{
		if(step != 2 && judge(mergearr) == true)
		{
			isMerge = true;
		}
		for(int i = 0; i < N; i += step)
		{
			sort(mergearr + i, mergearr + min(i + step, N));
		}
		if(isMerge == true)
		{
			printf("Merge Sort\n");
			for(int i = 0; i < N; ++i)
			{
				printf("%d", mergearr[i]);
				if(i < N - 1)
					printf(" ");
			}
			printf("\n");
			return;
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &origin[i]);
		mergearr[i] = origin[i];
	}
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);
	}
	insertSort();
	if(isInsert == false)//为归并排序 
	{
		//mergeSort(mergearr, 1, N);
		mergeByStep();
	}
	
	return 0;
}
