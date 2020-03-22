#include <bits/stdc++.h>
using namespace std;
struct person{
	char name[10];
	int yy, mm, dd;
}oldest, youngest, Left, Right, temp;
//left，right存放合法日期 
bool LessEqu(person a, person b)
{
	if(a.yy != b.yy)
		return a.yy <= b.yy;
	else if(a.mm != b.mm)
		return a.mm <= b.mm;
	else
		return a.dd <= b.dd;
}
bool MoreEqu(person a, person b)
{
	if(a.yy != b.yy)
		return a.yy >= b.yy;
	else if(a.mm != b.mm)
		return a.mm >= b.mm;
	else
		return a.dd >= b.dd;
}
void init()
{
	youngest.yy = Left.yy = 1814;
	oldest.yy = Right.yy = 2014;
	youngest.mm = oldest.mm = Left.mm = Right.mm = 9;
	youngest.dd = oldest.dd = Left.dd = Right.dd = 6;
}
int main(int argc, char** argv) {
	init();
	int n, num = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
		if(MoreEqu(temp, Left) && LessEqu(temp, Right))
		{
			num++;
			if(LessEqu(temp, oldest))
				oldest = temp;
			if(MoreEqu(temp, youngest))
				youngest = temp;
		}
	}
	if(num == 0)
		printf("0");
	else
		printf("%d %s %s", num, oldest.name, youngest.name);
	return 0;
}
