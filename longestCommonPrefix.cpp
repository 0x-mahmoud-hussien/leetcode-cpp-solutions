
// https://leetcode.com/problems/longest-common-prefix
#include <iostream>
#include <vector>
using namespace std;

class LongestCommonPrefix 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) 
        {
            while (strs[i].find(prefix) != 0) 
            {
                prefix.pop_back();        
                if (prefix.empty()) return ""; 
            }
        }
        return prefix;
}
};

int main()
{
    LongestCommonPrefix longest;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longest.longestCommonPrefix(strs) << "\n";
    return 0;
}