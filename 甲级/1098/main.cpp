#include <bits/stdc++.h>
using namespace std;
int N;
int origin[105], current[105], heap[105];
bool flag;//false:堆排序，true：插排 
bool check(int a[], int b[])
{
	for(int i = 1; i <= N; ++i)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;//序列相吻合 
}
void insertSort()
{
	for(int i = 2; i <= N; ++i)
	{
		int temp = origin[i];//当前插入元素 
		int j = i;
		while(j > 1 && temp < origin[j - 1])
		{
			origin[j] = origin[j - 1];
			j--;
		}
		origin[j] = temp;
		if(flag)
			break;
		if(check(origin, current))
		{
			flag = true;
		}
	}
}
void downAdjust(int low, int high)
{
	int father = low, lchild = father * 2, rchild = father * 2 + 1;
	while(lchild <= high)
	{
		//大顶堆 
		if(rchild <= high && heap[rchild] > heap[lchild])
			lchild = rchild;
		if(heap[lchild] > heap[father])
		{
			swap(heap[lchild], heap[father]);
			father = lchild;
			lchild = father * 2;
			rchild = father * 2 + 1;
		}
		else
			break;
	}
}
void heapSort()
{
	bool isCur = false;
	for(int i = N; i > 1; i--)
	{
		if(isCur)
			break;
		if(check(heap, current))
			isCur = true;
		swap(heap[i], heap[1]);
		downAdjust(1, i - 1);
	} 
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &origin[i]);
		heap[i] = origin[i];
	}
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &current[i]);
	}
	insertSort();
	if(flag)
	{
		printf("Insertion Sort\n");
		for(int i = 1; i <= N; ++i)
		{
			printf("%d", origin[i]);
			if(i < N)
				printf(" ");
		}
	}
	else
	{
		printf("Heap Sort\n");
		for(int i = N / 2; i >= 1; i--)//建堆 
		{
			downAdjust(i, N);
		}
		heapSort();
		for(int i = 1; i <= N; ++i)
		{
			printf("%d", heap[i]);
			if(i < N)
				printf(" ");
		}
	}
	return 0;
}
