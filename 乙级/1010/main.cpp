#include <bits/stdc++.h>
using namespace std;
int num[100005];
int ex[100005];
int main(int argc, char *argv[]) {
	int index = 0;
	int a, b;
	bool flag = false;//����Ƿ��г����� 
	while(scanf("%d %d", &a, &b) != EOF)
	{
		index++;
		num[index] = a * b;//�󵼺��ϵ�� 
		if(b != 0)
		{
			ex[index] = b - 1;//�󵼺�ָ��-1 
		}
		else
		{
			ex[index] = 0;//�������ָ������ 
			flag = true;
			break;
		}
	}
	if(flag)//�޸��±꣬��������������󵼺��0 
	{
		index--;
	}
	if(index)
	{
		for(int i = 1; i <= index; i++)//���뵽indexΪֹ���������������
		{
			printf("%d %d", num[i], ex[i]);
			if(i < index)
			{
				printf(" ");
			}
		}
	}
	else//�󵼺�index == 0���޷����������д��� 
	{
		printf("0 0");
	}
	return 0;
}
