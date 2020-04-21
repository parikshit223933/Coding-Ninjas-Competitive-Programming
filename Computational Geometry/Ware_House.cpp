/* Our warehouse is square, 200 feet on each side, with solid north and south walls. The east and west walls have sliding doors which allow trucks free entry and exit. Trucks come in a variety of sizes, but the width of each truck is an integer number of feet. Unfortunately the roof is supported by posts (of negligible size).
We want to drive big trucks in a straight line into the warehouse through the west wall and (after unloading and without changing direction) out through the east wall. Find the width of the widest truck (of integral width) that can drive straight through without touching any posts (or the north or south wall). The positions of the posts are given by int[] x and int[] y: the i-th element of x and y gives the distance in feet east and north respectively from the southwest corner of the building to the i-th post.
Input Format
Integer N
Vector x of size N
Vector y of size N
Output Format
Width of Track
Constraints
x has between 1 and 50 elements inclusive
y has the same number of elements as x
each element of x and y is between 0 and 200 inclusive
Sample Testcase
3       
100 100 120
60 140 180
Returns: 79
The best path is due east, but the first and second posts are only 80 feet apart so the truck must be less than 80 feet wide. */




//see previous commits for my code
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
//64 bit integer definition
#ifdef WIN32
#define in_routine(type, spec)               \
    istream &operator>>(istream &s, type &d) \
    {                                        \
        char b[30];                          \
        s >> b;                              \
        sscanf(b, spec, &d);                 \
        return s;                            \
    }
#define out_routine(type, spec)             \
    ostream &operator<<(ostream &s, type d) \
    {                                       \
        char b[30];                         \
        sprintf(b, spec, d);                \
        s << b;                             \
        return s;                           \
    }
typedef signed __int64 i64;
in_routine(i64, "%I64d") out_routine(i64, "%I64d") typedef unsigned __int64 u64;
in_routine(u64, "%I64u") out_routine(u64, "%I64u")
#else
typedef signed long long i64;
typedef unsigned long long u64;
#endif
//common routines
#ifdef WIN32
#define min(a, b) _cpp_min(a, b)
#define max(a, b) _cpp_max(a, b)
#endif
#define abs(a) ((a) > 0 ? (a) : -(a))
#define s2d(s, d)              \
    {                          \
        istringstream(s) >> d; \
    }
#define d2s(d, s)        \
    {                    \
        ostringstream t; \
        t << d;          \
        s = t.str();     \
    }
    int gcd(int a, int b)
{
    for (int c; b; c = a, a = b, b = c % b)
        ;
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
//remove routine
template <class T>
void remove(vector<T> &v, const T &e)
{
    v.resize(remove(v.begin(), v.end(), e) - v.begin());
}
template <class T>
vector<T> remove_copy(vector<T> &v, const T &e)
{
    vector<T> result;
    remove_copy(v.begin(), v.end(), back_inserter(result), e);
    return result;
}
//output routine
ostream &operator<<(ostream &s, string d)
{
    s << '\"' << d.c_str() << '\"';
    return s;
}
template <class T>
ostream &operator<<(ostream &s, vector<T> d)
{
    s << "{";
    for (typename vector<T>::iterator i = d.begin(); i != d.end(); i++)
        s << (i != d.begin() ? "," : "") << *i;
    s << "}";
    return s;
}
//parsing routine
template <class T>
vector<basic_string<T>> parse(const basic_string<T> &s, const basic_string<T> &delim)
{
    vector<basic_string<T>> ret(0);

    for (int b, e = 0;; ret.push_back(s.substr(b, e - b)))
        if ((b = s.find_first_not_of(delim, e)) == (e = s.find_first_of(delim, b)))
            return ret;
}
vector<int> intparse(const string &s, const string &delim = " \t\n")
{
    vector<string> tmp = parse(s, delim);
    vector<int> ret(0);
    int t;
    for (vector<string>::iterator i = tmp.begin(); i != tmp.end(); i++)
        sscanf(i->c_str(), "%d", &t), ret.push_back(t);
    return ret;
}
//name mapper
class mapper
{
public:
    map<string, int> m;
    vector<string> v;
    void reset()
    {
        v.clear();
        m.clear();
    }
    int size()
    {
        return v.size();
    }
    int get(const string str)
    {
        if (m.find(str) == m.end())
        {
            m[str] = v.size();
            v.push_back(str);
        }
        return m[str];
    }
    string get(int i)
    {
        return v[i];
    }
    vector<int> get(const vector<string> &strs)
    {
        vector<int> ret;
        ret.reserve(strs.size() + 2);
        for (int i = 0; i < strs.size(); i++)
            ret.push_back(get(strs[i]));
        return ret;
    }
    vector<string> get(const vector<int> &is)
    {
        vector<string> ret;
        ret.reserve(is.size() + 2);
        for (int i = 0; i < is.size(); i++)
            ret.push_back(get(is[i]));
        return ret;
    }
};
struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator-(point p)
    {
        return point(x - p.x, y - p.y);
    }
    double operator*(point p)
    {
        return x * p.y - y * p.x;
    }
    double dist(point p)
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};
class Warehouse
{
public:
    int n;

    vector<int> xx, yy;
    double len(point a, point b, point c)
    {
        return ((c - a) * (c - b)) / a.dist(b);
    }
    int calc(point a, point b)
    {
        vector<double> ret;
        for (int i = 0; i < n; ++i)
        {
            ret.push_back(len(a, b, point(xx[i], yy[i])));
        }
        sort(ret.begin(), ret.end());
        double m1 = len(a, b, point(0, 0));
        double m2 = len(a, b, point(200, 0));
        double m3 = len(a, b, point(0, 200));
        double m4 = len(a, b, point(200, 200));
        double lower, upper;
        if (max(m1, m2) > max(m3, m4))
        {
            upper = min(m1, m2);
            lower = max(m3, m4);
        }
        else
        {
            upper = min(m3, m4);
            lower = max(m1, m2);
        }
        int tt = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            double from = ret[i], to = ret[i + 1];
            if (from < lower - 1e-8)
                continue;
            if (to > upper + 1e-8)
                continue;
            int t = (int)floor(to - from - 1e-8);
            if (t > tt)
                tt = t;
        }
        return tt;
    }
    int feetWide(vector<int> x, vector<int> y)
    {
        x.push_back(0), y.push_back(0);
        x.push_back(0), y.push_back(200);
        x.push_back(200), y.push_back(0);
        x.push_back(200), y.push_back(200);
        n = x.size();
        xx = x, yy = y;
        int ret = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (x[i] != x[j])
                {
                    int t = calc(point(x[i], y[i]), point(x[j], y[j]));
                    if (t > ret)
                        ret = t;
                }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (y[i] != y[j])
                {
                    point a(x[i], y[i]);
                    point b(x[j], y[j]);
                    point c = a;
                    c.x += b.y - a.y;
                    c.y += a.x - b.x;
                    int t = calc(a, c);
                    if (t > ret)
                        ret = t;
                }
        return ret;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        x.push_back(curr);
    }

    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        y.push_back(curr);
    }
    Warehouse w;
    cout << w.feetWide(x, y) << endl;
    return 0;
}