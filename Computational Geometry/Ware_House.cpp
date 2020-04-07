#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#include <climits>
#include <math.h>
using namespace std;
struct point
{
    double x, y;
};
inline double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
inline bool sorter(point p1, point p2)
{
    if (p1.y < p2.y)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<double> x_points;
    vector<double> y_points;
    for (int i = 0; i < n; i++)
    {
        double element;
        cin >> element;
        x_points.push_back(element);
    }
    for (int i = 0; i < n; i++)
    {
        double element;
        cin >> element;
        y_points.push_back(element);
    }
    point *arr = new point[n];
    for (int i = 0; i < n; i++)
    {
        point p;
        p.x = x_points[i];
        p.y = y_points[i];
        arr[i] = p;
    }
    sort(arr, arr + n, sorter);
    double max_distance = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        max_distance = max(max_distance, distance(arr[i].x, arr[i].y, arr[i + 1].x, arr[i + 1].y));
    }
    max_distance=max(max_distance, 200-arr[n-1].y);
    max_distance=max(max_distance, arr[0].y-0);
    if(max_distance==(double)((int)max_distance))
    {
        cout<<max_distance-1<<endl;
    }
    else
    {
        cout<<(int)max_distance<<endl;
    }
}