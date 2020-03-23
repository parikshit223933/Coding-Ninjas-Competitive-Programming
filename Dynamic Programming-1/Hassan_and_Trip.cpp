#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
double distanc(double *x, double *y, int i, int j)
{
	double difference_x=x[i]-x[j];
	double difference_y=y[i]-y[j];
	double ans= sqrt((difference_x*difference_x)+(difference_y*difference_y));
	return ans;
}
inline void maximum_happiness(double *x, double *y, double *f, int n)
{
	double *dp=new double [3030];
	for(int i = 0; i < n; i++)
        dp[i] = -1e9;
	dp[0]=0;
	for(int i=0; i<n; i++)
	{
		dp[i]+=f[i];
		for(int j=i+1; j<n; j++)
		{
			double dist=distanc(x, y, i, j);
			dp[j]=max(dp[j], dp[i]-dist);
		}
	}
	cout<<fixed;
	cout.precision(6);
	cout<< dp[n-1];
	delete[]dp;
}
int main()
{
	int n;
	cin>>n;
	double *x=new double [3030];
	double *y=new double [3030];
	double *f=new double [3030];
	for(int i=0; i<n; i++)
	{
		cin>>x[i]>>y[i]>>f[i];
	}
	maximum_happiness(x, y, f, n);
	delete[]x;
	delete[]y;
	delete[]f;
}