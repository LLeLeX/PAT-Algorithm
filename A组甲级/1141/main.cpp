#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int N;
struct School{
	string id;
	double total = 0.0;
	int cnt = 0;
	int rank;
}sch[maxn];
unordered_map<string, int> schoolmp;
string init(string str)
{
	int len = str.length();
	for(int i = 0; i < len; ++i)
	{
		int temp = 'a' - 'A';
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + temp;
	}
	return str;
}
bool cmp(School s1, School s2)
{
	if((int)s1.total != (int)s2.total)
		return (int)s1.total > (int)s2.total;
	else
	{
		if(s1.cnt != s2.cnt)
			return s1.cnt < s2.cnt;
		else
			return s1.id < s2.id;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int count = 0;//设置学校下标，统计数量 
	for(int i = 0; i < N; ++i)
	{
		string str1, str2;
		double s;
		cin >> str1 >> s >> str2;
		str2 = init(str2);
		//初始化学校
		if(schoolmp.count(str2) == 0)
			schoolmp[str2] = count++;
		int pos = schoolmp[str2];
		sch[pos].id = str2;
		sch[pos].cnt++;
		
		if(str1[0] == 'B')
			s = s / 1.5;
		else if(str1[0] == 'T')
			s = s * 1.5;
		sch[pos].total += s;
	}
	sort(sch, sch + count, cmp);
	printf("%d\n", count);
	sch[0].rank = 1;
	for(int i = 0; i < count; ++i)
	{
		sch[i].total = (int)sch[i].total;
		if(i > 0)
		{
			if(sch[i].total == sch[i - 1].total)
				sch[i].rank = sch[i - 1].rank;
			else
				sch[i].rank = i + 1;
		}
		printf("%d ", sch[i].rank);
		cout << sch[i].id << " ";
		printf("%d %d\n", (int)sch[i].total, sch[i].cnt);
	}
	return 0;
}
