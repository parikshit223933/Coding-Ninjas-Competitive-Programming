#include<iostream>
#define endl '\n'
using namespace std;
class point
{
    public:
    double x, y;
};
class polygon
{
    public:
    point*points;
    polygon(int number_of_points)
    {
        points=new point [number_of_points];
    }

};
double area(polygon p, int n)
{
    double total_area=0;
    for(int i=1; i<n-1; i++)
    {
        double x1=p.points[i].x-p.points[0].x;
        double y1=p.points[i].y-p.points[0].y;
        double x2=p.points[i+1].x-p.points[0].x;
        double y2=p.points[i+1].y-p.points[0].y;
        double cross_product=x1*y2-y1*x2;
        total_area+=cross_product;
    }
    return abs(total_area/2);
}
int main()
{
    int n;
    cin>>n;
    polygon p(n);
    for(int i=0; i<n; i++)
    {
        cin>>p.points[i].x>>p.points[i].y;
    }
    //area
    cout<<area(p, n)<<endl;
}