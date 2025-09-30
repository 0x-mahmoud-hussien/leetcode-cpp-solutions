
// https://leetcode.com/problems/valid-palindrome
#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string result;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
                result += tolower(s[i]);
        }

        int left = 0, 
        right = result.length() - 1;

        while (left < right)
        {
            if (result[left] != result[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha; 

    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; 
    cout << sol.isPalindrome("race a car") << endl;                    
    cout << sol.isPalindrome(" ") << endl;              
}