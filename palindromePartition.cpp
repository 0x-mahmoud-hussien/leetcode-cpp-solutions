
// https://leetcode.com/problems/palindrome-partitioning
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> result; 

    bool isPalindrome(string &s, int start, int end) 
    {
        while (start < end) 
        {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }


    void backtrack(string &s, int start, vector<string> &current) 
    {
        if (start == s.size()) 
        {
            result.push_back(current); 
            return;
        }

        for (int end = start; end < s.size(); end++) 
        {
            if (isPalindrome(s, start, end)) 
            {  
                string sub = s.substr(start, end - start + 1);
                current.push_back(sub);   
                backtrack(s, end + 1, current); 
                current.pop_back();       
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        vector<string> current;
        backtrack(s, 0, current);
        return result;
    }
};

int main() 
{
    Solution sol;
    string s = "aab";
    vector<vector<string>> ans = sol.partition(s);

    cout << "[ ";
    for (auto &vec : ans) 
    {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) 
        {
            cout << "\"" << vec[i] << "\"";
            if (i != vec.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << "]\n";

    return 0;
}
