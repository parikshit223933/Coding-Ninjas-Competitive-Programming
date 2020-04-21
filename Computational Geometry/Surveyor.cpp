/* A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
Input Format
String s
Array of length of string
Output Format
Area
Constraints
direction will have between 4 and 50 characters inclusive.
length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
Sample Test Case
"NWWSE"
{10,3,7,10,10}
Returns: 100


"NESWNWSW"
{20,200,30,100,20,30,10,70}
Returns: 4700 */




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