#include <bits/stdc++.h>
using namespace std;
int N;
int awin, adead, alose;
int bwin, bdead, blose;
//apose[1]:´¸×Ó£¬apose[2]:¼ôµ¶ 
int apose[4], bpose[4];
int main(int argc, char** argv) {
	scanf("%d", &N);
	//aÎª¼×,bÎªÒÒ 
	while(N--)
	{
		char a, b;
		getchar();
		scanf("%c %c", &a, &b);
		if(a == b)
		{
			adead++;
			bdead++;
		}
		else
		{
			if(a == 'C' && b == 'J')
			{
				awin++;
				blose++;
				apose[1]++;
			}
			else if(a == 'C' && b == 'B')
			{
				alose++;
				bwin++;
				bpose[3]++;
			}
			else if(a == 'J' && b == 'C')
			{
				alose++;
				bwin++;
				bpose[1]++;
			}
			else if(a == 'J' && b == 'B')
			{
				awin++;
				blose++;
				apose[2]++;
			}
			else if(a == 'B' && b == 'C')
			{
				awin++;
				blose++;
				apose[3]++;
			}
			else if(a == 'B' && b == 'J')
			{
				alose++;
				bwin++;
				bpose[2]++;
			}
		}
	}
	printf("%d %d %d\n", awin, adead, alose);
	printf("%d %d %d\n", bwin, bdead, blose);
	char ansa, ansb;
	ansa = apose[3] >= max(apose[1], apose[2]) ? 'B' : apose[1] >= apose[2] ? 'C' : 'J';
	ansb = bpose[3] >= max(bpose[1], bpose[2]) ? 'B' : bpose[1] >= bpose[2] ? 'C' : 'J';
	printf("%c %c", ansa, ansb);
	return 0;
}
