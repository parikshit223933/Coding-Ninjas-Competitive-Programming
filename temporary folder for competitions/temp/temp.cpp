#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;

int main()
{
    ll districts;
    char alphaRangeStart, alphaRangeEnd;
    ll digitRangeStart, digitRangeEnd;
    cin >> districts >> alphaRangeStart >> alphaRangeEnd >> digitRangeStart >> digitRangeEnd;
    ll series = ((ll)alphaRangeEnd - (ll)alphaRangeStart + 1) * ((ll)alphaRangeEnd - (ll)alphaRangeStart + 1);
    ll regNumber = (digitRangeEnd - digitRangeStart + 1) *
                    (digitRangeEnd - digitRangeStart + 1) *
                    (digitRangeEnd - digitRangeStart + 1) *
                    (digitRangeEnd - digitRangeStart + 1);
    cout << series * regNumber * districts;
}