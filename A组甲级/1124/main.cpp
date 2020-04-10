#include <bits/stdc++.h>
using namespace std;
int M, N, S;
//map<string, int> name2id;
//map<int, string> id2name;
map<string, bool> isWinner;
vector<string> winner;
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &M, &N, &S);
	getchar();
	int next = S;
	for(int i = 1; i <= M; ++i)
	{
		string name;
		cin >> name;
		if(i == S)
		{
			isWinner[name] = true;
			next += N;
			winner.push_back(name);
			continue;
		}
		if(i == next)
		{
			if(isWinner[name] == false)
			{
				isWinner[name] = true;
				next += N;
				winner.push_back(name);
			}
			else
			{
				next += 1;
			}
		}
	}
	if(winner.size() == 0)
		printf("Keep going...\n");
	else
	{
		for(int i = 0; i < winner.size(); ++i)
		{
			cout << winner[i] << endl;
		}
	}
	return 0;
}
