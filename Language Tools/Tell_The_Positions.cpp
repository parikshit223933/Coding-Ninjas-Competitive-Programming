/* In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.
Input Format:
First line will have a single integer ‘n’, denoting the number of students in the class.
Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.
Output Format:
Print ‘n’ lines having two values: First, the position of student in the class and second his name.
Constraints:
1 <= n <= 10^5
0 <= m1, m2, m3 <= 100
Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99
Sample Output:
1 Shubham
2 Mohit
3 Rishabh */
#include<bits/stdc++.h>
using namespace std;
struct pairs
{
    int roll;
	string name;
	int marks;
};
bool arranger(pairs p1, pairs p2)
{
    if(p1.marks>p2.marks)
    {
        return 1;
    }
    else if(p2.marks>p1.marks)
    {
        return 0;
    }
    else if(p2.marks==p1.marks)
    {
        if(p1.roll<p2.roll)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
	int n;
	cin>>n;
	pairs *arr=new pairs[n];
    int roll=1;
	for(int i=0; i<n; i++)
	{
		string name;
		cin>>name;
		int m1, m2, m3;
		cin>>m1>>m2>>m3;
		int total_marks=m1+m2+m3;
		arr[i]={roll, name, total_marks};
        roll+=1;
	}
	sort(arr, arr+n, arranger);
	int count=1;
	for(int i=0; i<n; i++)
	{
		cout<<count<<" "<< arr[i].name<<endl;
        count+=1;
	}
}