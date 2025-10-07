
// https://leetcode.com/problems/reverse-only-letters
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        string letters = "";
        for (char c : s)
        {
            if (isalpha(c))
                letters += c;
        }

        reverse(letters.begin(), letters.end());

        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                s[i] = letters[j];
                j++;
            }
        }
        
        return s;
    }
};

int main()
{
    Solution sol;
    string str = "Hello65, World123";

    cout << sol.reverseOnlyLetters(str);
    return 0;
}