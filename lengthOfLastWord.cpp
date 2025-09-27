
// https://leetcode.com/problems/length-of-last-word
#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    int lengthOfLastWord(const string& s) 
    {
        int i = (int)s.size() - 1; 

        while (i >= 0 && s[i] == ' ') 
        {
            i--;
        }

        int length = 0;
        while (i >= 0 && s[i] != ' ') 
        {
            length++;
            i--;
        }

        return length;
    }
};

int main() 
{
    Solution sol;
    string line;

    cout << "Enter a line: ";
    getline(cin, line);

    int result = sol.lengthOfLastWord(line);
    cout << "Length of last word = " << result << endl;

    return 0;
}