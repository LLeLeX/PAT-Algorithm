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
	cnt = N - 1;//记录0以外不在本位的个数，即数字未出现在对的位置 
	for(int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		//如：3这个数字出现在0号位上 
		pos[num] = i;//存放当前数字出现在几号位上，即数组的下标
		if(num == i && num != 0)//当对的数字出现在对的位置，如3在3号位上时 
		{
			cnt--; 
		} 
	}
	int index = 1;
	while(cnt > 0)
	{
		if(pos[0] == 0)//如果0在0号位上 
		{
			while(index < N)
			{
				if(pos[index] != index)
				{
					swaparr(pos[0], pos[index]);
					ans++;
					//cnt--;//此处只是找到任一个不在本位上的数进行交换，并不能保证一定会换回到正确位置 
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
