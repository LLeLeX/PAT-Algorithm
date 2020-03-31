#include <bits/stdc++.h>
using namespace std;
int N, M;
map<string, set<int> >mp;
void dealString(string str, int id)
{
	int len = str.length();
	string tempStr;
	for(int i = 0; i < len; i++)
	{
		if(str[i] == ' ')
		{
			mp[tempStr].insert(id);
			tempStr.clear();
		}
		else
		{
			tempStr += str[i];
		}
	}
	mp[tempStr].insert(id);
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	getchar();
	for(int i = 0; i < N; i++)
	{
		int id;
		string title, auth, words, pub, year;
		scanf("%d", &id);
		getchar();
		getline(cin, title);
		mp[title].insert(id);
		getline(cin, auth);
		mp[auth].insert(id);
		getline(cin, words);
		dealString(words, id);
		getline(cin, pub);
		mp[pub].insert(id);
		getline(cin, year);
		mp[year].insert(id);
	}
	/*cout << "************" << endl;
	string a = "book";
	map<string, set<int> >::iterator it1 = mp.find(a);
	if(it1 != mp.end())//查找成功 
	{
		for(set<int>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
			printf("%d\n", *it2);
		}
	}
	cout << "************" << endl;*/
	scanf("%d", &M);
	getchar();
	while(M--)
	{
		string ques;
		getline(cin, ques);
		//char c = ques[0];
		cout << ques << endl;
		string text;
		int len = ques.length();
		for(int i = 3; i < len; i++)
		{
			text += ques[i];
		}
		map<string, set<int> >::iterator it = mp.find(text);
		if(it != mp.end())//查找成功 
		{
			for(set<int>::iterator itset = it->second.begin(); itset != it->second.end(); itset++)
			{
				printf("%07d\n", *itset);
			}
		}
		else
		{
			printf("Not Found\n");
		}
		/*for(map<string, set<int> >::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if(it->first == text)
			{
				for(set<int>::iterator itset = it->second.begin(); itset != it->second.end(); itset++)
				{
					printf("%d\n", *itset);
				}
			}
		}*/
		//cout << text << endl;
		/*switch (c)
		{
			case '1':
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
				break;
		}*/
	} 
	return 0;
}
