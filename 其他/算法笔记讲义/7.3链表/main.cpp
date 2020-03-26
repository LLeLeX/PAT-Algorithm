#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
}*head;
//创建链表
node* create(int arr[], int len)
{
	node *pre, *p;
	head = new node;//创建头结点 
	head->next = NULL;
	pre = head;
	for(int i = 0; i < len; i++)
	{
		p = new node;//新建节点 
		p->data = arr[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
} 
//对链表L的pos位置插入x 
void insert(node *L, int pos, int x)
{
	L = L->next;//从第一个节点开始 
	for(int i = 0; i < pos - 1; i++)
	{
		L = L->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = L->next;
	L->next = temp;
}
//删除链表L中值为x的所有节点
void deleteNode(node *L, int x)
{
	node *p, *pre;
	pre = L;
	p = L->next;//从第一个节点开始 	
	while(p != NULL)
	{
		if(p->data == x)
		{
			pre->next = p->next;
			delete(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
} 
void display(node *L)
{
	L = L->next;//从第一个节点开始 
	while(L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
int main(int argc, char** argv) {
	//创建链表
	int nums[5] = {5, 8, 3, 9, 7};
	node *L = create(nums, 5);
	display(L);
	//插入新节点
	insert(L, 4, 8);
	display(L);
	//删除节点
	deleteNode(L, 8);
	display(L); 
	delete(L);
	return 0;
}
