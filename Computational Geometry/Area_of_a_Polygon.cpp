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