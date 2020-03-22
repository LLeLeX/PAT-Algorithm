#include <bits/stdc++.h>
using namespace std;
const double CLKTCK = 100;
double C1, C2; 
int main(int argc, char** argv) {
	scanf("%lf%lf", &C1, &C2);
	double temp = round((C2 - C1) / CLKTCK);
	int h, m, s;
	h = temp / 3600;
	int hret;
	hret = (int)temp % 3600;
	m = hret / 60;
	s = hret % 60; 
	printf("%02d:%02d:%02d", (int)h, (int)m, (int)s);
	return 0;
}
