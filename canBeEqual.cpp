
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays?envType=problem-list-v2&envId=array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) 
    {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] != arr[i])
                return false; 
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> target = {1,2,3,4};
    vector<int> arr = {2,4,1,3};

    if (sol.canBeEqual(target, arr))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}