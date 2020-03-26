#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int cnt, dir[4] = {-3, 3, 1, -1};//��1ά�ַ����е��ƶ����൱��3*3��������������ƶ� 
int factorial[15] {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};//0-10�׳� 
int garray[10];
void arraycpy(int a[], int b[])//������a��ֵ������b 
{
	for(int i = 0; i < 9; i++)
	{
		b[i] = a[i];
	}
}
struct Node{
	int array[10];
	int status;//�洢��ǰ����״̬��Ӧ�Ŀ���չ�� 
	int step;//���� 
	int pos0; //���0��λ�����滻find() 
	Node(){}
	Node(int arr[], int ss, int s, int p){
		status = ss;
		step = s;
		pos0 = p;
		arraycpy(arr, array);
	}
}originNode, resultNode;
int cantor(int a[])//����չ�� 
{
	int ans = 0, sum = 0;
	for(int i = 0; i < 8; ++i)
	{
		for(int j = i + 1; j <= 8; ++j)
		{
			if(a[j] < a[i])
			{
				sum++;
			}
		}
		ans += sum * factorial[8 - i];
		sum = 0;
	}
	return ans + 1;
} 
int arrswap(int a[], int x, int y)//0���������ֽ���λ�� 
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
	return cantor(a);
}
int main(int argc, char *argv[]) {
	while(1)
	{
		DWORD startTime, endTime;
		
		
		queue<Node> q;
		map<int, bool> inq;//״̬��bool��ӳ�䣬��ʾ�Ƿ���� 
		int origin[10], result[10];//��ʼ״̬�ͽ��״̬ 
		int cnt = 0, pos0; 
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				scanf("%d", &origin[cnt++]);//��ʼ״̬ѹ�� 
				if(origin[cnt - 1] == 0)
					pos0 = 3 * i + j;
			}
		}
		originNode = Node(origin, cantor(origin), 1, pos0);
		cnt = 0;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				scanf("%d", &result[cnt++]);//���״̬ѹ�� 
				if(result[cnt - 1] == 0)
					pos0 = 3 * i + j;
			}
		}
		resultNode = Node(result, cantor(result), 1, pos0);
		//bfs
		startTime = GetTickCount();
		q.push(originNode);
		inq[originNode.status] = true;
		while(!q.empty())
		{
			Node top = q.front();
			q.pop();
			if(top.status == resultNode.status)//����״̬һ��
			{
				printf("%d\n", top.step); 
				break;
			}			
			int index0 = top.pos0;
			for(int i = 0; i < 4; i++)
			{
				int tindex = index0 + dir[i];//���������ƶ�"0"����±�
				if(tindex < 0 || tindex >= 9)//�ж��Ƿ�Ϸ� 
					continue; 
				arraycpy(top.array, garray);
				int tstatus = arrswap(garray, index0, tindex);//��������Ŀ���չ�� 
				if(!inq[tstatus])//��δ���
				{
					Node temp = Node(garray, tstatus, top.step + 1, tindex);
					inq[tstatus] = true;
					q.push(temp);//�ýڵ���� 
				} 	
			} 
		}
		endTime = GetTickCount();
		//printf("%dms\n", endTime - startTime);
		cout << endTime - startTime << "ms" << endl;
	}
	return 0;
}
