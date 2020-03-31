#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int N, L, H, cnt;
struct Student{
	int ID;
	int talent;
	int virtue;
	int total;
	int rank;
	int tag = 4;
	Student(){}
	Student(int id, int ta, int vv, int to)
	{
		ID = id;
		talent = ta;
		virtue = vv;
		total = to;
	}
}stu[maxn];
bool totalcmp(Student s1, Student s2)
{
	return s1.total > s2.total;
}
bool tagcmp(Student s1, Student s2)
{
	if(s1.tag != s2.tag)
	{
		return s1.tag < s2.tag;
	}
	else if(s1.total != s2.total)
	{
		return s1.total > s2.total;
	}
	else if(s1.virtue != s2.virtue)
	{
		return s1.virtue > s2.virtue;
	}
	else
	{
		return s1.ID < s2.ID;
	}
}

int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &L, &H);
	for(int i = 0; i < N; ++i)
	{
		int id, vv, ta, to;
		scanf("%d%d%d", &id, &vv, &ta);
		if(vv < L || ta < L)
			continue;
		to = vv + ta;
		stu[cnt++] = Student(id, ta, vv, to);
	}
	sort(stu, stu + cnt, totalcmp);
	stu[0].rank = 1;
	for(int i = 1; i < cnt; ++i)
	{
		if(stu[i].total == stu[i - 1].total)
			stu[i].rank = stu[i - 1].rank;
		else
			stu[i].rank = i;
	}	
	for(int i = 0; i < cnt; ++i)
	{
		Student s = stu[i];
		if(s.virtue >= H && s.talent >= H)//第一类 
		{
			stu[i].tag = 1;
		}
		else if(s.virtue >= H && s.talent < H)//第二类 
		{
			stu[i].tag = 2;
		}
		else if(s.virtue < H && s.talent < H && s.virtue >= s.talent)//第三类
		{
			stu[i].tag = 3;
		} 
		else
		{
			stu[i].tag = 4;
		}
	}
	sort(stu, stu + cnt, tagcmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; ++i)
	{
		printf("%d %d %d\n", stu[i].ID, stu[i].virtue, stu[i].talent);
	}
	return 0;
}
