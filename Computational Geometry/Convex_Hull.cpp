/* Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.
Input Format
Integer N(Number Of points)
Array of X coordinates
Array of Y coordinates
Output Format
X coordinate and Y coordinate of all the points seperated by space. Order doesn't matter.
Sample Testcase
Input
7
2 1 6 5 3 7 9
2 5 1 5 7 6 4
Output
1 5
2 2
6 1
9 4
7 6
3 7 */




#include <iostream>
#include <vector>
using namespace std;
struct point
{
    int x, y;
};
bool crosser(point p, point q, point r)
{
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - q.x;
    int y2 = r.y - q.y;
    int value = x1 * y2 - y1 * x2;
    return value < 0; //will change only when the cross prod is greater than 0
    //if the cross product is =0, then the points are colinear.
}
void convex_hull(point *points, int n)
{
    vector<point> hull;
    int left = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[left].x)
        {
            left = i;
        }
    }
    //now left contains the index of the left most point
    int p = left;
    do
    {
        hull.push_back(points[p]);
        int q = (p + 1) % n; //so that it loops over the array(circular array)
        for (int i = 0; i < n; i++)
        {
            if (crosser(points[p], points[q], points[i]))
            {
                q = i;
            }
        }
        p = q;
    } while (p != left);
    for (auto i : hull)
    {
        cout << i.x << " " << i.y << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr_x = new int[n];
    int *arr_y = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr_x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr_y[i];
    }
    point *points = new point[n];
    for (int i = 0; i < n; i++)
    {
        point p;
        p.x = arr_x[i];
        p.y = arr_y[i];
        points[i] = p;
    }
    convex_hull(points, n);
}