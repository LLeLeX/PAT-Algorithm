#include <bits/stdc++.h>
using namespace std;
int pg, ps, pk;
int ag, as, ak;
int ansg, anss, ansk;
bool judge()
{
	//trueÕıÊı 
	if(ag > pg)
	{
		return true;
	}
	else if(ag == pg)
	{
		if(as > ps)
		{
			return true;
		}
		else if(as == ps)
		{
			if(ak >= pk)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int main(int argc, char** argv) {
	scanf("%d.%d.%d", &pg, &ps, &pk);
	scanf("%d.%d.%d", &ag, &as, &ak);
	if(judge())
	{
		if(ak >= pk)
		{
			ansk = ak - pk;
		}
		else
		{
			as--;
			ak += 29;
			ansk = ak - pk;
		}
		if(as >= ps)
		{
			anss = as - ps;
		}
		else
		{
			ag--;
			as += 17;
			anss = as - ps;
		}
		ansg = ag - pg;
		printf("%d.%d.%d", ansg, anss, ansk);	
	}
	else
	{
		if(pk >= ak)
		{
			ansk = pk - ak;
		}
		else
		{
			ps--;
			pk += 29;
			ansk = pk - ak;
		}
		if(ps >= as)
		{
			anss = ps - as;
		}
		else
		{
			pg--;
			ps += 17;
			anss = ps - as;
		}
		ansg = pg - ag;
		printf("-%d.%d.%d", ansg, anss, ansk);
	}
	return 0;
}
