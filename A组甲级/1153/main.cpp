#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int N, M;
struct Student{
	string id;
	char level;
	int site;
	int date;
	int score;
}stu[maxn];
int siteCnt[1010];
int siteScore[1010];
int levelCnt[26];
unordered_map<int, int> timeCnt;
unordered_map<int,unordered_map<int,int> > mp;
struct Site{
	int siteid;
	int num;
	Site(){}
	Site(int ss, int nn)
	{
		siteid = ss;
		num = nn;
	}
};
bool cmp(Student s1, Student s2)
{
	if(s1.level != s2.level)
		return s1.level < s2.level;
	else if(s1.score != s2.score)
		return s1.score > s2.score;
	else
		return s1.id < s2.id;
}
bool cmpans(Site s1, Site s2)
{
	if(s1.num != s2.num)
		return s1.num > s2.num;
	else
		return s1.siteid < s2.siteid;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i)
	{
		string str;
		cin >> str >> stu[i].score;
		stu[i].id = str;
		stu[i].level = str[0];
		for(int j = 1; j < 4; ++j)
		{
			stu[i].site = stu[i].site * 10 + (str[j] - '0');
		}
		for(int j = 4; j < 10; ++j)
		{
			stu[i].date = stu[i].date * 10 + (str[j] - '0');
		}
		siteCnt[stu[i].site]++;
		siteScore[stu[i].site] += stu[i].score;	
		int pos = stu[i].level - 'A';
		levelCnt[pos]++;
		timeCnt[stu[i].date]++;
		mp[stu[i].date][stu[i].site]++;
	}
	sort(stu, stu + N, cmp);
	for(int m = 1; m <= M; ++m)
	{
		int type;
		scanf("%d", &type);
		if(type == 1)//等级考试成绩排序 
		{
			char lev;
			scanf(" %c", &lev);
			printf("Case %d: 1 %c\n", m, lev);
			int pos = lev - 'A';
			if(levelCnt[pos] == 0)
			{
				printf("NA\n");
				continue;
			}
			int start, end;
			if(lev == 'A')
			{
				start = 0, end = levelCnt[0];
			}
			else if(lev == 'B')
			{
				start = levelCnt[0];
				end = start + levelCnt[1];
			}
			else if(lev == 'T')
			{
				
				start = levelCnt[0] + levelCnt[1];
				end = start + levelCnt[pos];
			}
			for(int i = start; i < end; ++i)
			{
				cout << stu[i].id << " " << stu[i].score << endl;
			}
			
		}
		else if(type == 2)//同一考点的人数和总分 
		{
			int ss;
			scanf("%d", &ss);
			printf("Case %d: 2 %d\n", m, ss);
			if(siteCnt[ss] == 0 && siteScore[ss] == 0)
				printf("NA\n");
			else
				printf("%d %d\n", siteCnt[ss], siteScore[ss]);
		}
		else//同一时间各考点的考试人数并排序 
		{
			int dd;
			scanf("%d", &dd);
			printf("Case %d: 3 %06d\n", m, dd); 
			if(timeCnt[dd] == 0)
			{
				printf("NA\n");
				continue;
			}
			vector<Site> ans;
			for(auto it = mp[dd].begin(); it != mp[dd].end(); ++it)
			{
				ans.push_back(Site(it->first, it->second));
			}
			sort(ans.begin(), ans.end(), cmpans);
			for(int i = 0; i < ans.size(); ++i)
			{
				printf("%d %d\n", ans[i].siteid, ans[i].num);
			}	
		}
	}
	return 0;
}
