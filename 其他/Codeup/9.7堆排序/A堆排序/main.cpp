#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int heap[maxn];
void downAdjust(int low, int high)
{
	int father = low, lchild = father * 2, rchild = father * 2 + 1;
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
void heapSort()
{
	for(int i = n; i > 1; i--)
	{
		swap(heap[i], heap[1]);
		downAdjust(1, i - 1);
	}
}
int main(int argc, char *argv[]) {
	while(~scanf("%d", &n))
	{
		for(int i = 1; i <= n; ++i)
			scanf("%d", &heap[i]);
		for(int i = n / 2; i >= 1; i--)
			downAdjust(i, n);
		heapSort();
		for(int i = 1; i <= n; i++)
		{
			printf("%d", heap[i]);
			if(i < n)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
