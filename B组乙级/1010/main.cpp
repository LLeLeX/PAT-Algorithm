#include <bits/stdc++.h>
using namespace std;
int num[100005];
int ex[100005];
int main(int argc, char *argv[]) {
	int index = 0;
	int a, b;
	bool flag = false;//标记是否有常数项 
	while(scanf("%d %d", &a, &b) != EOF)
	{
		index++;
		num[index] = a * b;//求导后的系数 
		if(b != 0)
		{
			ex[index] = b - 1;//求导后指数-1 
		}
		else
		{
			ex[index] = 0;//常数项不做指数处理 
			flag = true;
			break;
		}
	}
	if(flag)//修改下标，不予输出常数项求导后的0 
	{
		index--;
	}
	if(index)
	{
		for(int i = 1; i <= index; i++)//输入到index为止，不再输出常数项
		{
			printf("%d %d", num[i], ex[i]);
			if(i < index)
			{
				printf(" ");
			}
		}
	}
	else//求导后index == 0，无非零项做特判处理 
	{
		printf("0 0");
	}
	return 0;
}
