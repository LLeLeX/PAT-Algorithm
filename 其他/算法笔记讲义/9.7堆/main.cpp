#include <bits/stdc++.h>
using namespace std;
int n = 10;//����Ԫ�ظ��� 
int heap[20] = {0, 85, 55, 82, 57, 68, 92, 99, 98, 66, 56};//��һ��Ԫ����1��λ 
void downAdjust(int low, int high)//���µ��� 
{
	int father = low, lchild = father * 2, rchild = father * 2 + 1;//��1��λ�����ĸ��ڵ���� 
	while(lchild <= high)//Ҷ�ӽڵ�����ѭ�����жϵ�ǰ�ڵ��Ƿ�ΪҶ�ӽڵ� 
	{
		if(rchild <= high && heap[rchild] > heap[lchild])//�Һ�����Ч��ֵ�������� 
		{
			lchild = rchild;//�Ƚ������ӽڵ㣬�ϴ��ߴ���lchild�� 
		}
		if(heap[lchild] > heap[father])//���ӽڵ�ֵ���ڸ��ڵ�ʱ 
		{
			swap(heap[lchild], heap[father]);
			father = lchild;
			lchild = father * 2;
			rchild = father * 2 + 1; 
		}
		else//��ǰ�Ѿ������ֵ�ˣ�����ѭ�� 
			break;
	}
}
void upAdjust(int low, int high)//���ϵ��� 
{
	int child = high, father = child / 2;//�˴��������������ӽڵ㣬��Ϊ���ڵ���Ψһ�� 
	while(father >= low)//���׽ڵ������ݷ�Χ�� 
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
	for(int i = n / 2; i >= 1; i--)//���� 
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
