#include <bits/stdc++.h>
using namespace std;
int N;
int main(int argc, char** argv) {
	scanf("%d", &N);
	//a:¼×,b:ÒÒ 
	int cnta = 0, cntb = 0;
	while(N--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		//¼×Ó® 
		if(b == a + c && d != a + c)
		{
			cntb++;
		}
		//ÒÒÓ® 
		if(d == a + c && b != a + c)
		{
			cnta++;
		} 
	}
	printf("%d %d", cnta, cntb);
	return 0;
}
