/* Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.
Input format :
Line 1 : Integer N (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer x
Output format :
Line 1 : Triplet 1 elements (separated by space)
Line 2 : Triplet 3 elements (separated by space)
Line 3 : and so on
Constraints :
1 <= N <= 1000
1 <= x <= 100
Sample Input:
7
1 2 3 4 5 6 7 
12
Sample Output ;
1 4 7
1 5 6
2 3 7
2 4 6
3 4 5 */
/* Time Complexity : O(n^2) 
Space Complexity : O(n) 
where n is size of Array/List 
*/ 
#include<bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int startIndex, int endIndex, int num) 
{ 
    int numPair = 0; 
    while (startIndex < endIndex) 
    { 
        if (arr[startIndex] + arr[endIndex] < num) 
        { 
            startIndex++; 
            
        } 
        else if (arr[startIndex] + arr[endIndex] > num) 
        { 
            endIndex--; 
            
        } 
        else 
        { 
            int elementAtStart = arr[startIndex];
            int elementAtEnd = arr[endIndex]; 
            if (elementAtStart == elementAtEnd) 
            { 
                int totalElementsFromStartToEnd = (endIndex - startIndex) + 1; 
                numPair += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1) / 2); 
                return numPair; 
                
            }
            int tempStartIndex = startIndex + 1; 
            int tempEndIndex = endIndex - 1; 
            while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart) 
            { 
                tempStartIndex += 1; 
                
            } 
            while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == elementAtEnd) 
            { 
                tempEndIndex -= 1; 
            } 
            int totalElementsFromStart = (tempStartIndex - startIndex); 
            int totalElementsFromEnd = (endIndex - tempEndIndex); 
            numPair += (totalElementsFromStart * totalElementsFromEnd); 
            startIndex = tempStartIndex; endIndex = tempEndIndex; 
        }
    } 
    return numPair; 
} 
int tripletSum(int *arr, int n, int num) 
{ 
    sort(arr, arr + n); 
    int numTriplets = 0; 
    for (int i = 0; i < n; i++) 
    {
        int pairSumFor = num - arr[i]; 
        int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor); 
        numTriplets += numPairs;
    }
    return numTriplets;
}