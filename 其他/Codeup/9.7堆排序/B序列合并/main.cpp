#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int N, length;
int a[maxn], b[maxn], heap[1000005];
void downAdjust(int low, int high)
{
	int father = low, lchild = low * 2, rchild = low * 2 + 1;
	while(lchild <= high)
	{
		if(rchild <= high && heap[rchild] > heap[lchild])
		{
			lchild = rchild;
		}
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
void upAdjust(int low, int high)
{
	int child = high, father = child / 2;
	while(father >= low)
	{
		if(heap[child] > heap[father])
		{
			swap(heap[child], heap[father]);
			child = father;
			father = child / 2;
		}
		else 
			break;
	}
}
void deleteTop()
{
	heap[1] = heap[length--];
	downAdjust(1, length);
}
void insert(int x)
{
	heap[++length] = x;
	upAdjust(1, length);
}
void heapSort()
{
	for(int i = length; i > 1; i--)
	{
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
	}
}
int main(int argc, char *argv[]) {
	while(~scanf("%d", &N))
	{
		for(int i = 1; i <= N; ++i)
		{
			scanf("%d", &a[i]);
		}
		for(int i = 1; i <= N; ++i)
		{
			scanf("%d", &b[i]);
		}
		for(int j = 1; j <= N; ++j)
		{
			int num = a[1] + b[j];
			insert(num);
		}
		
		for(int i = 2; i <= N; ++i)
		{
			for(int j = 1; j <= N; ++j)
			{
				int num = a[i] + b[j];
				if(num < heap[1])
				{
					deleteTop();
					insert(num);
				}
				else
				{
					break;
				}
			}
		}
		heapSort();
		for(int i = 1; i <= N; ++i)
		{
			printf("%d", heap[i]);
			if(i < N)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
