
// https://leetcode.com/problems/reverse-integer
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        int num = 0;
        while (x != 0) 
        {
            int digit = x % 10;

            if (num > INT_MAX/10 || (num == INT_MAX/10 && digit > 7)) return 0;
            if (num < INT_MIN/10 || (num == INT_MIN/10 && digit < -8)) return 0;

            num = num * 10 + digit;
            x /= 10;
        }
        return num;
    }
};

int main() 
{
    Solution sol;
    cout << sol.reverse(123) << endl; 
    cout << sol.reverse(-123) << endl;  
    cout << sol.reverse(120) << endl;   
    return 0;
}