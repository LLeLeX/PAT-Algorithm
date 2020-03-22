/*#include <bits/stdc++.h>
using namespace std;
int N, M;
struct student{
	string id;
	int seat1;
	int seat2;
	student(){}
	student(string str, int s1, int s2)
	{
		id = str;
		seat1 = s1;
		seat2 = s2;
	}
};
bool cmp(student st1, student st2)
{
	return st1.seat1 < st2.seat1;
}
int main(int argc, char** argv) {
	scanf("%d", &N);
	student stu[N + 3];
	for(int i = 1; i <= N; i++)
	{
		string str;
		int s1, s2;
		cin >> str >> s1 >> s2;
		stu[i] = {str, s1, s2};
	}
	sort(stu, stu + N + 1, cmp);
	scanf("%d", &M);
	while(M--)
	{
		int temp;
		scanf("%d", &temp);
		for(int i = 1; i <= N; i++)
		{
			if(temp == stu[i].seat1)
			{
				if(M >= 1)
					cout << stu[i].id << " " << stu[i].seat2 << endl;
				else
					cout << stu[i].id << " " << stu[i].seat2;
			}
		}
	}
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int N, M;
struct student{
	string id;
	int seat;
	student(){}
	student(string str, int s)
	{
		id = str;
		seat = s;
	}
}stu[1010];
int main(int argc, char** argv) {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		string str;
		int s1, s2;
		cin >> str >> s1 >> s2;
		stu[s1] = {str, s2};
	}
	scanf("%d", &M);
	while(M--)
	{
		int temp;
		scanf("%d", &temp);
		if(M >= 1)
			cout << stu[temp].id << " " << stu[temp].seat << endl;
		else
			cout << stu[temp].id << " " << stu[temp].seat;
	}
	return 0;
}
