#include <bits/stdc++.h>
using namespace std;
int countNum[15];
int cnt;
int ans[100];
int main(int argc, char *argv[]) {
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &countNum[i]);
		cnt += countNum[i]; 
	}
	int index = 0;
	//������λ
	for(int i = 1; i < 10; i++)
	{
		if(countNum[i])
		{
			ans[index++] = i;
			countNum[i]--;
			break;
		}
	} 
	//����λ 
	for(int i = 0; i < 10; i++)
	{
		if(countNum[i])
		{
			while(countNum[i]--)
			{
				ans[index++] = i;
			}
		}	
	}
	for(int i = 0; i < index; i++)
	{
		
	}
	return 0;
}
