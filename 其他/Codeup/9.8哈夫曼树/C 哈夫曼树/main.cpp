#include <bits/stdc++.h>
using namespace std;
int n;
int heap[1005];
//建立小顶堆 
void downAdjust(int low, int high)
{
	int father = low, lchild = 2 * father, rchild = 2 * father + 1;
	while(lchild <= high)
	{
		if(rchild <= high && heap[rchild] < heap[lchild])
		{
			lchild = rchild;
		}
		if(heap[lchild] < heap[father])
		{
			swap(heap[lchild], heap[father]);
			father = lchild;
			lchild = father * 2;
			rchild = lchild + 1;
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
		if(heap[child] < heap[father])
		{
			swap(heap[child], heap[father]);
			child = father;
			father = child / 2;
		}
		else
			break;
	}
}
void insert(int x)
{
	heap[++n] = x;
	upAdjust(1, n);
}
void deleteTop()
{
	heap[1] = heap[n--];
	downAdjust(1, n);
}
int main(int argc, char *argv[]) {
	while(~scanf("%d", &n))
	{
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &heap[i]);
		}
		//建立小顶堆 
		for(int i = n / 2; i >= 1; i--)
		{
			downAdjust(i, n);
		}
		int ans = 0;
		while(n > 1)
		{
			int temp = 0;
			temp += heap[1];
			deleteTop();
			temp += heap[1];
			deleteTop();
			ans += temp;
			insert(temp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
