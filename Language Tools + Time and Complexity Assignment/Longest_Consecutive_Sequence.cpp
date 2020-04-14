/* You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16 */

#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    vector<pair<int, int> >pairs_vector;
	//in this vector first element of each pair is the start and second element is the max_length.
	map<int, bool>m;
	for (int i = 0; i < n; i++)
	{
		m[arr[i]] = true;
	}
	int max_length = 0;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		int current_length = 1;
		int current_start = 0;
		if (m[arr[i]] = true)
		{
			m[arr[i]] = false;
			//forward propagation from arr[i]
			int element_at_position = arr[i];
			while (m[element_at_position + 1] == true)
			{
				current_length += 1;
				m[element_at_position + 1] = false;
				element_at_position++;
			}
			//backward propagation from arr[i]
			element_at_position = arr[i];
			current_start = element_at_position;
			while (m[element_at_position - 1] == true)
			{
				m[element_at_position - 1] = false;
				current_start--;
				current_length++;
				element_at_position--;
			}
		}
		if (current_length >= max_length)
		{
			max_length = current_length;
			start = current_start;
			pair<int, int>p;
			p.first = start;
			p.second = max_length;
			pairs_vector.push_back(p);
			//in this vector first element of each pair is the START and second element is the MAX_LENGTH.
		}
	}
	if (max_length == 1 && start == arr[n - 1])
	{
		vector<int>temp;
		temp.push_back(arr[0]);
		return temp;
	}
	for (int i = 0; i < n; i++)
	{
		int starting_element = arr[i];
		for (int j = 0; j < pairs_vector.size(); j++)
		{
			if (starting_element == pairs_vector[j].first && max_length == pairs_vector[j].second)
			{
				vector<int>temp;
				for (int k = starting_element; k < starting_element + max_length; k++)
				{
					temp.push_back(k);
				}
				return temp;
			}
		}
	}
}