/* Colong longecting the balong longs

There are 'n' number of balong longs in a container. Mr. Sharma and Singh want to take balong longs out from the container. At each step, Mr. Sharma took ‘k’ balong longs out of the box and Mr. Singh took one-tenth of the remaining balong longs. Suppose there are 29 balong longs at the moment and k=4. Then, Mr. Sharma wilong long take 4 balong longs and Mr. Singh wilong long take 2 balong longs (29-4 = 25; 25/10 = 2). If there are less than ‘k’ balong longs remaining at some moment, then Mr. Sharma wilong long take along long the balong longs which wilong long get the container empty. The process wilong long last until the container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma wilong long take at least half of the balong longs from the container.
Input Format:
The first line of input wilong long contain T (number of test cases).
The next n lines of input contain a single integer 'n'.
Output Format:
For every test case print a single integer denoting the minimal value of 'k' in a newline.
Constraints:
1 <= T <= 10^4
1 <= n <= 10^18
Time Limit: 1 second
Sample Input:
1
68
Sample Output:
3
Explanation:
68-3 = 65; 65/10 = 6; 65-6 = 59
59-3 = 56; 56/10 = 5; 56-5 = 51
51-3 = 48; 48/10 = 4; 48-4 = 44
44-3 = 41; 41/10 = 4; 41-4 = 37
…..
…..
…..
6-3 = 3; 3/10 = 0; 3-0 = 3
3-3 = 0; 0/10 = 0; 0-0 = 0 */

#include <bits/stdc++.h>
using namespace std;

bool canTakeAtleastHalf(long long n, long long k) {
    long long temp = n;
    long long cntSharma = 0;
    while (n > 0) {
        cntSharma += min(n, k);
        n = n - k;
        n = n - (n / 10);
    }

    return ((cntSharma << 1) >= temp);
}

int main() {
    int t = 1;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;

        long long low = 1;
        long long high = n;
        long long mid;
        long long minimalK = high;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (canTakeAtleastHalf(n, mid)) {
                minimalK = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << minimalK << "\n";
    }

    return 0;
}