
// https://leetcode.com/problems/beautiful-array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) 
    {
        vector<int> result = {1}; 

        while (result.size() < n) 
        {
            vector<int> temp;
            
            for (int x : result)
                if (2 * x - 1 <= n)
                    temp.push_back(2 * x - 1);

            for (int x : result)
                if (2 * x <= n)
                    temp.push_back(2 * x);

            result = temp; 
        }

        return result;
    }
};

int main() 
{
    Solution solution;
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> ans = solution.beautifulArray(n);

    cout << "Beautiful Array: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}