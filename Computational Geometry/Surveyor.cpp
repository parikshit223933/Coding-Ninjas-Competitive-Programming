#include <bits/stdc++.h>
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
    point *points;
    polygon(int number_of_points)
    {
        points = new point[number_of_points];
    }
};
double area(polygon p, int n)
{
    double total_area = 0;
    for (int i = 1; i < n - 1; i++)
    {
        double x1 = p.points[i].x - p.points[0].x;
        double y1 = p.points[i].y - p.points[0].y;
        double x2 = p.points[i + 1].x - p.points[0].x;
        double y2 = p.points[i + 1].y - p.points[0].y;
        double cross_product = x1 * y2 - y1 * x2;
        total_area += cross_product;
    }
    return abs(total_area / 2);
}
int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int *arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    point p1;
    p1.x = 60000;
    p1.y = 60000;
    polygon poly(n);
    poly.points[0] = p1;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'N')
        {
            poly.points[i].x = poly.points[i - 1].x;
            poly.points[i].y = poly.points[i - 1].y + arr[i - 1];
        }
        else if (s[i - 1] == 'S')
        {
            poly.points[i].x = poly.points[i - 1].x;
            poly.points[i].y = poly.points[i - 1].y - arr[i - 1];
        }
        else if (s[i - 1] == 'W')
        {
            poly.points[i].x = poly.points[i - 1].x - arr[i - 1];
            poly.points[i].y = poly.points[i - 1].y;
        }
        else if (s[i - 1] == 'E')
        {
            poly.points[i].x = poly.points[i - 1].x + arr[i - 1];
            poly.points[i].y = poly.points[i - 1].y;
        }
    }
    cout << (int)area(poly, n) << endl;
}