#include <bits/stdc++.h>
using namespace std;
char num[15][15] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char unit[10][10] = {"ge", "Shi", "Bai", "Qian", "Wan", "Yi"};
int main(int argc, char *argv[]) {
	char N[15];
	scanf("%s", N);
	int len = strlen(N);
	int left = 0, right = len - 1;
	if(len == 1 && N[0] == '0')//就一位且还是0 
	{
		printf("ling");
	}
	else
	{
		if(N[0] == '-')
		{
			printf("Fu"); 
			left++;
		}
		while(left + 4 <= right)//从最高节开始 
		{
			right -= 4;//保证了left，right在同一节，且left在高位，right在该节的最低位 
		}
		while(left < len)
		{
			bool flag = false;//标记是否有积累的0 
			bool isPrint = false;//是否已经输出过其中的位 
			while(left <= right)//从该节的高位left一直走到低位right 
			{
				if(N[left] == '0')//若当前位为0 
				{
					flag = true;//有积累的0 
				} 
				else//当前位置不为0，说明前面的一串0都已经遍历过了 
				{
					if(flag == true)//前面已经有积累的0了
					{
						printf(" ling");//发音一次0即可 
						flag = false;//flag重置 
					} 
					if(left > 0)//表示不是首位 ，即不是第一个输出的元素，则在前面先输出空格
					{
						printf(" ");
					}	
					int indexNum = N[left] - '0';
					printf("%s", num[indexNum]);
					isPrint = true;//该节有过输出
					//处理每一节中的十，百， 千的小单位问题
					if(left != right)//该位不是个位
					{
						int indexUint = right - left;
						printf(" %s", unit[indexUint]);//已设置好空格 
					} 	 
				}
				left++; 
			}
			//处理亿，万大单位问题
			//此节有过输出（避免100000000的情况），且不是个位节 
			if(isPrint == true && right != len - 1)
			{
				int indexUint = (len - 1 - right) / 4 + 3;
				printf(" %s", unit[indexUint]);
			}
			right += 4;
		} 
	}
	return 0;
}
