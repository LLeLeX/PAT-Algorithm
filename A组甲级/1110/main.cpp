//��ȫ���������ж������ǣ���������ö�������1������ǰ�ڵ������Ϊ�գ��Һ��Ӳ�Ϊ�գ������ȫ��������
//2��������ĳ���ڵ�û���Һ�������б�ǣ�����֮����ӵĽڵ��������Ҷ�ӽڵ���ô�Ͳ�����ȫ��������
#include <bits/stdc++.h>
using namespace std;
int hashtable[25];//Ѱ�Ҹ��ڵ� 
bool inq[25];
int N, root;
struct Node{
	int data;
	int left, right;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		left = l;
		right = r;
	}
}nodes[105];
int bfs(int cnt)
{
	bool isleaf = false;
	queue<Node> q;
	q.push(nodes[root]);
	inq[root] = true;
	while(!q.empty())
	{
		Node now = q.front();
		q.pop();
		cnt++;//����ʱ���ż��������������ʱ���� 
		//�ж� 
		if(isleaf == true)
		{
			if(now.left != -1 || now.right != -1)
				return -1;
		}
		if(now.left == -1 && now.right != -1)//����Ϊ�գ��Һ��Ӳ��� 
			return -1;
			
		//if(now.left == -1 && now.right == -1)���������������� 
		if(now.right == -1)//���Ӳ��գ��Һ��ӿ� 
		{
			isleaf = true;//������ӵľ�ΪҶ�ӽڵ� 
		}
		if(cnt == N)
			return now.data;
		//���
		if(now.left != -1)
		{
			q.push(nodes[now.left]);
			inq[now.left] = true;
		}
		if(now.right != -1)
		{
			q.push(nodes[now.right]);
			inq[now.right] = true;
		}
		/*if(q.empty())//��cnt == N������Ϊ�ж���������ѡһ 
			return now.data;*/
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	//getchar();
	for(int i = 0; i < N; ++i)
	{
		char l[3], r[3];//ע�����ݷ�Χ��0~20����˲����õ����ַ����գ������޷�����12,13����λ������ 
		int ll, rr;
		//getchar();
		scanf("%s %s", l, r);
		if(l[0] == '-')
			ll = -1;
		else
			sscanf(l, "%d", &ll);
		if(r[0] == '-')
			rr = -1;
		else
			sscanf(r, "%d", &rr);
		nodes[i] = Node(i, ll, rr);
		hashtable[ll] = hashtable[rr] = 1;
	}
	for(int i = 0; i < N; ++i)
	{
		if(hashtable[i] == 0)
		{
			root = i;
			break;
		}
	}
	int flag = bfs(0);
	if(flag == -1)//������ȫ������ 
	{
		printf("NO %d", root);
	}
	else
	{
		printf("YES %d", flag);
	}
	return 0;
}
