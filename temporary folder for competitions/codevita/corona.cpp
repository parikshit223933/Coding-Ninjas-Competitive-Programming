#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
#define uint unsigned long long int
using namespace std;

void solve(int *arr, int n)
{
    unordered_map<int, string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";
    m[10] = "ten";
    m[11] = "eleven";
    m[12] = "twelve";
    m[13] = "thirteen";
    m[14] = "fourteen";
    m[15] = "fifteen";
    m[16] = "sixteen";
    m[17] = "seventeen";
    m[18] = "eighteen";
    m[19] = "nineteen";
    m[20] = "twenty";
    m[21] = "twenty-one ";
    m[22] = "twenty-two";
    m[23] = "twenty-three ";
    m[24] = "twenty-four ";
    m[25] = "twenty-five";
    m[26] = "twenty-six";
    m[27] = "twenty-seven";
    m[28] = "twenty-eight";
    m[29] = "twenty-nine";
    m[30] = "thirty";
    m[31] = "thirtyone";
    m[32] = "thirtytwo";
    m[33] = "thirtythree";
    m[34] = "thirtyfour";
    m[35] = "thirtyfive";
    m[36] = "thirtysix";
    m[37] = "thirtyseven";
    m[38] = "thirtyeight";
    m[39] = "thirtynine";
    m[40] = "forty";
    m[41] = "fortyone";
    m[42] = "fortytwo";
    m[43] = "fortythree";
    m[44] = "fortyfour";
    m[45] = "fortyfive";
    m[46] = "fortysix";
    m[47] = "fortyseven";
    m[48] = "fortyeight";
    m[49] = "fortynine";
    m[50] = "fifty";
    m[51] = "fiftyone";
    m[52] = "fiftytwo";
    m[53] = "fiftythree";
    m[54] = "fiftyfour";
    m[55] = "fiftyfive";
    m[56] = "fiftysix";
    m[57] = "fiftyseven";
    m[58] = "fiftyeight";
    m[59] = "fiftynine";
    m[60] = "sixty";
    m[61] = "sixtyone";
    m[62] = "sixtytwo";
    m[63] = "sixtythree";
    m[64] = "sixtyfour";
    m[65] = "sixtyfive";
    m[66] = "sixtysix";
    m[67] = "sixtyseven";
    m[68] = "sixtyeight";
    m[69] = "sixtynine";
    m[70] = "seventy";
    m[71] = "seventyone";
    m[72] = "seventytwo";
    m[73] = "seventythree";
    m[74] = "seventyfour";
    m[75] = "seventyfive";
    m[76] = "seventysix";
    m[77] = "seventyseven";
    m[78] = "seventyeight";
    m[79] = "seventynine";
    m[80] = "eighty";
    m[81] = "eightyone";
    m[82] = "eightytwo";
    m[83] = "eightythree";
    m[84] = "eightyfour";
    m[85] = "eightyfive";
    m[86] = "eightysix";
    m[87] = "eightyseven";
    m[88] = "eightyeight";
    m[89] = "eightynine";
    m[90] = "ninety";
    m[91] = "ninetyone";
    m[92] = "ninetytwo";
    m[93] = "ninetythree";
    m[94] = "ninetyfour";
    m[95] = "ninetyfive";
    m[96] = "ninetysix";
    m[97] = "ninetyseven";
    m[98] = "ninetyeight";
    m[99] = "ninetynine";
    m[100] = "hundred";
    m[101] = "onehundredone";
    m[102] = "onehundredtwo";
    m[103] = "onehundredthree";
    m[104] = "onehundredfour";
    m[105] = "onehundredfive";
    m[106] = "onehundredsix";
    m[107] = "onehundredseven";
    m[108] = "onehundredeight";
    m[109] = "onehundrednine";
    m[110] = "onehundredten";
    m[111] = "onehundredeleven";
    m[112] = "onehundredtwelve";
    m[113] = "onehundredthirteen";
    m[114] = "onehundredfourteen";
    m[115] = "onehundredfifteen";
    m[116] = "onehundredsixteen";
    m[117] = "onehundredseventeen";
    m[118] = "onehundredeighteen";
    m[119] = "onehundrednineteen";
    m[120] = "onetwenty";
    m[121] = "onetwenty-one ";
    m[122] = "onetwenty-two";
    m[123] = "onetwenty-three ";
    m[124] = "onetwenty-four ";
    m[125] = "onetwenty-five";
    m[126] = "onetwenty-six";
    m[127] = "onetwenty-seven";
    m[128] = "onetwenty-eight";
    m[129] = "onetwenty-nine";
    m[130] = "onethirty";
    m[131] = "onethirtyone";
    m[132] = "onethirtytwo";
    m[133] = "onethirtythree";
    m[134] = "onethirtyfour";
    m[135] = "onethirtyfive";
    m[136] = "onethirtysix";
    m[137] = "onethirtyseven";
    m[138] = "onethirtyeight";
    m[139] = "onethirtynine";
    m[140] = "oneforty";
    m[141] = "onefortyone";
    m[142] = "onefortytwo";
    m[143] = "onefortythree";
    m[144] = "onefortyfour";
    m[145] = "onefortyfive";
    m[146] = "onefortysix";
    m[147] = "onefortyseven";
    m[148] = "onefortyeight";
    m[149] = "onefortynine";
    m[150] = "onefifty";
    m[151] = "onefiftyone";
    m[152] = "onefiftytwo";
    m[153] = "onefiftythree";
    m[154] = "onefiftyfour";
    m[155] = "onefiftyfive";
    m[156] = "onefiftysix";
    m[157] = "onefiftyseven";
    m[158] = "onefiftyeight";
    m[159] = "onefiftynine";
    m[160] = "onesixty";
    m[161] = "onesixtyone";
    m[162] = "onesixtytwo";
    m[163] = "onesixtythree";
    m[164] = "onesixtyfour";
    m[165] = "onesixtyfive";
    m[166] = "onesixtysix";
    m[167] = "onesixtyseven";
    m[168] = "onesixtyeight";
    m[169] = "onesixtynine";
    m[170] = "oneseventy";
    m[171] = "oneseventyone";
    m[172] = "oneseventytwo";
    m[173] = "oneseventythree";
    m[174] = "oneseventyfour";
    m[175] = "oneseventyfive";
    m[176] = "oneseventysix";
    m[177] = "oneseventyseven";
    m[178] = "oneseventyeight";
    m[179] = "oneseventynine";
    m[180] = "oneeighty";
    m[181] = "oneeightyone";
    m[182] = "oneeightytwo";
    m[183] = "oneeightythree";
    m[184] = "oneeightyfour";
    m[185] = "oneeightyfive";
    m[186] = "oneeightysix";
    m[187] = "oneeightyseven";
    m[188] = "oneeightyeight";
    m[189] = "oneeightynine";
    m[190] = "oneninety";
    m[191] = "oneninetyone";
    m[192] = "oneninetytwo";
    m[193] = "oneninetythree";
    m[194] = "oneninetyfour";
    m[195] = "oneninetyfive";
    m[196] = "oneoneninetysix";
    m[197] = "oneninetyseven";
    m[198] = "oneninetyeight";
    m[199] = "oneninetynine";
    m[200] = "twohundred";
    m[0] = "zero";

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int len = m[arr[i]].length();
        for (int j = 0; j < len; j++)
        {
            if (m[arr[i]][j] == 'a' || m[arr[i]][j] == 'e' || m[arr[i]][j] == 'i' || m[arr[i]][j] == 'o' || m[arr[i]][j] == 'u')
            {
                sum++;
            }
        }
    }

    map<pair<int, int>, bool> visited;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> p;
            p.first = (int)arr[i];
            p.second = (int)arr[j];
            if (arr[i] + arr[j] == sum && !visited[p])
            {
                visited[p] = true;
                count++;
            }
        }
    }

    cout << m[count];
}

int32_t main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
}