#include <bits/stdc++.h>
using namespace std;
int n;
int main(int argc, char *argv[]) {
	scanf("%d", &n);
	while(n--)
	{
		string str;
		cin >> str;
		int numP = 0, numT = 0, numOther = 0;
		int posP, posT;
		int len = str.length(); 
		for(int i = 0; i < len; ++i)
		{
			if(str[i] == 'P')
			{
				numP++;
				posP = i;
			}
			else if(str[i] == 'T')
			{
				numT++;
				posT = i;
			}
			else if(str[i] != 'A')
			{
				numOther++;
			}
		}
		//P不为1个，T不为1个，有其他的字母，P的位置大于T，P与T之间没有A 
		if(numP != 1 || numT != 1 || numOther != 0 || posP > posT || posP == posT - 1)
		{
			printf("NO\n");
			continue;
		}
		//P左侧A的个数，PT之间的A的个数，T右侧A的个数 
		int leftA = posP, middA = posT - posP - 1, rightA = len - posT - 1;
		bool flag = false;//答案正确为true 
		while(1)
		{
			if(middA == 1)
			{
				if(leftA == rightA)
				{
					flag = true;
				}
				break;
			}
			middA = middA - 1;
			rightA = rightA - leftA; 
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
