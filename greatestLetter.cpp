
// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) 
    {
        unordered_set<char> lower, upper;

        for (char c : s)
        {
            if (islower(c)) lower.insert(c);
            if (isupper(c)) upper.insert(c);
        }

        for (char ch = 'Z'; ch >= 'A'; ch--)
        {
            if (upper.count(ch) && lower.count(tolower(ch)))
                return string(1, ch);
        }

        return "";
    }
};

int main()
{
    Solution sol;
    cout << sol.greatestLetter("arRAzFif"); 
}