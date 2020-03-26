#include <bits/stdc++.h>
using namespace std;
int n, length;
int w[105];
struct Node{
	int weight;
	int parent, lchild, rchild;
	Node(){}
	Node(int w, int p, int l, int r)
	{
		weight = w;
		parent = p;
		lchild = l;
		rchild = r;
	}
}nodes[100005];//要寻找根节点 
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
			int w;
			scanf("%d", &w);
			nodes[i] = Node(w, -1, -1, -1);
		}
		length = n;//树的节点数，n个叶子节点 
		//建立小顶堆 
		for(int i = n / 2; i >= 1; i--)
			downAdjust(i, n);
		while(n > 1)
		{
			int x = heap[1];//子节点x 
			deleteTop();
			int y = heap[2];//子节点y
			int temp = x + y; //父节点权值 
			deleteTop();
			nodes[++length] = Node(temp, -1, )
			insert(temp);
		}
	}
	return 0;
}
