#include <bits/stdc++.h>
using namespace std;
int N, ans, cnt;
int pos[100005];
bool cmp(int a, int b)
{
	return a < b;
}
void swaparr(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	cnt = N - 1;//��¼0���ⲻ�ڱ�λ�ĸ�����������δ�����ڶԵ�λ�� 
	for(int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		//�磺3������ֳ�����0��λ�� 
		pos[num] = i;//��ŵ�ǰ���ֳ����ڼ���λ�ϣ���������±�
		if(num == i && num != 0)//���Ե����ֳ����ڶԵ�λ�ã���3��3��λ��ʱ 
		{
			cnt--; 
		} 
	}
	int index = 1;
	while(cnt > 0)
	{
		if(pos[0] == 0)//���0��0��λ�� 
		{
			while(index < N)
			{
				if(pos[index] != index)
				{
					swaparr(pos[0], pos[index]);
					ans++;
					//cnt--;//�˴�ֻ���ҵ���һ�����ڱ�λ�ϵ������н����������ܱ�֤һ���ỻ�ص���ȷλ�� 
					break;
				}
				index++;
			}	
		}
		while(pos[0] != 0)
		{
			swaparr(pos[0], pos[pos[0]]);
			ans++;
			cnt--;
		}
	}
	printf("%d", ans);
	return 0;
}
