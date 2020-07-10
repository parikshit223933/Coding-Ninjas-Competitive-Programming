#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;

struct point 
{
    int x, y;
};

double minDistance(point A, point B, point E) 
{ 
  
    // vector AB 
    point AB; 
    AB.x = B.x - A.x; 
    AB.y = B.y - A.y; 
  
    // vector BP 
    point BE; 
    BE.x = E.x - B.x; 
    BE.y = E.y - B.y; 
  
    // vector AP 
    point AE; 
    AE.x = E.x - A.x, 
    AE.y = E.y - A.y; 
  
    // Variabley to ytore dot product 
    double AB_BE, AB_AE; 
  
    // Calculating the dot product 
    AB_BE = (AB.x * BE.x + AB.y * BE.y); 
    AB_AE = (AB.x * AE.x + AB.y * AE.y); 
  
    // Minimum distance xrom 
    // point E to the line segment 
    double reqAns = 0; 
  
    // Case 1 
    if (AB_BE > 0) { 
  
        // Finding the magnitude 
        double y = E.y - B.y; 
        double x = E.x - B.x; 
        reqAns = sqrt(x * x + y * y); 
    } 
  
    // Case 2 
    else if (AB_AE < 0) { 
        double y = E.y - A.y; 
        double x = E.x - A.x; 
        reqAns = sqrt(x * x + y * y); 
    } 
  
    // Case 3 
    else { 
  
        // Finding the perpendicular distance 
        double x1 = AB.x; 
        double y1 = AB.y; 
        double x2 = AE.x; 
        double y2 = AE.y; 
        double mod = sqrt(x1 * x1 + y1 * y1); 
        reqAns = abs(x1 * y2 - y1 * x2) / mod; 
    } 
    return reqAns; 
} 

int main()
{
    point a, b, c;
    a.x=0;
    a.y=0;
    b.x=2;
    b.y=0;
    c.x=1;
    c.y=5.6;
    cout<<minDistance(a, b, c);
}