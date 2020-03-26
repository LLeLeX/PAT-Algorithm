#include <bits/stdc++.h>
using namespace std;
int n = 10;//堆中元素个数 
int heap[20] = {0, 85, 55, 82, 57, 68, 92, 99, 98, 66, 56};//第一个元素在1号位 
void downAdjust(int low, int high)//向下调整 
{
	int father = low, lchild = father * 2, rchild = father * 2 + 1;//从1号位，树的根节点遍历 
	while(lchild <= high)//叶子节点跳出循环，判断当前节点是否为叶子节点 
	{
		if(rchild <= high && heap[rchild] > heap[lchild])//右孩子有效且值大于左孩子 
		{
			lchild = rchild;//比较两个子节点，较大者存在lchild中 
		}
		if(heap[lchild] > heap[father])//当子节点值大于父节点时 
		{
			swap(heap[lchild], heap[father]);
			father = lchild;
			lchild = father * 2;
			rchild = father * 2 + 1; 
		}
		else//当前已经是最大值了，跳出循环 
			break;
	}
}
void upAdjust(int low, int high)//向上调整 
{
	int child = high, father = child / 2;//此处不再区分左右子节点，因为父节点是唯一的 
	while(father >= low)//父亲节点在数据范围内 
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
	heap[1] = heap[n--];
	downAdjust(1, n);
}
void insert(int x)
{
	heap[++n] = x;
	upAdjust(1, n);
}
void heapSort()
{
	for(int i = n; i >= 1; i--)
	{
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
	}
}
void display()
{
	for(int i = 1; i <= n; ++i)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
}
int main(int argc, char *argv[]) {
	for(int i = n / 2; i >= 1; i--)//建堆 
	{
		downAdjust(i , n);
	}
	display();
	//deleteTop();
	//insert(100);
	heapSort();
	display();
	return 0;
}
