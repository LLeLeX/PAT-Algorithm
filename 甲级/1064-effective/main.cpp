#include <bits/stdc++.h>
using namespace std;
int N, num[1005], cbt[1005], pos;
void inOrder(int root)
{
	if(root > N)//�жϽڵ�Ϊ��
		return;
	inOrder(root * 2);
	cbt[root] = num[pos++];
	inOrder(root * 2 + 1); 
} 
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &num[i]);
	sort(num, num + N);
	inOrder(1);
	for(int i = 1; i <= N; ++i)
	{
		printf("%d", cbt[i]);//������ǲ���
		if(i < N)
			printf(" "); 
	}
	return 0;
}
