#include <bits/stdc++.h>
using namespace std;
string str, ansStr;
int ansNum = -1;
map<string, int> words;
bool judge(char c)//判断是否是有效字符 
{
	if(c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a'))
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main(int argc, char *argv[]) {
	getline(cin, str);
	int len = str.length();
	int tempIndex = 0;//记录上一个非字符的位置 
	string tempstr;
	for(int i = 0; i < len; i++)
	{
		if(!judge(str[i]))
		{
			if(!judge(tempstr[0]))
			{
				continue;
			}
			words[tempstr]++;
			tempstr.clear();
			continue;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		tempstr += str[i];
	}
	if(judge(tempstr[0]))
	{
		words[tempstr]++;
	}
	ansNum = words.begin()->second;
	ansStr = words.begin()->first;
	for(map<string, int>::iterator it = words.begin(); it != words.end(); it++)
	{
		//cout << it->first << " " << it->second << endl;
		if(it->second > ansNum)
		{
			ansNum = it->second;
			ansStr = it->first;
		}
	}
	cout << ansStr << " " << ansNum;
	return 0;
}
