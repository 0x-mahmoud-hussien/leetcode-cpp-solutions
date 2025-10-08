
// https://leetcode.com/problems/shuffle-the-array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> result;
        result.reserve(nums.size()); 

        for (int i = 0; i < n; i++) 
        {
            result.push_back(nums[i]);     
            result.push_back(nums[i + n]);
        }

        return result;
    }
};

int main() 
{
    Solution s;

    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;

    vector<int> res = s.shuffle(nums, n);

    cout << "Result: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}