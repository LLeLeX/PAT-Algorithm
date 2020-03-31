#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ag, as, ak;
ll bg, bs, bk;
ll ansg, anss, ansk;
ll cnt;//½øÎ» 
int main(int argc, char *argv[]) {
	scanf("%lld.%lld.%lld", &ag, &as, &ak);
	scanf("%lld.%lld.%lld", &bg, &bs, &bk);
	if(ak + bk < 29)
	{
		ansk = ak + bk;
		cnt = 0;
	}
	else
	{
		ansk = (ak + bk) % 29;
		cnt = (ak + bk) / 29;
	}
	if(as + bs + cnt < 17)
	{
		anss = as + bs + cnt;
		cnt = 0;
	}
	else
	{
		anss = (as + bs + cnt) % 17;
		cnt = (as + bs) / 17;
	}
	ansg = ag + bg + cnt;
	printf("%lld.%lld.%lld", ansg, anss, ansk);
	return 0;
}
