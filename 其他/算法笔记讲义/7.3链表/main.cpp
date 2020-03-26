#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
}*head;
//��������
node* create(int arr[], int len)
{
	node *pre, *p;
	head = new node;//����ͷ��� 
	head->next = NULL;
	pre = head;
	for(int i = 0; i < len; i++)
	{
		p = new node;//�½��ڵ� 
		p->data = arr[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
} 
//������L��posλ�ò���x 
void insert(node *L, int pos, int x)
{
	L = L->next;//�ӵ�һ���ڵ㿪ʼ 
	for(int i = 0; i < pos - 1; i++)
	{
		L = L->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = L->next;
	L->next = temp;
}
//ɾ������L��ֵΪx�����нڵ�
void deleteNode(node *L, int x)
{
	node *p, *pre;
	pre = L;
	p = L->next;//�ӵ�һ���ڵ㿪ʼ 	
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
	L = L->next;//�ӵ�һ���ڵ㿪ʼ 
	while(L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
int main(int argc, char** argv) {
	//��������
	int nums[5] = {5, 8, 3, 9, 7};
	node *L = create(nums, 5);
	display(L);
	//�����½ڵ�
	insert(L, 4, 8);
	display(L);
	//ɾ���ڵ�
	deleteNode(L, 8);
	display(L); 
	delete(L);
	return 0;
}
