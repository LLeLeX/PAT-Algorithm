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
	nodes[aa].id = cnt;//记录有效节点的总数 
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
	
	//关于翻转 
	int cntGroup;
	bool flag = false;//标记不能整除	
	if(cnt % K == 0)
	{//刚好整除时 
		flag = true;
		cntGroup = cnt / K;//带上最后一组的组数 
	}
	else
	{//不能整除时 
		flag = false;
		cntGroup = cnt / K + 1;
	} 
	for(int i = 0; i < cntGroup; i++)//组数 
	{
		if(i < cntGroup - 2)//不是倒数第二组 
		{
			for(int j = K * (i + 1) - 1; j >= K * i; j--)//组内翻转，从后往前输出 
			{
				if(j > K * i)//不是最后一个 
				{
					printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j - 1].addr);
				}
				else//是最后一个 
				{
					printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[K * ( i + 2) - 1].addr);
				} 
			}
		}
		else if(i == cntGroup - 2)//是倒数第二组 
		{
			for(int j = K * (i + 1) - 1; j >= K * i; j--)//组内翻转，从后往前输出 
			{
				if(j > K * i)//不是最后一个 
				{
					printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j - 1].addr);
				}
				else//是倒数第二组的最后一个 
				{
					if(flag)//true,整除，最后一组正常翻转 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[K * ( i + 2) - 1].addr);
					}
					else//flase,不能整除,最后一组不做翻转 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[K * (i + 1)].addr);
					}
				} 
			}
		}
		else//最后一组 
		{
			if(flag)//true,整除，最后一组正常翻转 
			{
				for(int j = K * (i + 1) - 1; j >= K * i; j--)//组内翻转，从后往前输出 
				{
					if(j > K * i)//不是最后一个 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j - 1].addr);
					}
					else//是最后一个 
					{
						printf("%05d %d -1\n", nodes[j].addr, nodes[j].data);
					} 
				}	
			}
			else//flase,不能整除,最后一组不做翻转 
			{
				for(int j = K * i; j < cnt; j++)
				{
					if(j < cnt - 1)//不是最后一个 
					{
						printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j].next);
					}
					else//是最后一个 
					{
						printf("%05d %d -1\n", nodes[j].addr, nodes[j].data);
					} 
				}
			}
		}
	}
	return 0;
}
