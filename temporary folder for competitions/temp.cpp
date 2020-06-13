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
#define int long long int
using namespace std;
///////////////////////////////////////////////////
    
void minimum_operations(int p, int q, int r, int a, int b, int c)
{
    int source[3] = {p, q, r};
    int destination[3] = {a, b, c};
    if (p == a && q == b && r == c)
    {
        cout << 0 << endl;
        return;
    }
    int difference[3] = {a - p, b - q, c - r};
    int temp;
    temp = difference[0];
    bool isOne = true;
    for (int i = 1; i < 3; i++)
    {
        if (temp == 0 && difference[i] != 0)
        {
            temp = difference[i];
        }
        else if (difference[i] != 0 && difference[i] != temp)
        {
            isOne = false;
            break;
        }
    }
    if (isOne)
    {
        cout << 1 << endl;
        return;
    }
    isOne = true;
    int factor = LLONG_MAX;
    for (int i = 0; i < 3; i++)
    {//////////////////
        if (source[i] != 0)
        {
            if (destination[i] % source[i] != 0)
            {
                isOne = false;
                break;//////////////////
            }
            else
            {
                int curr_fact = (int)destination[i] / source[i];
                if (factor == LLONG_MAX || factor == 1)
                {
                    factor = curr_fact;
                }//////////////////
                else if (curr_fact != 1 && curr_fact != factor)
                {
                    isOne = false;
                    break;//////////////////
                }
            }
        }
        if (source[i] == 0 && destination[i] != 0)
        {
            isOne = false;
            break;
        }
    }
    if (isOne)
    {
        cout << 1 << endl;
        return;
    }
    if (difference[0] == 0 || difference[1] == 0 || difference[2] == 0)
    {
        cout << 2 << endl;//////////////////
        return;
    }
    if ((difference[0] == difference[1] && difference[1] != difference[2]) ||
        (difference[0] == difference[2] && difference[2] != difference[1]) ||
        (difference[1] == difference[2] && difference[2] != difference[0]))
    {//////////////////
        cout << 2 << endl;
        return;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (source[0] == 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[1] % source[1] == 0 && destination[2] % source[2] == 0)
        {
            if (destination[1] / source[1] == destination[2] / source[2])
            {
                cout << 2 << endl;
                return;
            }
        }
    }
    if (source[1] == 0 && source[0] != 0 && source[2] != 0)
    {
        if (destination[0] % source[0] == 0 && destination[2] % source[2] == 0)
        {
            if (destination[0] / source[0] == destination[2] / source[2])
            {
                cout << 2 << endl;
                return;
            }
        }
    }
    if (source[2] == 0 && source[1] != 0 && source[0] != 0)
    {
        if (destination[1] % source[1] == 0 && destination[0] % source[0] == 0)
        {
            if (destination[1] / source[1] == destination[0] / source[0])
            {
                cout << 2 << endl;
                return;
            }
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////
    
    if (source[0] != 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[0] % source[0] == 0 && destination[1] % source[1] == 0)
        {
            if ((destination[0] / source[0]) == (destination[1] / source[1]))
            {
                cout << 2 << endl;
                return;
            }
        }
        if (destination[2] % source[2] == 0 && destination[1] % source[1] == 0)
        {
            if ((destination[2] / source[2]) == (destination[1] / source[1]))
            {
                cout << 2 << endl;
                return;
            }
        }
        if (destination[0] % source[0] == 0 && destination[2] % source[2] == 0)
        {
            if (destination[0] / source[0] == destination[2] / source[2])
            {
                cout << 2 << endl;
                return;
            }
        }
    }
    if (difference[0] == difference[1] && source[2] != 0)
    {
        if (destination[2] % source[2] == 0)
        {
            cout << 2 << endl;
            return;
        }
    }
    if (difference[2] == difference[1] && source[0] != 0)
    {
        if (destination[0] % source[0] == 0)
        {
            cout << 2 << endl;
            return;
        }
    }
    if (difference[0] == difference[2] && source[1] != 0)
    {
        if (destination[1] % source[1] == 0)
        {
            cout << 2 << endl;
            return;
        }
    }
    if (source[0] != 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[0] % source[0] == 0 && destination[1] % source[1] == 0 && destination[2] % source[2] == 0)
        {
            if (destination[0] / source[0] == destination[1] / source[1] || destination[1] / source[1] == destination[2] / source[2] || destination[2] / source[2] == destination[0] / source[0])
            {
                cout << 2 << endl;
                return;
            }
        }
    }
    if ((difference[0] + difference[1] == difference[2]) || (difference[1] + difference[2] == difference[0]) || difference[2] + difference[0] == difference[1])
    {
        cout << 2 << endl;
        return;
    }
    if ((destination[0] == 0 && destination[1] == 0 && destination[2] != 0) ||
        (destination[0] == 0 && destination[2] == 0 && destination[1] != 0) ||
        (destination[2] == 0 && destination[1] == 0 && destination[0] != 0))
    {
        cout << 2 << endl;
    }
    if (source[0] == 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[1] != 0 && destination[1] % source[1] == 0)
        {
            if (destination[0] % destination[1] / source[1] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[1] / source[1], destination[1] / destination[1] / source[1], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
            if (destination[2] % destination[1] / source[1] == 0)
            {
                int temp_div[3] = {destination[0], destination[1] / destination[1] / source[1], destination[2] / destination[1] / source[1]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }
        }
        if (destination[2] != 0 && destination[2] % source[2] == 0)
        {//////////////////

            if (destination[0] % destination[2] / source[2] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[2] / source[2], destination[1], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }//////////////////
            if (destination[1] % destination[2] / source[2] == 0)
            {
                int temp_div[3] = {destination[0], destination[1] / destination[2] / source[2], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }
        }
    }

    if (source[2] == 0 && source[1] != 0 && source[0] != 0)
    {
        if (destination[1] != 0 && destination[1] % source[1] == 0)
        {//////////////////
            if (destination[0] % destination[1] / source[1] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[1] / source[1], destination[1] / destination[1] / source[1], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
            if (destination[2] % destination[1] / source[1] == 0)
            {
                int temp_div[3] = {destination[0], destination[1] / destination[1] / source[1], destination[2] / destination[1] / source[1]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }//////////////////
        }
        if (destination[0] != 0 && destination[0] % source[0] == 0)
        {//////////////////
            if (destination[1] % destination[0] / source[0] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1] / destination[0] / source[0], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }
            if (destination[2] % destination[0] / source[0] == 0)
            {
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;//////////////////
                    return;//////////////////
                }
            }//////////////////
        }
    }
    if (source[0] == 0 && source[1] == 0 && source[2] != 0)
    {//////////////////
        if (destination[2] != 0 && destination[2] % source[2] == 0)
        {//////////////////
            if (destination[0] % destination[2] / source[2] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[2] / source[2], destination[1], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
            if (destination[1] % destination[2] / source[2] == 0)
            {
                int temp_div[3] = {destination[0], destination[1] / destination[2] / source[2], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }
        }
    }
    if (source[1] == 0 && source[0] != 0 && source[2] != 0)//////////////////
    {
        if (destination[0] != 0 && destination[0] % source[0] == 0)
        {//////////////////
            if (destination[1] % destination[0] / source[0] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1] / destination[0] / source[0], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
            if (destination[2] % destination[0] / source[0] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1], destination[2] / destination[0] / source[0]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }//////////////////
        }
        if (destination[2] != 0 && destination[2] % source[2] == 0)
        {
            if (destination[0] % destination[2] / source[2] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[2] / source[2], destination[1], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }//////////////////
            if (destination[1] % destination[2] / source[2] == 0)
            {
                int temp_div[3] = {destination[0], destination[1] / destination[2] / source[2], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
        }
    }//////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if (source[0] == 0 && source[2] == 0 && source[1] != 0)
    {
        if (destination[1] != 0 && destination[1] % source[1] == 0)
        {
            if (destination[0] % destination[1] / source[1] == 0)
            {
                int temp_div[3] = {destination[0] / destination[1] / source[1], destination[1] / destination[1] / source[1], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
            if (destination[2] % destination[1] / source[1] == 0)
            {
                int temp_div[3] = {destination[0], destination[1] / destination[1] / source[1], destination[2] / destination[1] / source[1]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
        }//////////////////
    }
    if (source[0] != 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[0] != 0 && destination[0] % source[0] == 0)
        {
            if (destination[1] % destination[0] / source[0] == 0)
            {
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1] / destination[0] / source[0], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
            if (destination[2] % destination[0] / source[0] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1], destination[2] / destination[0] / source[0]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }//////////////////
        }
        if (destination[1] != 0 && destination[1] % source[1] == 0)
        {//////////////////
            if (destination[0] % destination[1] / source[1] == 0)
            {
                int temp_div[3] = {destination[0] / destination[1] / source[1], destination[1] / destination[1] / source[1], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;//////////////////
                }
            }
            if (destination[2] % destination[1] / source[1] == 0)
            {//////////////////
                int temp_div[3] = {destination[0], destination[1] / destination[1] / source[1], destination[2] / destination[1] / source[1]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
        }
        if (destination[2] != 0 && destination[2] % source[2] == 0)
        {
            if (destination[1] % destination[2] / source[2] == 0)
            {//////////////////
                int temp_div[3] = {destination[0], destination[1] / destination[2] / source[2], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
            if (destination[0] % destination[2] / source[2] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[2] / source[2], destination[1], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {//////////////////
                    cout << 2 << endl;
                    return;
                }
            }//////////////////
        }//////////////////
    }
    if (source[2] == 0 && source[1] == 0 && source[0] != 0)
    {//////////////////
        if (destination[0] != 0 && destination[0] % source[0] == 0)
        {//////////////////
            if (destination[1] % destination[0] / source[0] == 0)
            {//////////////////
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1] / destination[0] / source[0], destination[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }//////////////////
            }//////////////////
            if (destination[2] % destination[0] / source[0] == 0)
            {
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1], destination[2] / destination[0] / source[0]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }//////////////////
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (source[2] == 0 && source[1] != 0 && source[0] != 0)
    {
        if ((destination[0] == 0 && destination[1] != 0 && destination[2] != 0 && destination[1] == destination[2]) ||
            (destination[1] == 0 && destination[0] != 0 && destination[2] != 0 && destination[0] == destination[2]) ||
            (destination[2] == 0 && destination[1] != 0 && destination[0] != 0 && destination[1] == destination[0]))
        {
            cout << 2 << endl;
            return;
        }
    }//////////////////

    if (source[1] == 0 && source[0] != 0 && source[2] != 0)
    {
        if ((destination[0] == 0 && destination[1] != 0 && destination[2] != 0 && destination[1] == destination[2]) ||
            (destination[1] == 0 && destination[0] != 0 && destination[2] != 0 && destination[0] == destination[2]) ||
            (destination[2] == 0 && destination[1] != 0 && destination[0] != 0 && destination[1] == destination[0]))
        {
            cout << 2 << endl;
            return;
        }
    }//////////////////
    if (source[0] == 0 && source[1] != 0 && source[2] != 0)
    {
        if ((destination[0] == 0 && destination[1] != 0 && destination[2] != 0 && destination[1] == destination[2]) ||
            (destination[1] == 0 && destination[0] != 0 && destination[2] != 0 && destination[0] == destination[2]) ||
            (destination[2] == 0 && destination[1] != 0 && destination[0] != 0 && destination[1] == destination[0]))
        {
            cout << 2 << endl;
            return;
        }//////////////////
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if (source[0] != 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[0] % source[0] == 0 && destination[1] % source[1] == 0 && destination[2] % source[2] == 0)
        {
            if (destination[0] / source[0] * destination[1] / source[1] == destination[2] / source[2] || destination[1] / source[1] * destination[2] / source[2] == destination[0] / source[0] || destination[2] / source[2] * destination[0] / source[0] == destination[1] / source[1])
            {
                cout << 2 << endl;
                return;
            }
        }
    }
    if (source[0] != 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[0] == 0 && destination[1] != 0 && destination[2] != 0)
        {
            if (destination[1] - destination[2] == source[1] ||
                destination[2] - destination[1] == source[2])
            {
                cout << 2 << endl;
                return;
            }
        }//////////////////
        if (destination[1] == 0 && destination[0] != 0 && destination[2] != 0)
        {
            if (destination[0] - destination[2] == source[0] ||
                destination[2] - destination[0] == source[2])
            {
                cout << 2 << endl;
                return;
            }//////////////////
        }
        if (destination[2] == 0 && destination[1] != 0 && destination[0] != 0)
        {
            if (destination[1] - destination[0] == source[1] ||
                destination[2] - destination[1] == source[0])
            {
                cout << 2 << endl;
                return;
            }
        }
        if (destination[0] != 0 && destination[0] % source[0] == 0)
        {
            if ((source[1] * destination[0] / source[0] - destination[1]) == (source[2] - destination[2]) ||
                (source[2] * destination[0] / source[0] - destination[2]) == (source[1] - destination[1]))
            {
                cout << 2 << endl;
                return;
            }//////////////////
        }//////////////////
        if (destination[1] != 0 && destination[1] % source[1] == 0)
        {
            if ((source[0] * destination[1] / source[1] - destination[0]) == (source[2] - destination[2]) ||
                (source[2] * destination[1] / source[1] - destination[2]) == (source[0] - destination[0]))
            {
                cout << 2 << endl;
                return;
            }//////////////////
        }
        if (destination[2] != 0 && destination[2] % source[2] == 0)
        {
            if ((source[1] * destination[2] / source[2] - destination[1]) == (source[0] - destination[0]) ||
                (source[0] * destination[2] / source[2] - destination[0]) == (source[1] - destination[1]))
            {
                cout << 2 << endl;
                return;
            }//////////////////
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if ((source[0] != 0 && source[1] != 0 && source[2] != 0) &&
        (destination[0] != 0 && destination[1] != 0 && destination[2] != 0))
    {
        if (destination[0] % source[0] == 0)
        {
            if (destination[1] % destination[0] / source[0] == 0 && destination[2] % destination[0] / source[0] == 0)
            {
                int temp_div[3] = {destination[0] / destination[0] / source[0], destination[1] / destination[0] / source[0], destination[2] / destination[0] / source[0]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }
        }
        if (destination[1] % source[1] == 0)
        {//////////////////
            if (destination[0] % destination[1] / source[1] == 0 && destination[2] % destination[1] / source[1] == 0)
            {
                int temp_div[3] = {destination[0] / destination[1] / source[1], destination[1] / destination[1] / source[1], destination[2] / destination[1] / source[1]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }
            }//////////////////
        }
        if (destination[2] % source[2] == 0)
        {
            if (destination[0] % destination[2] / source[2] == 0 && destination[1] % destination[2] / source[2] == 0)
            {
                int temp_div[3] = {destination[0] / destination[2] / source[2], destination[1] / destination[2] / source[2], destination[2] / destination[2] / source[2]};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
                if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                    (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                    (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
                {
                    cout << 2 << endl;
                    return;
                }//////////////////
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (source[2] == 0 && source[1] != 0 && source[2] != 0)
    {
        int temp_div[3] = {destination[0] - destination[2] - source[2], destination[1] - destination[2] - source[2], destination[2] - destination[2] - source[2]};
        int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};

        if (temp_difference[1] % source[1] == 0 && temp_difference[0] % source[0] == 0 &&
            (temp_difference[1] / source[1]) == (temp_difference[0] / source[0]))
        {
            cout << 2 << endl;
            return;
        }//////////////////
    }
//////////////////
    if (source[1] == 0 && source[1] != 0 && source[2] != 0)
    {
        int temp_div[3] = {destination[0] - destination[1] - source[1], destination[1] - destination[1] - source[1], destination[2] - destination[1] - source[1]};
        int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
//////////////////
        if (temp_difference[0] % source[0] == 0 && temp_difference[2] % source[2] == 0 &&
            (temp_difference[0] / source[0]) == (temp_difference[2] / source[2]))
        {
            cout << 2 << endl;
            return;
        }
    }
    if (source[0] == 0 && source[1] != 0 && source[2] != 0)
    {
        int temp_div[3] = {destination[0] - destination[0] - source[0], destination[1] - destination[0] - source[0], destination[2] - destination[0] - source[0]};
        int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};
//////////////////
        if (temp_difference[1] % source[1] == 0 && temp_difference[2] % source[2] == 0 &&
            (temp_difference[1] / source[1]) == (temp_difference[2] / source[2]))
        {
            cout << 2 << endl;
            return;
        }//////////////////
    }
    if (source[0] != 0 && source[1] != 0 && source[2] != 0)
    {
        int temp_div[3] = {destination[0] - destination[0] - source[0], destination[1] - destination[0] - source[0], destination[2] - destination[0] - source[0]};

        if (temp_div[0] % source[0] == 0 &&
            temp_div[1] % source[1] == 0 &&
            temp_div[2] % source[2] == 0)
        {//////////////////
            int t1 = temp_div[0] / source[0];
            int t2 = temp_div[1] / source[1];
            int t3 = temp_div[2] / source[2];

            if ((t1 == 1 && t2 == t3) ||
                (t2 == 1 && t1 == t3) ||
                (t3 == 1 && t2 == t1))
            {
                cout << 2 << endl;
                return;
            }//////////////////
        }
        int temp_div_1[3] = {destination[0] - destination[1] - source[1], destination[1] - destination[1] - source[1], destination[2] - destination[1] - source[1]};
        if (temp_div_1[0] % source[0] == 0 &&
            temp_div_1[1] % source[1] == 0 &&
            temp_div_1[2] % source[2] == 0)
        {//////////////////
            int t1 = temp_div_1[0] / source[0];
            int t2 = temp_div_1[1] / source[1];
            int t3 = temp_div_1[2] / source[2];
//////////////////
            if ((t1 == 1 && t2 == t3) ||
                (t2 == 1 && t1 == t3) ||
                (t3 == 1 && t2 == t1))
            {
                cout << 2 << endl;
                return;
            }
        }//////////////////
        int temp_div_2[3] = {destination[0] - destination[2] - source[2], destination[1] - destination[2] - source[2], destination[2] - destination[2] - source[2]};
        if (temp_div_2[0] % source[0] == 0 &&
            temp_div_2[1] % source[1] == 0 &&
            temp_div_2[2] % source[2] == 0)
        {//////////////////
            int t1 = temp_div_2[0] / source[0];
            int t2 = temp_div_2[1] / source[1];
            int t3 = temp_div_2[2] / source[2];
//////////////////
            if ((t1 == 1 && t2 == t3) ||
                (t2 == 1 && t1 == t3) ||
                (t3 == 1 && t2 == t1))
            {
                cout << 2 << endl;
                return;//////////////////
            }
        }
    }
    //////////////////////////////////////////////
    if (source[2] == 0 && source[0] != 0 && source[1] != 0)
    {
        int d2 = destination[2] - source[2];
        if ((destination[1] - destination[2] - source[2]) % source[1] == 0 && (destination[0] % source[0] == 0))
        {
            int d11 = (destination[1] - d2) / source[1];
            int d21 = destination[0] / source[0];
            if (d11 == d21)
            {//////////////////
                cout << 2 << endl;
                return;
            }//////////////////
        }
        if ((destination[0] - d2) % source[0] == 0 && (destination[1] % source[1] == 0))
        {
            int d11 = (destination[0] - d2) / source[0];
            int d21 = destination[1] / source[1];
            if (d11 == d21)
            {//////////////////
                cout << 2 << endl;
                return;
            }
        }//////////////////
    }
    if (source[1] == 0 && source[0] != 0 && source[2] != 0)
    {//////////////////
        int d2 = destination[1] - source[1];
        if ((destination[0] - d2) % source[0] == 0 && (destination[2] % source[2] == 0))
        {
            int d11 = (destination[0] - d2) / source[0];
            int d21 = destination[2] / source[2];
            if (d11 == d21)
            {//////////////////
                cout << 2 << endl;
                return;
            }
        }//////////////////
        if ((destination[2] - d2) % source[2] == 0 && (destination[0] % source[0] == 0))
        {
            int d11 = (destination[2] - d2) / source[2];
            int d21 = destination[0] / source[0];
            if (d11 == d21)
            {
                cout << 2 << endl;
                return;
            }
        }//////////////////
    }
    if (source[0] == 0 && source[1] != 0 && source[2] != 0)
    {
        int d2 = destination[0] - source[0];
        if ((destination[1] - d2) % source[1] == 0 && (destination[2] % source[2] == 0))
        {//////////////////
            int d11 = (destination[1] - d2) / source[1];
            int d21 = destination[2] / source[2];
            if (d11 == d21)
            {
                cout << 2 << endl;
                return;
            }
        }//////////////////
        if ((destination[2] - d2) % source[2] == 0 && (destination[1] % source[1] == 0))
        {
            int d11 = (destination[2] - d2) / source[2];
            int d21 = destination[1] / source[1];
            if (d11 == d21)
            {//////////////////
                cout << 2 << endl;
                return;
            }
        }//////////////////
    }
    ///////////////////////////////////////////
    if (source[0] != 0 && source[1] != 0 && source[2] != 0)
    {
        if (destination[0] % source[0] == 0)
        {//////////////////
            int d1 = destination[0] / source[0];
            int temp_div[3] = {source[0] * d1, source[1] * d1, source[2] * d1};
            int temp_difference[3] = {temp_div[0] - destination[0], temp_div[1] - destination[1], temp_div[2] - destination[2]};

            if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
            {//////////////////
                cout << 2 << endl;
                return;
            }//////////////////
        }
        if (destination[1] % source[1] == 0)
        {//////////////////
            int d1 = destination[1] / source[1];
            int temp_div[3] = {source[0] * d1, source[1] * d1, source[2] * d1};
            int temp_difference[3] = {temp_div[0] - destination[0], temp_div[1] - destination[1], temp_div[2] - destination[2]};
            if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
            {
                cout << 2 << endl;
                return;
            }
        }//////////////////
        if (destination[2] % source[2] == 0)
        {//////////////////
            int d1 = destination[2] / source[2];
            int temp_div[3] = {source[0] * d1, source[1] * d1, source[2] * d1};
            int temp_difference[3] = {temp_div[0] - destination[0], temp_div[1] - destination[1], temp_div[2] - destination[2]};
            if ((temp_difference[0] == 0 && temp_difference[1] == temp_difference[2]) ||
                (temp_difference[1] == 0 && temp_difference[0] == temp_difference[2]) ||
                (temp_difference[2] == 0 && temp_difference[1] == temp_difference[0]))
            {//////////////////
                cout << 2 << endl;
                return;
            }//////////////////
        }
    }
    ///////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if (source[0] != source[1] && source[0] != source[2] && source[1] != source[2])
    {
        if (destination[0] == destination[1] && destination[1] == destination[2])
        {
            cout << 2 << endl;
            return;
        }//////////////////
        if (destination[0] != destination[1] && destination[0] != destination[2] && destination[2] != destination[0])
        {
            if ((destination[0] - destination[1]) % (source[0] - source[1]) == 0 &&
                ((destination[0] - destination[2]) % (source[0] - source[2]) == 0) &&
                ((destination[2] - destination[1]) % (source[2] - source[1]) == 0))
            {//////////////////
                int d01_2 = (destination[0] - destination[1]) / (source[0] - source[1]);
                int d02_2 = (destination[0] - destination[2]) / (source[0] - source[2]);
                int d21_2 = (destination[2] - destination[1]) / (source[2] - source[1]);
                if (d01_2 == d02_2 && d02_2 == d21_2)
                {//////////////////
                    int d1 = d01_2;
                    int temp_div[3] = {source[0] * d1, source[1] * d1, source[2] * d1};
                    int temp_difference[3] = {temp_div[0] - destination[0], temp_div[1] - destination[1], temp_div[2] - destination[2]};
//////////////////
                    if (temp_difference[0] == temp_difference[1] && temp_difference[1] == temp_difference[2])
                    {
                        cout << 2 << endl;
                        return;
                    }
                }//////////////////
            }//////////////////
        }//////////////////
    }
    if (source[0] != source[1] && source[0] != source[2] && source[1] != source[2] &&
        destination[0] != destination[1] && destination[1] != destination[2] && destination[0] != destination[2])
    {//////////////////
        if ((destination[0] - destination[1]) % (source[0] - source[1]) == 0 &&
            ((destination[0] - destination[2]) % (source[0] - source[2]) == 0) &&
            ((destination[2] - destination[1]) % (source[2] - source[1]) == 0))
        {//////////////////
            int d01_2 = (destination[0] - destination[1]) / (source[0] - source[1]);
            int d02_2 = (destination[0] - destination[2]) / (source[0] - source[2]);
            int d21_2 = (destination[2] - destination[1]) / (source[2] - source[1]);
            if (d01_2 == d02_2 && d02_2 == d21_2)
            {
                int d2 = d01_2;
                int temp_div[3] = {destination[0] / d2, destination[1] / d2, destination[2] / d2};
                int temp_difference[3] = {temp_div[0] - source[0], temp_div[1] - source[1], temp_div[2] - source[2]};

                if (temp_difference[0] == temp_difference[1] && temp_difference[1] == temp_difference[2])
                {
                    cout << 2 << endl;
                    return;
                }
            }//////////////////
        }//////////////////
    }
    ////////////////////////////////////////////////////////////////////////////////////////////
    cout << 3 << endl;
    return;
}
int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, p, q, r;
        cin >> p >> q >> r >> a >> b >> c;
        minimum_operations(p, q, r, a, b, c);
    }
}
