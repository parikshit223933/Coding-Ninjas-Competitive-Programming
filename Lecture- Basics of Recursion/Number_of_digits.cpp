/* Given the code to find out and return the number of digits present in a number recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass.
Input Format :
Integer n
Output Format :
Count of digits
Constraints :
1 <= n <= 10^6
Sample Input :
 156
Sample Output :
3 */
int count(int n){
    if(n>=0&&n<10){
        return 1;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}