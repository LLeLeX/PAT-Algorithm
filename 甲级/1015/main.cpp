#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int N, D;
bool isPrime[maxn] = {true};
void findPrime()
{
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < maxn; ++i)
	{
		if(isPrime[i])
		{
			for(int j = i + i; j < maxn; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}
int num[50], pos = 0;//�洢����ת����ÿһλ��pos���±� 
int getNum(int n, int r)//ʮ����ת��ΪN���� 
{
	while(n)
	{
		int ret = n % r;
		num[pos++] = ret;//���� 
		n = n / r;
	}
}
int main(int argc, char *argv[]) {
	memset(isPrime, true, sizeof(isPrime));
	findPrime();
	while(1)
	{
		scanf("%d", &N);
		if(N < 0)
			break;
		scanf("%d", &D);
		memset(num, 0, sizeof(num));//��ʼ�� 
		pos = 0;
		if(isPrime[N] == false)
			printf("No\n");
		else
		{
			getNum(N, D);//ʮ����Nת��ΪD����
			//��ʱnum����������D������
			//�������num���ǵ����N��D�����£�
			//reverse�洢��ת���ʮ��������product��ǰ���ƴη� 
			int reverse = 0, product = 1;
			for(int i = pos - 1; i >= 0; --i)
			{
				reverse += num[i] * product;
				product *= D;
			} 
			if(isPrime[reverse] == false)
				printf("No\n");
			else
				printf("Yes\n"); 
		}
	}
	return 0;
}
