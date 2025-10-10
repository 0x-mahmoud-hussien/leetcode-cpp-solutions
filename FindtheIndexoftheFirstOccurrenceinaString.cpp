
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int pos = haystack.find(needle); 
        return pos; 
    }
};

int main()
{
    Solution s;
    cout << s.strStr("sadbutsad", "sad") << endl;  
    cout << s.strStr("leetcode", "leeto") << endl;
}