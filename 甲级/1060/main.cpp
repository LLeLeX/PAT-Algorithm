#include <bits/stdc++.h>
using namespace std;
int N;
string A, B;
int expA, expB;
string preProcess(string s, int &exp)
{
	int index = 0;
	while(s.length() > 0 && s[0] == '0')
	{
		s.erase(0, 1);//去除前导0 
	}
	if(s[0] == '.')//第一位是小数点，原数是小于1的数字 
	{
		s.erase(0, 1);//去除小数点
		while(s.length() > 0 && s[0] == '0')//小数点后的0 
		{
			exp--;
			s.erase(0, 1);
		} 
	}
	else//原数大于1，寻找小数点 
	{
		while(index < s.length() && s[index] != '.')
		{
			index++;
			exp++;
		}
		if(index < s.length())//小数点在原数中间，说明原数有小数部分 
		{
			s.erase(index, 1);
		}//否则原数即为整数 
	} 
	if(s.length() == 0)//除去前导0之后，长度为0，则原数即为0 
	{
		exp = 0;
	} 
	int validnum = 0;
	index = 0;
	string res;
	while(validnum < N)
	{
		if(index < s.length())
		{
			res += s[index++];
		}
		else
		{
			res += '0';
		}
		validnum++;
	}
	return res;
}
int main(int argc, char *argv[]) {
	cin >> N >> A >> B;
	string resA = preProcess(A, expA);
	string resB = preProcess(B, expB);
	if(resA == resB && expA == expB)
	{
		cout << "YES 0." << resA << "*10^" << expA;
	}
	else
	{
		cout << "NO 0." << resA << "*10^" << expA << " 0." << resB << "*10^" << expB;
	}
	return 0;
}
