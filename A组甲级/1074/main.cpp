#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int start, num, K, cnt = 1;
struct Node{
	int id = maxn;
	int addr;
	int data;
	int next;
	Node(){}
	Node(int aa, int dd, int nn){
		data = dd;
		addr = aa;
		next = nn;
	} 
}nodes[maxn];

void setID(){
	int aa = start;
	while(nodes[aa].next != -1)
	{
		nodes[aa].id = cnt++;
		aa = nodes[aa].next;
	}
	nodes[aa].id = cnt;//��¼��Ч�ڵ������ 
}

bool cmp(Node n1, Node n2){
	return n1.id < n2.id;
}
int main(int argc, char** argv) {
	scanf("%d%d%d", &start, &num, &K);
	for(int i = 0; i < num; i++)
	{
		int aa, dd, nn;
		scanf("%d%d%d", &aa, &dd, &nn);
		nodes[aa] = Node(aa, dd, nn); 
	}
	setID();
	sort(nodes, nodes + maxn, cmp);
	
	//���ڷ�ת 
	int cntGroup;
	bool flag = false;//��ǲ�������	
	if(cnt % K == 0)
	{//�պ�����ʱ 
		flag = true;
		cntGroup = cnt / K;//�������һ������� 
	}
	else
	{//��������ʱ 
		flag = false;
		cntGroup = cnt / K + 1;
	} 
	for(int i = 0; i < cntGroup; i++)//���� 
	{
		if(i < cntGroup - 2)//���ǵ����ڶ��� 
		{
			for(int j = K * (i + 1) - 1; j >= K * i; j--)//���ڷ�ת���Ӻ���ǰ��� 
			{
				if(j > K * i)//�������һ�� 
				{
					printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j - 1].addr);
				}
				else//�����һ�� 
				{
					printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[K * ( i + 2) - 1].addr);
				} 
			}
		}
		else if(i == cntGroup - 2)//�ǵ����ڶ��� 
		{
			for(int j = K * (i + 1) - 1; j >= K * i; j--)//���ڷ�ת���Ӻ���ǰ��� 
			{
				if(j > K * i)//�������һ�� 
				{
					printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j - 1].addr);
				}
				else//�ǵ����ڶ�������һ�� 
				{
					if(flag)//true,���������һ��������ת 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[K * ( i + 2) - 1].addr);
					}
					else//flase,��������,���һ�鲻����ת 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[K * (i + 1)].addr);
					}
				} 
			}
		}
		else//���һ�� 
		{
			if(flag)//true,���������һ��������ת 
			{
				for(int j = K * (i + 1) - 1; j >= K * i; j--)//���ڷ�ת���Ӻ���ǰ��� 
				{
					if(j > K * i)//�������һ�� 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j - 1].addr);
					}
					else//�����һ�� 
					{
						printf("%05d %d -1\n", nodes[j].addr, nodes[j].data);
					} 
				}	
			}
			else//flase,��������,���һ�鲻����ת 
			{
				for(int j = K * i; j < cnt; j++)
				{
					if(j < cnt - 1)//�������һ�� 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j].next);
					}
					else//�����һ�� 
					{
						printf("%05d %d -1\n", nodes[j].addr, nodes[j].data);
					} 
				}
			}
		}
	}
	return 0;
}
