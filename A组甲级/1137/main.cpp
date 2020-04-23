#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;
int P, M, N;
struct Student{
	string name;
	double Gp = -1;
	double Gm = -1;
	double Gf = -1;
	double G = -1;//总分G 
}stu[maxn];
unordered_map<string, int> mp;//名字与下标的映射 

bool cmp(Student s1, Student s2)
{
	if(s1.G != s2.G)
		return s1.G > s2.G;
	else
		return s1.name < s2.name;
}

int main(int argc, char *argv[]) {
	scanf("%d%d%d", &P, &M, &N);
	
	for(int i = 0; i < P; ++i)
	{
		cin >> stu[i].name >> stu[i].Gp;
		mp[stu[i].name] = i;
	}
	//存在新输入的用户 
	int pos = P;
	for(int i = 0; i < M; ++i)
	{
		string nn;
		int ss;
		cin >> nn >> ss;
		if(mp.count(nn) == 0)//新用户 
		{
			stu[pos].name = nn;
			stu[pos].Gm = ss;
			mp[nn] = pos++;
		}
		else
		{
			int id = mp[nn];
			stu[id].Gm = ss;
		}
	}
	for(int i = 0; i < N; ++i)
	{
		string nn;
		int ss;
		cin >> nn >> ss;
		if(mp.count(nn) == 0)//新用户 
		{
			stu[pos].name = nn;
			stu[pos].Gf = ss;
			mp[nn] = pos++;
		}
		else
		{
			int id = mp[nn];
			stu[id].Gf = ss;
		}
	}
	//cout << endl;
	for(int i = 0; i < pos; ++i)
	{
		if(stu[i].Gm > stu[i].Gf)
			stu[i].G = 0.4 * stu[i].Gm + 0.6 * stu[i].Gf;
		else
			stu[i].G = stu[i].Gf;
		
		stu[i].G = round(stu[i].G);	
		//cout << stu[i].name << " " << stu[i].G << endl;
	}
	sort(stu, stu + pos, cmp);
	for(int i = 0; i < pos; ++i)
	{
		if(stu[i].Gp >= 200 && stu[i].G >= 60)
			cout << stu[i].name << " " << stu[i].Gp << " " << stu[i].Gm << " " << stu[i].Gf << " " << stu[i].G << endl;
	}
	
	return 0;
}
