#include <bits/stdc++.h>
using namespace std;
int n;
int main(int argc, char *argv[]) {
	while(scanf("%d", &n), n != 0)
	{
		
		while(n--)
		{
			/*double x1, x2, x3, y1, y2, y3;
			scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
			ansx = x1 + x2 + x3;
			ansy = y1 + y2 + y3;*/
			double ansx = 0, ansy = 0;
			for(int i = 0; i < 3; i++)
			{
				pair<double, double> p;
				scanf("%lf%lf", &p.first, &p.second);
				ansx += p.first;
				ansy += p.second;
			}
			printf("%.1f %.1f\n", ansx / 3, ansy / 3);
		}
	}
	return 0;
}
