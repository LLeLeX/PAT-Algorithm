#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);//PI
const double eps = 1e-5;//¾«¶È 
double getr(double R, double h)
{
	double alpha = 2 * acos((R - h) / R);
	double L = 2 * sqrt(R * R - (R - h) * (R - h));
	double S1 = alpha * R * R / 2 - L * (R - h) / 2; 
	return S1 / S2;
}
double solve(double R, double r)
{
	double left = 0, right = R, mid;
	while(right - left > eps)
	{
		mid = (left + right) / 2;
		if(getr(R, mid) > r)
		{
			right = mid;
		}
		else if(getr(R, mid) <= r)
		{
			left = mid;
		}
	}
	return mid;
}
int main(int argc, char *argv[]) {
 	double R, r;
	scanf("%lf%lf", &R, &r);
	printf("%.4f\n", solve(R, r));
	return 0;
}
