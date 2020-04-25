#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int M, N;
int in[maxn], pre[maxn];
unordered_map<int, int> inpos;//���������ݵ�λ�� 
int main(int argc, char *argv[]) {
	scanf("%d%d", &M, &N);
	for(int i = 1; i <= N; ++i)//�±��1��ʼ 
	{
		scanf("%d", &in[i]);
		inpos[in[i]] = i; 
	}
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &pre[i]);
	}
	while(M--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		int inu = inpos[u], inv = inpos[v];
		if(inu == 0 && inv != 0)//����0˵�������ݲ������� 
			printf("ERROR: %d is not found.\n", u);
		else if(inu != 0 && inv == 0)
			printf("ERROR: %d is not found.\n", v);
		else if(inu == 0 && inv == 0)
			printf("ERROR: %d and %d are not found.\n", u, v);
		else
		{
			for(int i = 1; i <= N; ++i)//������������ 
			{
				int now = pre[i];//��ǰ�ڵ����ֵ 
				int innow = inpos[now];//��ǰ�ڵ��������е��±� 
				if((innow > inu && innow < inv) || (innow > inv && innow < inu))//�±���u��v֮�� 
				{
					printf("LCA of %d and %d is %d.\n", u, v, now);
					break;
				}
				else if(innow == inu)//��u��ȼ��ɣ�û��innow != inv������ 
				{
					printf("%d is an ancestor of %d.\n", u, v);
					break;
				}
				else if(innow == inv)
				{
					printf("%d is an ancestor of %d.\n", v, u);
					break;
				}
				else
					continue;
			}
		}
	}
	return 0;
}
