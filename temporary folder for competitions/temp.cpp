#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include<math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define INF 1000000007 
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;

struct point
{
    int x, y;
};

/* it will return a boolean value based on weather we have to change or not. */
bool change(point p, point q, point r)
{
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - q.x;
    int y2 = r.y - q.y;

    int value = (x1 * y2) - (y1 * x2);

    return value > 0;
}

/* it will give the convex hull for an array for points */
vector<point> convex_hull(point* points, int n)
{
    vector<point>hull;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        if (points[i].x < points[left].x)
        {
            left = i;
        }
    }

    int p = left;
    do
    {
        hull.push_back(points[p]);
        int q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (change(points[p], points[q], points[i]))
            {
                q = i;
            }
        }
        p = q;
    } while (p != left);

    return hull;
}

/* checks if the point q lies on the line segment pr */
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear 
    return (val > 0) ? 1 : 2; // clock or counterclock wise 
}

// The function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect.
bool doIntersect(point p1, point q1, point p2, point q2)
{
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case 
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases 
}

// Returns true if the point p lies inside the polygon[] with n vertices 
bool isInside(vector<point> polygon, int n, point p)
{
    // There must be at least 3 vertices in polygon[] 
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite 
    point extreme = { INF, p.y };

    // Count intersections of the above line with sides of polygon 
    int count = 0, i = 0;
    do
    {
        int next = (i + 1) % n;

        // Check if the line segment from 'p' to 'extreme' intersects 
        // with the line segment from 'polygon[i]' to 'polygon[next]' 
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next', 
            // then check if it lies on segment. If it lies, return true, 
            // otherwise false 
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise 
    return count & 1;  // Same as (count%2 == 1) 
}

int distance(point a, point b)
{
    int x = a.x - b.x;
    int y = a.y - b.y;
    return sqrt((x * x) + (y * y));
}

/* to sort the distance array */
bool distance_sorter(pair<point, int>a, pair<point, int>b)
{
    if (a.second < b.second)
    {
        return true;
    }
    return false;
}

/* this gives the deliciousness of cake */
int deliciousness(point* arr, int n, int query_x, int query_y)
{
    vector<point> points = convex_hull(arr, n);
    point p;
    p.x = query_x;
    p.y = query_y;
    if (!isInside(points, points.size(), p))
    {
        return 0;
    }

    /* mapping the point to its distance from p. */
    pair<point, int>* distance_array = new pair<point, int>[n];
    for (int i = 0; i < n; i++)
    {
        distance_array[i].first = arr[i];
        distance_array[i].second = distance(p, arr[i]);
    }
    /* sorting the distance array according to the small distance */
    sort(distance_array, distance_array + n, distance_sorter);

    /* keeping a count and initializing a visited array */
    int count = 0;
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 2; i < n; i++)
    {
        vector<point>v;
        vector<int>indices;
        for (int j = 0; j <= i; j++)
        {
            if (!visited[j] && distance_array[j].second!=0)
            {
                v.push_back(distance_array[j].first);
                indices.push_back(j);
            }
        }
        if (v.size() < 3)
        {
            continue;
        }
        point* temp = new point[v.size()];
        for (int k = 0; k < v.size(); k++)
        {
            temp[k] = v[k];
        }
        if (isInside(convex_hull(temp, v.size()), v.size(), p))
        {
            count++;
            for (auto ind : indices)
            {
                visited[ind] = true;
            }
        }
        else
        {
            continue;
        }
    }
    return count;
}



int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        point* arr = new point[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].x >> arr[i].y;
        }
        for (int i = 0; i < q; i++)
        {
            int query_x, query_y;
            cin >> query_x >> query_y;
            cout << deliciousness(arr, n, query_x, query_y) << endl;
        }
    }
    return 0;
}