
// https://leetcode.com/problems/palindrome-number
#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;
        
        int num = x;
        long long result = 0;
        while (num != 0)
        {
            int digit = num % 10; 
            result = result * 10 + digit; 
            num /= 10;  
        }
        
        return result == x;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.isPalindrome(121) << "\n"; 
    cout << sol.isPalindrome(-121) << "\n";
    cout << sol.isPalindrome(10) << "\n";
    return 0;
}