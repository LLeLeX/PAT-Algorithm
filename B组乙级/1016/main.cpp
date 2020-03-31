#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL A, B;
int Da, Db;
int main(int argc, char** argv) {
	scanf("%lld%d%lld%d", &A, &Da, &B, &Db);
	LL Pa = 0, Pb = 0;
	int cnta = 0, cntb = 0;
	while(A)
	{
		int ret = A % 10;
		if(ret == Da)
		{
			Pa += Da * pow(10, cnta);
			cnta++;
		}
		A = A / 10;
	}
	while(B)
	{
		int ret = B % 10;
		if(ret == Db)
		{
			Pb += Db * pow(10, cntb);
			cntb++;
		}
		B = B / 10;
	}
	printf("%lld", Pa + Pb);
	return 0;
}
