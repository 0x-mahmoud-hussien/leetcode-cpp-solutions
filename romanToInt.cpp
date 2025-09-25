
// https://leetcode.com/problems/roman-to-integer
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> values = 
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.size(); i++) 
        {
            int current = values[s[i]];
        
            int next = (i + 1 < s.size()) ? values[s[i + 1]] : 0;

            if (current < next) 
                result -= current;
            else 
                result += current;
        }
        return result;
    }
};


int main()
{
    Solution sol;
    cout << sol.romanToInt("III") << "\n";
    cout << sol.romanToInt("LVIII") << "\n"; 
    cout << sol.romanToInt("MCMXCIV") << "\n"; 
    return 0;
}