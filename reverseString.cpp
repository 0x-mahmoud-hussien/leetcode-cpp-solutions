
// https://leetcode.com/problems/reverse-string
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        reverse(s.begin(), s.end()); 

        cout << "Reversed string: ";
        for (char c : s)
            cout << c;
        cout << endl;
    }

    void printReversed(vector<char>& s)
    {
        cout << "Printed in reverse: ";
        for (int i = s.size() - 1; i >= 0; i--)
            cout << s[i];
        cout << endl;
    }
};

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution obj;
    obj.printReversed(s); 
    obj.reverseString(s);

    return 0;
}