#include <bits/stdc++.h>
using namespace std;
int N;
struct school
{
	int num;
	int score;
	school(){}
	school(int n, int s)
	{
		num = n;
		score = s;
	}	
};
bool cmp(school s1, school s2)
{
	return s1.score > s2.score;
}
school s[100005];
int arr[100005];
int main(int argc, char *argv[]) {
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		s[a].num = a;
		s[a].score += b; 
	}
	sort(s, s + N + 1, cmp);
	cout << s[0].num << " " << s[0].score;
	return 0;
}
