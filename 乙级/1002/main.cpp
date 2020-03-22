#include <bits/stdc++.h>
using namespace std;
string str;
char ans[20];
int main(int argc, char** argv) {
	cin >> str;
	int len = str.size();
	int sum = 0;
	while(len--)
	{
		int temp = str[len] - '0';
		sum += temp;
	}
	sprintf(ans, "%d", sum);
	int charlen = strlen(ans);
	for(int i = 0; i < charlen; i++)
	{
		int temp = ans[i] - '0';
		if(i < charlen - 1)
		{
			switch(temp)
			{
				case 1:
					printf("yi ");
					break;
				case 2:
					printf("er ");
					break;
				case 3:
					printf("san ");
					break;
				case 4:
					printf("si ");
					break;
				case 5:
					printf("wu ");
					break;
				case 6:
					printf("liu ");
					break;
				case 7:
					printf("qi ");
					break;
				case 8:
					printf("ba ");
					break;
				case 9:
					printf("jiu ");
					break;
				case 0:
					printf("ling ");
					break;
			} 
		}
		if(i == charlen - 1)
		{
			switch(temp)
			{
				case 1:
					printf("yi");
					break;
				case 2:
					printf("er");
					break;
				case 3:
					printf("san");
					break;
				case 4:
					printf("si");
					break;
				case 5:
					printf("wu");
					break;
				case 6:
					printf("liu");
					break;
				case 7:
					printf("qi");
					break;
				case 8:
					printf("ba");
					break;
				case 9:
					printf("jiu");
					break;
				case 0:
					printf("ling");
					break;
			} 
		}
	}
	
	return 0;
}
